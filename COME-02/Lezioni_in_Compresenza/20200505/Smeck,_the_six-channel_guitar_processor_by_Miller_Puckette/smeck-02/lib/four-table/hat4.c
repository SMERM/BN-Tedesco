/* copyright 2000 Miller Puckette.  You may use this code for any purpose
provided you keep this copyright notice intact.  The author makes no warranty
related to this program. */

/* this program tries to generate four 4096-point tables, the sum of whose
squares is nearly constant, and whose spectra are each "hat functions" with
512 partials. */

#include "stdio.h"
#include "math.h"
#define NPOINTS 4096

#define TEST 4096
#define NS 512

float amp[NS];
float pha1[NS], pha2[NS], pha3[NS], pha4[NS];

#define SS 65536
double cosines[SS];

double fbuf1[NPOINTS], fbuf2[NPOINTS], fbuf3[NPOINTS], fbuf4[NPOINTS];
float grain;
float bestone = 100000;
float minimprove = 0.001;
int minstrat;
/* #define HANNING */

float badness(int size)
{
    double min = 1e20, max = -1, mean = 0, meansq = 0, rval,
    	meaninv = 0, meaninvsq = 0, meancubed = 0, meaninvcubed = 0,
	mean4 = 0, meani4 = 0;
    double average;
    int i;
    for (i = 0, average = 0; i < size; i++)
	average += fbuf1[i] * fbuf1[i] + fbuf2[i] * fbuf2[i]
            + fbuf3[i] * fbuf3[i] + fbuf4[i] * fbuf4[i];
    average *= (1. / size);
    for (i = 0; i < size; i++)
    {
    	double val = fbuf1[i] * fbuf1[i] + fbuf2[i] * fbuf2[i]
	    + fbuf3[i] * fbuf3[i] + fbuf4[i] * fbuf4[i] ;
	double oops = val - average;
	if (val < min)
	    min = val;
	if (val > max) 
	    max = val;
	meansq += oops * oops;
	mean4 += oops * oops * oops * oops;
    }

    meansq = sqrt(meansq/size);
    mean4  = sqrt(sqrt(mean4/size));

    if (minstrat == 1)
    	rval = mean4;
    else rval = meansq;
    return (rval);
}

void badness2(int size)
{
    float min = 1e20, max = -1, mean = 0, meansq = 0;
    int i;
    for (i = 0; i < size; i++)
    {
    	float val = fbuf1[i] * fbuf1[i] + fbuf2[i] * fbuf2[i]
	    + fbuf3[i] * fbuf3[i] + fbuf4[i] * fbuf4[i] ;
	if (val < min)
	    min = val;
	if (val > max) 
	    max = val;
    	mean += val;
	meansq += val * val;
    }
    /* fprintf(stderr, "- %f\n", m); */
    mean *= (1./size);
    meansq *= (1./size);
    fprintf(stderr, "\nmin %f, max %f range %f dB\n", min, max,
    	20 * log(min <= 0 ? 1e20 : max/min)/log(10.)); 
}

float build(int size, float *pha, double *fbuf)
{
    int i, j;
    float norm = (1./size);
    for (i = 0; i < size; i++)
    {
	float foo = 0;
	for (j = 0; j < NS; j++)
	    foo += amp[j] * 
	    	cosines[(int)(SS * ((j+1)*i*norm + pha[j])) & (SS-1)];
	fbuf[i] = foo;
    }
    return (badness(size));
}


void addon(int size, int npartial, float sign, float *pha, double *fbuf)
{
    int i;
    float norm = (1./size);
    for (i = 0; i < size; i++)
	fbuf[i] += sign * amp[npartial] *
	    cosines[(int)(SS * ((npartial+1)*i*norm + pha[npartial])) & (SS-1)];

}

int optimizefor(float *pha, double *fbuf, int i)
{
    float was = pha[i], tmp;

    addon(TEST, i, -1, pha, fbuf);
    pha[i] = was + grain;
    addon(TEST, i, 1, pha, fbuf);
    if ((tmp = badness(TEST)) < bestone - minimprove)
    {
	bestone = tmp;
	fprintf(stderr, "%7.6f ", bestone);
	return (1);
    }
    addon(TEST, i, -1, pha, fbuf);
    pha[i] = was - grain;
    addon(TEST, i, 1, pha, fbuf);
    if ((tmp = badness(TEST)) < bestone - minimprove)
    {
	bestone = tmp;
	fprintf(stderr, "%7.6f ", bestone);
	fflush(stderr);
	return (1);
    }
    addon(TEST, i, -1, pha, fbuf);
    pha[i] = was;
    addon(TEST, i, 1, pha, fbuf);
    return (0);
}

