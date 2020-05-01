/* Copyright (c) 2005 Miller Puckette.
* For information on usage and redistribution, and for a DISCLAIMER OF ALL
* WARRANTIES, see the file, "LICENSE.txt," in this distribution.  */

/* this is a variant on tabread4~, in which the array is viewed as a series of
wraparound tables. */

#include "m_pd.h"

static t_class *tabreadwrap4_tilde_class;

typedef struct _tabreadwrap4_tilde
{
    t_object x_obj;
    int x_npoints;              /* number of points in array */
    t_word *x_vec;               /* floating-point samples in array */
    t_symbol *x_arrayname;      /* name of array */
    float x_f;                  /* for signal inlet */
    int x_wrap;                 /* logical size of wraparound tables */
} t_tabreadwrap4_tilde;

void tabreadwrap4_tilde_wrap(t_tabreadwrap4_tilde *x, t_floatarg f)
{
    int n = f;
    if (n <= 0)
        n = 1024;
    if (n < 4)
        pd_error(x, "tabreadwrap4~: correcting to minimum size 4"), n = 4;
    if (n != (1 << ilog2(n)))
        pd_error(x, "tabreadwrap4~: correcting to power of 2 size"),
            n = ilog2(n);
    x->x_wrap = n;
}

static void *tabreadwrap4_tilde_new(t_symbol *s, t_floatarg f)
{
    t_tabreadwrap4_tilde *x = (t_tabreadwrap4_tilde *)
        pd_new(tabreadwrap4_tilde_class);
    inlet_new(&x->x_obj, &x->x_obj.ob_pd, &s_signal, &s_signal);
    inlet_new(&x->x_obj, &x->x_obj.ob_pd, &s_float, gensym("wrap"));
    outlet_new(&x->x_obj, gensym("signal"));
    x->x_arrayname = s;
    x->x_vec = 0;
    x->x_f = 0;
    tabreadwrap4_tilde_wrap(x, f);
    return (x);
}

#ifdef OPTIMIZE /* do this later... */
#define UNITBIT32 1572864.  /* 3*2^19; bit 32 has place value 1 */

#ifdef MSW
    /* little-endian; most significant byte is at highest address */
#define HIOFFSET 1
#define LOWOFFSET 0
#define int32 long
#endif /* MSW */

#ifdef __FreeBSD__
#include <machine/endian.h>
#endif

#if defined(__linux__) || defined(MACOSX)
#include <endian.h>
#endif

#ifdef __unix__
#if BYTE_ORDER == LITTLE_ENDIAN
#define HIOFFSET 1
#define LOWOFFSET 0
#else
#define HIOFFSET 0    /* word offset to find MSB */
#define LOWOFFSET 1    /* word offset to find LSB */
#endif /* BYTE_ORDER */
#include <sys/types.h>
#define int32 int32_t
#endif

#if !defined(HIOFFSET)                       
#error cannot determine machine byte order                                                   
#endif                                                                          
                                                                                
union tabfudge
{
    double tf_d;
    int32 tf_i[2];
};
#endif /* OPTIMIZE */

