/* conform -- output a continuous delay in frames to conform
second argument of a list to first argument. */

/*  Copyright 2004 Miller Puckette.
Permission is granted to use this software for any purpose provided you
keep this copyright notice intact.

THE AUTHOR AND HIS EMPLOYERS MAKE NO WARRANTY, EXPRESS OR IMPLIED,
IN CONNECTION WITH THIS SOFTWARE.
 
This file may someday be downloadable from http://www.crca.ucsd.edu/~msp .
*/

#include "m_pd.h"
#include <math.h>
#include <stdio.h>

#define HISTORY 250

#define STATE_OFF   0
#define STATE_RISE  1
#define STATE_ON    2
#define STATE_FALL  3

#define ACTION_NORMAL 0
#define ACTION_FAST 1
#define ACTION_SLOW 2

/* assume 11 msec frames */
#define DEFAULT_NULLDEL      50
#define DEFAULT_MAXDEL      100

#define DEFAULT_THRESH  40
#define DEFAULT_DEBOUNCELEVELDIFF 5
#define DEFAULT_ONFRAMESMIN 5
#define DEFAULT_ONRISELEVELMAX 5
#define DEFAULT_FALLFRAMESMIN 10
#define DEFAULT_FALLLEVELMIN 5
#define DEFAULT_FALLTORISEFRAMESMIN 10
#define DEFAULT_FALLTORISETHRESH 7

typedef struct _conform
{
    t_object x_obj;
    float x_from[HISTORY];
    float x_to[HISTORY];
    int x_fromstate[HISTORY];
    int x_tostate;
    int x_phase;
    float x_lastoutdelay;
    int x_action;
    int x_debug;
    	/* parameters */
    float x_nulldel;
    float x_maxdel;

    float x_from_thresh;    	    	/* on/off threshold */
    float x_from_debounceleveldiff; 	/* DB above thresh to turn on */
    float x_from_onframesmin;	    	/* period of steady-state test */
    float x_from_onriselevelmax;    	/* max level rise for steady state */
    float x_from_fallframesmin;	    	/* period of decay test */
    float x_from_falllevelmin;	    	/* level fall sufficient for decay */
    float x_from_falltoriseframesmin;	/* period of fall-to-rise */
    float x_from_falltorisethresh;  	/* DB rise needed for fall-to-rise */

    float x_to_thresh;
    float x_to_debounceleveldiff;
    float x_to_onframesmin;
    float x_to_onriselevelmax;
    float x_to_fallframesmin;
    float x_to_falllevelmin;
    float x_to_falltoriseframesmin;
    float x_to_falltorisethresh;
} t_conform;

#define PHASEWAS(x, n) \
  ((x)->x_phase - (n) < 0 ? (x)->x_phase - (n) + HISTORY : (x)->x_phase - (n))

#define TOWAS(x, n) ((x)->x_to[PHASEWAS((x), (n))])
#define FROMWAS(x, n) ((x)->x_from[PHASEWAS((x), (n))])
#define FROMSTATEWAS(x, n) ((x)->x_fromstate[PHASEWAS((x), (n))])

#define THRESH(x, y) ((y)?(x)->x_to_thresh:(x)->x_from_thresh)
#define DEBOUNCELEVELDIFF(x, y) ((y)?(x)->x_to_debounceleveldiff:\
    (x)->x_from_debounceleveldiff)
#define ONFRAMESMIN(x, y) ((y)?(x)->x_to_onframesmin:\
    (x)->x_from_onframesmin)
#define ONRISELEVELMAX(x, y) ((y)?(x)->x_to_onriselevelmax:\
    (x)->x_from_onriselevelmax)
#define FALLFRAMESMIN(x, y) ((y)?(x)->x_to_fallframesmin:\
    (x)->x_from_fallframesmin)
#define FALLLEVELMIN(x, y) ((y)?(x)->x_to_falllevelmin:\
    (x)->x_from_falllevelmin)
#define FALLTORISEFRAMESMIN(x, y) ((y)?(x)->x_to_falltoriseframesmin:\
    (x)->x_from_falltoriseframesmin)
#define FALLTORISETHRESH(x, y) ((y)?(x)->x_to_falltorisethresh:\
    (x)->x_from_falltorisethresh)

static t_class *conform_class;

