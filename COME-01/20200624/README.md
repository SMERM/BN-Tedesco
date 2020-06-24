# Appunti della lezione di Mercoledí 24 Giugno 2020

Concerto abbinato a una prima presentazione di SEAM

PD versione 0.51 calcolo 64 bit double

in Filtergraph~ di Max -> analog filter prototype -> quando si imposta analog, il biquad non fa il notch a Nyquist

lores ha frequenza di taglio e q, che

Scala esponenziale su response per avere controllo su bassi numeri di response, per avere numeri piccoli.

Togliere noise e lasciare il filtro in maniera sinusoidale

aumentare di response deve diminuire _no.noise_

```
/*BIQUAD FILTER*/
/* y[n]=b0x[n]+b1x[n−1]+b2x[n−2]−a1y[n−1]−a2y[n−2]
Note that a and b parameters are inverted */
import("stdfaust.lib");
biquad(a0c,a1c,a2c,b1c,b2c) =  a(a0c,a1c,a2c) : ma.sub~(b(b1c,b2c))
with{
    a0(a0c) = *(a0c);
    a1(a1c) = @(1) : *(a1c);
    a2(a2c) = @(2) : *(a2c);
    b1(b1c) = *(b1c);
    b2(b2c) = @(1) : *(b2c);
    //Blocco FIR
    a(a0c,a1c,a2c) = _ <: a0(a0c),a1(a1c),a2(a2c) :> _ ;
    //Blocco IIR
    b(b1c, b2c) = _ <:  b1(b1c), b2(b2c):> _;
};
//Coefficenti Max
//a = a0(0.9), a1(0.1), a2(0.1);
//b = b1(0.2), b2(0.2);
// Pitch tracker
a = hslider("n cycles", 1, 1, 100, 1);
upt(a,x) = a*ma.SR / max(M,1) - a * ma.SR * (M == 0)
with{
    // positive zero crossing
    xcr = (x' < 0) & (x >= 0);
    // counts of crossing
    xcnt = +(xcr)~ %(int(a));
    // windows of counts
    wnd = xcr & (xcnt == a);
    // counting samples inside windows
    N = (+(1) : *(1 - wnd)) ~ _;
    // sample and hold the number of cycles
    M = ba.sAndH(N == 0, N' + 1);
};
ptrack(a) = fi.dcblockerat(80) : (fi.lowpass(1) : upt(a)) ~ max(100);

//filtro oscillante Pellecchia
osco = os.impulse : biquad(1,0,0,-1.95128373,1)*0.1;

//filtro low pass
lores(fc,q) = biquad(a0c,a1c,a2c,b1c,b2c)
with{
    twopi = 2*ma.PI;
    //punto in radianti in cui si trova il polo sullo z-plane
    omega = fc*(twopi/ma.SR);
    //
    sn = sin(omega);
    cs = cos(omega);
    //
    alfa = sn*0.5/q;
    //calcolo coefficenti
    a0c = alfa*q*b0c;
    a1c = 0;
    a2c = -alfa*q*b0c;
    b0c = 1/(1+alfa);//coefficente intermedio, fattore scalare
    b1c = (-2*cs)*b0c;
    b2c = (1-alfa)*b0c;
};
freq = hslider("Freq", 1000,1,10000,0.1) : si.smoo;
response = hslider("Response[scale:exp]", 1,1,20000,1) : si.smoo;
norm = _ <: 0.5/an.rms_envelope_tau(0.2)*_ ;
//process =  osco <: _,(ptrack(30) : hbargraph("[01]freq[style:numerical]", 1000, 5000)) : _,*(0;

process = no.noise*(1-(response/20000)) : lores(freq,response) : norm;
```

nuovo filtro oscillante