static t_int *tabreadwrap4_tilde_perform(t_int *w)
{
    t_tabreadwrap4_tilde *x = (t_tabreadwrap4_tilde *)(w[1]);
    t_float *in1 = (t_float *)(w[2]);
    t_float *in2 = (t_float *)(w[3]);
    t_float *out = (t_float *)(w[4]);
    int n = (int)(w[5]);   
    int wrap = x->x_wrap; 
    int npoints = x->x_npoints & (~(wrap-1));
    t_word *buf = x->x_vec, *wp1, *wp2;
    int i;
    int normhipart;
    int tablimit = ((int) (npoints / wrap)) * wrap;

    if (!buf)
    {
        while (n--)
            *out++ = 0;
        goto done;
    }
#ifdef OPTIMIZE
    tf.tf_d = UNITBIT32;
    normhipart = tf.tf_i[HIOFFSET];
    tf.tf_d = dphase;

    ...
#else
    for (i = 0; i < n; i++, out++)
    {
        float findex1 = *in1++;
        float findex2 = *in2++;
        double dfindex;
        int index1, index2, t;
        float frac1, frac2, a, b, c,  d, cminusb, *fp1, *fp2, fwrap = wrap;
        
        /* index1 is the wraparound index into table segments of
        size "wrap".  Only its fractional part matters; it is
        adjusted to the range 0-fwrap. */
        dfindex = 1024 + (double)findex1;
        findex1 = fwrap * (dfindex - (int)dfindex);
        
        /* the integer part gives index into table segment, and fractional part is
            is used for (4-point) interpolation */
        index1 = (int)findex1;
        findex1 -= index1;

        /* index2 selects a mixture between two consecutive chunks. */
        if (findex2 < 0)
            findex2 = 0;
        dfindex = (double)findex2;
        index2 = (int)dfindex;
        findex2 = dfindex - index2;
        index2 *= wrap;
        if (index2 >= tablimit)
        {
            *out = 0;
            continue;
        }        
        wp1 = buf + index2;
        index2 += wrap;
        if (index2 >= tablimit)
            index2 -= tablimit;
        wp2 = buf + index2;
        
        t = (index1-1)&(wrap-1);
        a = wp1[t].w_float + findex2 * (wp2[t].w_float - wp1[t].w_float);
        t = (index1)&(wrap-1);
        b = wp1[t].w_float + findex2 * (wp2[t].w_float - wp1[t].w_float);
        t = (index1+1)&(wrap-1);
        c = wp1[t].w_float + findex2 * (wp2[t].w_float - wp1[t].w_float);
        t = (index1+2)&(wrap-1);
        d = wp1[t].w_float + findex2 * (wp2[t].w_float - wp1[t].w_float);

        cminusb = c-b;
        *out = b + findex1 * (
            cminusb - 0.1666667f * (1.-findex1) * (
                (d - a - 3.0f * cminusb) * findex1 + (d + 2.0f*a - 3.0f*b)
            )
        );
    }
#endif /* OPTIMIZE */
done:
    return (w+6);
}

void tabreadwrap4_tilde_set(t_tabreadwrap4_tilde *x, t_symbol *s)
{
    t_garray *a;
    
    x->x_arrayname = s;
    if (!(a = (t_garray *)pd_findbyclass(x->x_arrayname, garray_class)))
    {
        if (*s->s_name)
            pd_error(x, "tabreadwrap4~: %s: no such array", x->x_arrayname->s_name);
        x->x_vec = 0;
    }
    else if (!garray_getfloatwords(a, &x->x_npoints, &x->x_vec))
    {
        pd_error(x, "%s: bad template for tabreadwrap4~", x->x_arrayname->s_name);
        x->x_vec = 0;
    }
    else garray_usedindsp(a);
}

static void tabreadwrap4_tilde_dsp(t_tabreadwrap4_tilde *x, t_signal **sp)
{
    tabreadwrap4_tilde_set(x, x->x_arrayname);

    dsp_add(tabreadwrap4_tilde_perform, 5, x,
        sp[0]->s_vec, sp[1]->s_vec, sp[2]->s_vec, sp[0]->s_n);

}

void tabreadwrap4_tilde_setup(void)
{
    tabreadwrap4_tilde_class = class_new(gensym("tabreadwrap4~"),
        (t_newmethod)tabreadwrap4_tilde_new, 0,
        sizeof(t_tabreadwrap4_tilde), 0, A_DEFSYM, A_DEFFLOAT, 0);
    CLASS_MAINSIGNALIN(tabreadwrap4_tilde_class, t_tabreadwrap4_tilde, x_f);
    class_addmethod(tabreadwrap4_tilde_class, (t_method)tabreadwrap4_tilde_dsp,
        gensym("dsp"), 0);
    class_addmethod(tabreadwrap4_tilde_class, (t_method)tabreadwrap4_tilde_set,
        gensym("set"), A_SYMBOL, 0);
    class_addmethod(tabreadwrap4_tilde_class, (t_method)tabreadwrap4_tilde_wrap,
        gensym("wrap"), A_FLOAT, 0);
}