static void conform_default(t_conform *x);
static void *conform_new(t_float fnonrepeat)
{
    t_conform *x = (t_conform *)pd_new(conform_class);
    int i;
    outlet_new(&x->x_obj, gensym("float"));
    for (i = 0; i < HISTORY; i++)
    	x->x_from[i] = x->x_to[i] = 0, x->x_fromstate[i] = STATE_OFF;
    x->x_phase = 0;
    x->x_tostate = STATE_OFF;

    conform_default(x);

    x->x_nulldel = DEFAULT_NULLDEL;
    x->x_maxdel = DEFAULT_MAXDEL;
    x->x_action = ACTION_NORMAL;
    x->x_lastoutdelay = DEFAULT_NULLDEL;
    x->x_debug = 0;
    return (x);
}

static void conform_from_thresh(t_conform *x, t_floatarg f)
{
    x->x_from_thresh = f;
}

static void conform_to_thresh(t_conform *x, t_floatarg f)
{
    x->x_to_thresh = f;
}

static void conform_print(t_conform *x)
{
    int i;
    post("tostate %d", x->x_tostate);
    for (i = 9; i >= 0; i--)
    	post("from %3d (state %d) to %3d", (int)FROMWAS(x, i), 
	    x->x_fromstate[PHASEWAS(x, i)], (int)TOWAS(x, i));
}

    /* find new state from old one.  If 'useto' is true, we're finding
    the new state of the 'to' signal, otherwise the 'from' one. */
static int conform_newstate(t_conform *x, int useto)
{
    int statewas = (useto ? x->x_tostate : FROMSTATEWAS(x, 1));
    float thresh = (useto ? x->x_to_thresh : x->x_from_thresh);
    float *history = (useto ? x->x_to : x->x_from);
    float newlevel = history[x->x_phase];
    int newstate = statewas;
    int i;

    	/* test for state change. */
    switch (statewas)
    {
    case STATE_OFF:
    	if (newlevel >= thresh + DEBOUNCELEVELDIFF(x, useto))
	{
	    newstate = STATE_RISE;
	    if ((x->x_debug == 1) && !useto
	    	|| (x->x_debug == 2) && useto)
	    	    post("rise 1");
	}
	break;
    case STATE_RISE:
    	for (i = 1; i < ONFRAMESMIN(x, useto); i++)
	    if (newlevel >= history[PHASEWAS(x, i)] + ONRISELEVELMAX(x, useto))
	    	goto nonewstate;
	    newstate = STATE_ON;
	break;
    case STATE_ON:
	    if (newlevel < thresh + DEBOUNCELEVELDIFF(x, useto))
	    	newstate = STATE_FALL;
    	    for (i = 1; i < FALLFRAMESMIN(x, useto); i++)
	    	if (newlevel < history[PHASEWAS(x, i)] - FALLLEVELMIN(x, useto))
	    	    newstate = STATE_FALL;
	break;
    case STATE_FALL:
    	    if (newlevel < thresh)
	    	newstate = STATE_OFF;
	    else for (i = 0; i < FALLTORISEFRAMESMIN(x, useto); i++)
	    {
	    	if (history[PHASEWAS(x, i)] > newlevel)
		    break;
		else if (history[PHASEWAS(x, i)] <
		    newlevel - FALLTORISETHRESH(x, useto))
		{
		    newstate = STATE_RISE;
	    	    if ((x->x_debug == 1) && !useto
	    	    	|| (x->x_debug == 2) && useto)
		    	    post("rise 2");
		    break;
		}
	    }
	break;
    }
nonewstate: ;
    return (newstate);
}

static int conform_canfind(t_conform *x, int tostate)
{
    int i;
    if (x->x_lastoutdelay > x->x_nulldel)
    	return (1);
    for (i = 0; i < x->x_lastoutdelay; i++)
    	if (FROMSTATEWAS(x, i) == tostate)
	    return (1);
    return (0);
}