```
/*BIQUAD FILTER*/
/* y[n]=b0x[n]+b1x[n−1]+b2x[n−2]−a1y[n−1]−a2y[n−2]
Note that a and b parameters are inverted */
import("stdfaust.lib");
biquad(a0c,a1c,a2c,b1c,b2c) =  a(a0c,a1c,a2c) : ma.sub~(b(b1c,b2c))
with{
    a0(a0c) = *(a0c);
    a1(a1c) = @(1) : *(a1c);
    a2(a2c) = @(2) : *(a2c);
    b1(b1c) = *(b1c);
    b2(b2c) = @(1) : *(b2c);
    //Blocco FIR
    a(a0c,a1c,a2c) = _ <: a0(a0c),a1(a1c),a2(a2c) :> _ ;
    //Blocco IIR
    b(b1c, b2c) = _ <:  b1(b1c), b2(b2c):> _;
};
//Coefficenti Max
//a = a0(0.9), a1(0.1), a2(0.1);
//b = b1(0.2), b2(0.2);
// Pitch tracker
a = hslider("n cycles", 1, 1, 100, 1);
upt(a,x) = a*ma.SR / max(M,1) - a * ma.SR * (M == 0)
with{
    // positive zero crossing
    xcr = (x' < 0) & (x >= 0);
    // counts of crossing
    xcnt = +(xcr)~ %(int(a));
    // windows of counts
    wnd = xcr & (xcnt == a);
    // counting samples inside windows
    N = (+(1) : *(1 - wnd)) ~ _;
    // sample and hold the number of cycles
    M = ba.sAndH(N == 0, N' + 1);
};
ptrack(a) = fi.dcblockerat(80) : (fi.lowpass(1) : upt(a)) ~ max(100);

//filtro oscillante Pellecchia
osco = os.impulse : biquad(1,0,0,-1.95128373,1)*0.1;
//process =  osco <: _,(ptrack(30) : hbargraph("[01]freq[style:numerical]", 1000, 5000)) : _,*(0;

//filtro low pass
lores(fc,q) = biquad(a0c,a1c,a2c,b1c,b2c)
with{
    twopi = 2*ma.PI;
    //punto in radianti in cui si trova il polo sullo z-plane
    omega = fc*(twopi/ma.SR);
    //
    sn = sin(omega);
    cs = cos(omega);
    //
    alfa = sn*0.5/q;
    //calcolo coefficenti
    a0c = alfa*q*b0c;
    a1c = 0;
    a2c = -alfa*q*b0c;
    b0c = 1/(1+alfa);//coefficente intermedio, fattore scalare
    b1c = (-2*cs)*b0c;
    b2c = (1-alfa)*b0c;
};
freq = hslider("Freq", 1000,1,10000,0.1) : si.smoo;
response = hslider("Response[scale:exp]", 1,1,20000,1) : si.smoo;
norm = _ <: 0.5/an.rms_envelope_tau(0.2)*_ ;

//process = no.noise*(1-(response/20000)) : lores(freq,response) : norm;

// =====================================================
// Cool Sounding Lowpass With Decibel Measured Resonance
// https://www.musicdsp.org/en/latest/Filters/180-cool-sounding-lowpass-with-decibel-measured-resonance.html

csrldb(fc,r) = biquad(a0c,a1c,a2c,b1c,b2c)
with{
    c = 1 / (tan(ma.PI * (fc / ma.SR)));
    csq = c * c;
    resonance = pow(10, (-r * 0.5));
    q = sqrt(2) * resonance;
    a0c = 1 / (1+ (q * c) + (csq));
    a1c = 2 * a0c;
    a2c = a0c;
    b1c = (2 * a0c) * (1 - csq);
    b2c = a0c * (1 - (q* c) + csq);
};

responsedb = hslider("Response[scale:exp]", 1,1,240,1) : si.smoo;

process = no.noise*(1-(0.5*ba.db2linear(responsedb))) : csrldb(freq,responsedb) : norm;
```

Nuovo filtro autoscillante

```
// =====================================================
// Cool Sounding Lowpass With Decibel Measured Resonance
// https://www.musicdsp.org/en/latest/Filters/180-cool-sounding-lowpass-with-decibel-measured-resonance.html

csrldb(fc,r) = biquad(a0c,a1c,a2c,b1c,b2c)
with{
    //punto di taglio normalizzato
    c = 1 / (tan(ma.PI * (fc / ma.SR)));
    //quadrato di c
    csq = c * c;
    //scala in dB per l'ampiezza di guadagno del filtro
    resonance = pow(10, (-r * 0.5));
    //riscalo in termini di ampiezza lineare in rapporto alla banda, (q coefficente di risonanza che rimane stabile in frequenza)
    q = sqrt(2) * resonance;
    //calcolo coefficenti
    a0c = 1 / (1+ (q * c) + (csq));
    a1c = 2 * a0c;
    a2c = a0c;
    b1c = (2 * a0c) * (1 - csq);
    b2c = a0c * (1 - (q* c) + csq);
};

responsedb = hslider("Response[scale:exp]", 1,1,240,1) : si.smoo;

process = no.noise*(1-(0.5*ba.db2linear(responsedb))) : csrldb(freq,responsedb) : norm;
```

TODO:
- valutare se serve la radice quadrata in attenuazione (1-(0.5*ba.db2linear(responsedb))) oppure sqrt((1-(0.5*ba.db2linear(responsedb))))
All'aumentare di reson diminuisce l'ampiezza del noise, con curva quadratica l'ampiezza diminuisce di piú ma dopo, filtro che scompaia linearmente o alla fine del pomello.
- trovare punti di innesco per entrambi i filtri
- interazione filtergraph e osc, per avere uscita coreaudio a osc (strumenti che ci servono, oscilloscopio, spettroscopio)
- software oscilloscopio (x42)