void optimize( void)
{
    int i = 1, nochange = 0, howmany = 0;
    fprintf(stderr, "------grain %f, minimprove %f minstrat %d -------\n",
    	grain, minimprove, minstrat);
    while (1)
    {
	float was, tmp;
	
	if (howmany <= 0)
	{
	    build(TEST, pha1, fbuf1);
	    build(TEST, pha2, fbuf2);
	    build(TEST, pha3, fbuf3);
	    build(TEST, pha4, fbuf4);
	    
	    badness2(TEST);
	    howmany = 100;
	}
    	howmany--;
#if 0
    	if (optimizefor(pha1, fbuf1, i))
	{
	    nochange = 0;
	    continue;
    	}
    	if (optimizefor(pha2, fbuf2, i))
	{
	    nochange = 0;
	    continue;
    	}

    	if (optimizefor(pha3, fbuf3, i))
	{
	    nochange = 0;
	    continue;
    	}

    	if (optimizefor(pha4, fbuf4, i))
	{
	    nochange = 0;
	    continue;
    	}
#else
    	while (optimizefor(pha1, fbuf1, i))
	    nochange = 0;
    	while (optimizefor(pha2, fbuf2, i))
	    nochange = 0;
    	while (optimizefor(pha3, fbuf3, i))
	    nochange = 0;
    	while (optimizefor(pha4, fbuf4, i))
	    nochange = 0;
#endif
	if ((++nochange) == NS) break;
	i ++;
	i %= NS;
	if (!i) i = 1;
    }
}


main(argc, argv)
 char **argv;
{
    int i = 0, sfd;
    char *name;
    short buf[NPOINTS];
    int j;
    float sumsq, norm;
    
    amp[0] = 0.5;
    pha1[0] = pha2[0] = pha3[0] = pha4[0] = 0;
    for (j = 1; j < NS; j++)
    {
	pha1[j] = ((123 * j * j + 5213*j)%700)/700.;
	pha2[j] = ((457 * j * j + 3769*j)%700)/700.;
	pha3[j] = ((311 * j * j + 4867*j)%700)/700.;
	pha4[j] = ((423 * j * j + 8343*j)%700)/700.;
#ifdef HANNING
	amp[j] = 0.5 * (1 + cos(3.14159*j / (float)NS));
#else
#ifdef HALFSINE
	amp[j] = cos(3.14159*0.5*j / (float)NS);
#else
	amp[j] = (NS - j) / (float)NS;
#endif
#endif
    }
    for (j = 0; j < SS; j++)
	cosines[j] = cos((2*3.14159/SS)*j);

    minstrat = 1;	
    minimprove = 0.01;
    grain = 0.25;
    optimize();
    minimprove = 0.001;
    grain = 0.4;
    optimize();
    minimprove = 0.01;
    grain = 0.25;
    optimize();
    minimprove = 0.01;
    grain = 0.01;	
    optimize();
    minimprove = 0.001;
    grain = 0.001;	
    optimize();
    minimprove = 0.0001;
    grain = 0.001;	
    optimize();

    build(NPOINTS, pha1, fbuf1);
    build(NPOINTS, pha2, fbuf2);
    build(NPOINTS, pha3, fbuf3);
    build(NPOINTS, pha4, fbuf4);
    fprintf(stderr, "badness %f\n", badness(NPOINTS));
    badness2(NPOINTS);

    for (i = 0, sumsq = 0; i < NPOINTS; i++)
    	sumsq += fbuf1[i]*fbuf1[i] + fbuf2[i]*fbuf2[i] +
	    fbuf3[i]*fbuf3[i] + fbuf4[i]*fbuf4[i];
    norm = sqrt(NPOINTS / sumsq);
    for (i = 0; i < NPOINTS; i++) 
	printf("%f\t%f\t%f\t%f\n", norm * fbuf1[i], 
	    norm * fbuf2[i], norm * fbuf3[i], norm * fbuf4[i]);

    exit(0);
}