static void conform_list(t_conform *x, t_symbol *s, int argc, t_atom *argv)
{
    float newfrom = atom_getfloatarg(0, argc, argv);
    float newto = atom_getfloatarg(1, argc, argv);
    float newdelay = 0;
    int lasttostate, tostate, i;

    x->x_phase = (x->x_phase + 1 >= HISTORY ? 0 : x->x_phase + 1);
    lasttostate = x->x_tostate;

    FROMWAS(x, 0) = newfrom;
    TOWAS(x, 0) = newto;
    
    tostate = x->x_tostate = conform_newstate(x, 1);
    x->x_fromstate[x->x_phase] = conform_newstate(x, 0);
        
    if (tostate == STATE_OFF)
    {
    	if ((int)(x->x_lastoutdelay) > x->x_nulldel)
	    newdelay = x->x_lastoutdelay-1;
    	else if ((int)(x->x_lastoutdelay) < x->x_nulldel)
	    newdelay = x->x_lastoutdelay+1;
	else newdelay = x->x_nulldel;
	x->x_action = ACTION_NORMAL;
    }
    else
    {
	if (x->x_action == ACTION_NORMAL)
	{
	    int fromstate = FROMSTATEWAS(x, (int)(x->x_lastoutdelay));
	    newdelay = -1;
    	    if (tostate != fromstate &&
		tostate != lasttostate && x->x_lastoutdelay >= 1
		    && conform_canfind(x, tostate))
	    		x->x_action = ACTION_FAST;
	    else if (tostate != fromstate &&
		fromstate != FROMSTATEWAS(x, (int)(x->x_lastoutdelay)+1)
	    	    && x->x_lastoutdelay < x->x_maxdel-1)
	    		x->x_action = ACTION_SLOW;
    	    else
	    {
	    	    /* normal speed.  Check if we're getting short of
		    available history that matches the state; if so, slow
		    down progressively */
		int nequal;
		for (nequal = 0; nequal <= (int)(x->x_lastoutdelay); nequal++)
		{
		    if (FROMSTATEWAS(x, (int)(x->x_lastoutdelay - nequal))
		    	!= tostate)
		    	    break;
		}
		if (nequal == 0 || nequal > 10)
		     newdelay = x->x_lastoutdelay;
		else newdelay = x->x_lastoutdelay + 0.1*(10-nequal);
                if (newdelay > x->x_maxdel-1)
	    	    newdelay = x->x_maxdel-1;
	    }
	}
    	if (x->x_action == ACTION_FAST)
	{
	    if (!conform_canfind(x, tostate))
	    	x->x_action = ACTION_NORMAL;
	    else for (i = 0, newdelay = x->x_lastoutdelay; i < 10; i++,
	    	newdelay = newdelay-1)
	    {
	    	if (newdelay < 0)
	     	    break;
	    	if (FROMSTATEWAS(x, (int)newdelay) == tostate)
		{
		    x->x_action = ACTION_NORMAL;
		    break;
		}
	    }
	    if (newdelay < 0)
		newdelay = 0;
	}
	else if (x->x_action == ACTION_SLOW)
	{
	    newdelay = x->x_lastoutdelay + 1;
    	    if (tostate == FROMSTATEWAS(x, (int)newdelay))
		x->x_action = ACTION_NORMAL;
	    if (newdelay > x->x_maxdel-1)
	    	x->x_action = ACTION_FAST;
	}
    }
    if (newdelay < 0)
    {
    	bug("conform: negative delay?");
	newdelay = 0;
    }
#if 0
    if (newdelay < x->x_lastoutdelay - 1 || newdelay > x->x_lastoutdelay + 1)
    	post("delay change %f, action %d, to %d, from %d",
	    newdelay - x->x_lastoutdelay, x->x_action, tostate,
	    	(int)FROMSTATEWAS(x, (int)(x->x_lastoutdelay)));
#endif
    if (x->x_debug == 3)
    	post("del %d, action %d, to %d, from %d, fromwas %d %d",
    	    (int)newdelay, x->x_action, tostate, (int)FROMSTATEWAS(x, 0), 
	    	FROMSTATEWAS(x, (int)newdelay), (int)FROMWAS(x, (int)newdelay));
    {
    	t_atom outs[3];
	SETFLOAT(outs, newdelay);
	SETFLOAT(outs+1, FROMSTATEWAS(x, (int)newdelay));
	SETFLOAT(outs+2, tostate);
    	outlet_list(x->x_obj.ob_outlet, 0, 3, outs);
    }
    x->x_lastoutdelay = newdelay;
}

static void conform_default(t_conform *x)
{
    x->x_from_thresh =              DEFAULT_THRESH;
    x->x_from_debounceleveldiff =   DEFAULT_DEBOUNCELEVELDIFF; 
    x->x_from_onframesmin =         DEFAULT_ONFRAMESMIN;         
    x->x_from_onriselevelmax =      DEFAULT_ONRISELEVELMAX;      
    x->x_from_fallframesmin =       DEFAULT_FALLFRAMESMIN;       
    x->x_from_falllevelmin =        DEFAULT_FALLLEVELMIN;        
    x->x_from_falltoriseframesmin = DEFAULT_FALLTORISEFRAMESMIN;    
    x->x_from_falltorisethresh =    DEFAULT_FALLTORISETHRESH;    
    x->x_from_debounceleveldiff =   DEFAULT_DEBOUNCELEVELDIFF;	
    
    x->x_to_thresh =                DEFAULT_THRESH;
    x->x_to_debounceleveldiff =     DEFAULT_DEBOUNCELEVELDIFF; 
    x->x_to_onframesmin =     	    DEFAULT_ONFRAMESMIN;
    x->x_to_onriselevelmax =  	    DEFAULT_ONRISELEVELMAX;
    x->x_to_fallframesmin =   	    DEFAULT_FALLFRAMESMIN;
    x->x_to_falllevelmin =    	    DEFAULT_FALLLEVELMIN;
    x->x_to_falltoriseframesmin =   DEFAULT_FALLTORISEFRAMESMIN;  
    x->x_to_falltorisethresh =      DEFAULT_FALLTORISETHRESH;	 
    x->x_to_debounceleveldiff =     DEFAULT_DEBOUNCELEVELDIFF;    
}

static void conform_fromparams(t_conform *x, t_symbol *s,
    int argc, t_atom *argv)
{
    x->x_from_thresh =              atom_getfloatarg(0, argc, argv);
    x->x_from_debounceleveldiff =   atom_getfloatarg(1, argc, argv);
    x->x_from_onframesmin =         atom_getfloatarg(2, argc, argv);
    x->x_from_onriselevelmax =      atom_getfloatarg(3, argc, argv);
    x->x_from_fallframesmin =       atom_getfloatarg(4, argc, argv);
    x->x_from_falllevelmin =        atom_getfloatarg(5, argc, argv);
    x->x_from_falltoriseframesmin = atom_getfloatarg(6, argc, argv);
    x->x_from_falltorisethresh =    atom_getfloatarg(7, argc, argv);
    x->x_from_debounceleveldiff =   atom_getfloatarg(8, argc, argv);
}
    
static void conform_toparams(t_conform *x, t_symbol *s,
    int argc, t_atom *argv)
{
    x->x_to_thresh =                atom_getfloatarg(0, argc, argv);
    x->x_to_debounceleveldiff =     atom_getfloatarg(1, argc, argv);
    x->x_to_onframesmin =     	    atom_getfloatarg(2, argc, argv);
    x->x_to_onriselevelmax =  	    atom_getfloatarg(3, argc, argv);
    x->x_to_fallframesmin =   	    atom_getfloatarg(4, argc, argv);
    x->x_to_falllevelmin =    	    atom_getfloatarg(5, argc, argv);
    x->x_to_falltoriseframesmin =   atom_getfloatarg(6, argc, argv);
    x->x_to_falltorisethresh =      atom_getfloatarg(7, argc, argv);
    x->x_to_debounceleveldiff =     atom_getfloatarg(8, argc, argv);
}

static void conform_debug(t_conform *x, t_floatarg f)
{
    x->x_debug = f;
}

void conform_setup(void)
{
    conform_class = class_new(gensym("conform"), (t_newmethod)conform_new,
    	0, sizeof(t_conform), 0, A_DEFFLOAT, 0);
    class_addmethod(conform_class, (t_method)conform_from_thresh,
    	gensym("from_threshold"), A_FLOAT, 0);
    class_addmethod(conform_class, (t_method)conform_to_thresh,
    	gensym("to_threshold"), A_FLOAT, 0);
    class_addmethod(conform_class, (t_method)conform_print, gensym("print"), 0);
    class_addmethod(conform_class, (t_method)conform_default,
    	gensym("default"), 0);
    class_addmethod(conform_class, (t_method)conform_fromparams,
    	gensym("fromparams"), A_GIMME, 0);
    class_addmethod(conform_class, (t_method)conform_toparams,
    	gensym("toparams"), A_GIMME, 0);
    class_addmethod(conform_class, (t_method)conform_debug,
    	gensym("debug"), A_DEFFLOAT, 0);
    class_addlist(conform_class, conform_list);
}
