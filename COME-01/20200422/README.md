# Appunti della lezione di Mercoledí 22 Aprile 2020

idea è che se c'è già fatto nella libreria di Faust, si studia, si fa e si fa suonare

- come si fa suonare un oscillatore dalla funzione seno

- fasore di controllo > in vcs3 come oscillatore alternativa

fasore dell'oscillatore 1 del vcs3: sinusoide, fasore, M, W, poi forme ibride

banda del filtro > problema degli oscillatori che hanno tantissime armoniche > andiamo a sbattere Nyquist

VCS3 > frequenza a banda passante di 10k

ragionamento sulla frequenza di campionamento

studio del filtro allpass del charlieverb > nottoli, faust, curtis roads

filtro allpass al cambiare della frequenza di campionamento cambia il risultato > considerazione del filtraggio

filtro allpass a frequenze elevate realizza modulazione d'ampiezza

#### È sbagliato lavorare a frequenze di campionamento basse

frequenza in direzione dei 192kHz > per consapevolezza dei filtri e capire la matematica e scientifica

allpass > filtro che diffonde un impulso > filtro ricorsivo > filtro IIR > linea di feedback che calcolata a SR diversi porta ovviamente a diversi risultati

nuovo fasore > fa il calcolo prima della ricorsione e non dopo la stessa

prima il fasore faceva offset > aggiunta valore oltre l'uno spostava sul cerchio la posizione della nostra oscillazione e la fa muovere di offset positivo > step all'aumentare della frequenza è piú grande

come cercare oscillatori in libreria di Faust

da provare triangleN e triangleN(2) > onda quadra, limitato in banda e fa una triangolare

_lf_triangle_ puó essere utile per osc3

oscillatori a banda limitata > limitati in banda\

treno di impulsi fatto con il duty cycle > componenti fondamentali perchè governata dal pomello shape

oscillatori basati su filtri

_quadosc_ >filtro indicato per fare le basse frequenze

codice ha questo livello di complessità perchè è limitato in banda

quadre generate matematicamente > non limitate in banda

duty cycle comodo in pulsetrainN che squareN non ha

non possiamo usare

seq > sequenza di filtri > sequenza ordinata da carattere di punti di oggetti

impulso, _x-x'_ realizzato con sottrzione con campione ritardato

individuare quale è l'oggetto che mette in fase un'onda quadra

vedere come è fatto oscillatore _triangle_ in Faust

_poly_ legati a nc e quindi legati da N

se so che ordine massimo è 1

clippedFreq > limitazione in banda

```
import ("stdfaust.lib");

osc1_g(x) = hgroup("[001]OSCILLATOR 1", x);
freq  = osc1_g(vslider("[001]FREQUENCY[style:knob][scale:exp]", 100,1,10000,0.01) : si.smoo);shape = osc1_g(vslider("[002]SHAPE[style:knob]", 5,0,10,0.1)/10 : si.smoo);
samp = osc1_g(vslider("[003]SINE[style:knob]",0,0,1,0.001):si.smoo);
pamp = osc1_g(vslider("[004]SAW[style:knob]",0,0,1,00.1):si.smoo);

vcs3osc1(f,s,sl,pl) = shaped, saw
  with{
    step = f/ma.SR;
    phasor(step) = step : (+ : ma.decimal)~_;
    sine = sin(phasor(step)*2*ma.PI) : *(0.5*sin(s*(ma.PI)));
    wsine = sin(phasor(step)*(-1)*ma.PI) : +(0.5) : *(cos(s*(ma.PI)));
    shaped = (sine+wsine)*sl;
    saw = (phasor(step)-(0.5))*pl;
};
//process = vcs3osc1(freq,shape,samp,pamp);

MAX_SAW_ORDER = 4; MAX_SAW_ORDER_NEXTPOW2 = 8; // par cannot handle the case of 0 elements
sawN(N,freq) = saw1l : poly(1)
with {
  Nc = max(1,min(N,MAX_SAW_ORDER));
  clippedFreq = max(20.0,abs(freq)); // use lf_sawpos(freq) for LFOs (freq < 20 Hz)
  saw1l = 2*lf_sawpos(clippedFreq) - 1; // zero-mean, amplitude +/- 1
  // Also note the availability of lf_sawpos_phase above.
  poly(1,x) = x;
  p0n = float(ma.SR)/clippedFreq; // period in samples
  diff1(x) = (x - x')/(2.0/p0n);
  diff(N) = seq(n,N,diff1); // N diff1s in series
  factorial(0) = 1;
  factorial(i) = i * factorial(i-1);
};

pulsetrainN(N,freq,duty) = diffdel(sawN(N,freqC),del) with {
 // non-interpolated-delay version: diffdel(x,del) = x - x@int(del+0.5);
 // linearly interpolated delay version (sounds good to me):
    diffdel(x,del) = x-x@int(del)*(1-ma.frac(del))-x@(int(del)+1)*ma.frac(del);
 // Third-order Lagrange interpolated-delay version (see filters.lib):
 // diffdel(x,del) = x - fdelay3(DELPWR2,max(1,min(DELPWR2-2,ddel)));
 DELPWR2 = 2048; // Needs to be a power of 2 when fdelay*() used above.
 delmax = DELPWR2-1; // arbitrary upper limit on diff delay (duty=0.5)
 SRmax = 96000.0; // assumed upper limit on sampling rate
 fmin = SRmax / float(2.0*delmax); // 23.4 Hz (audio freqs only)
 freqC = max(freq,fmin); // clip frequency at lower limit
 period = (float(ma.SR) / freqC); // actual period
 ddel = duty * period; // desired delay
 del = max(0,min(delmax,ddel));
};

vcs3osc2(N,freq,duty) = os.pulsetrainN(N,freq,duty);

//process = vcs3osc2(1,100,0.5);

vcs3osc1(f,s,sl,pl) = saw
  with{
    step = f/ma.SR;
    phasor(step) = step : (+ : ma.decimal)~_;
    sine = sin(phasor(step)*2*ma.PI) : *(0.5*sin(s*(ma.PI)));
    wsine = sin(phasor(step)*(-1)*ma.PI) : +(0.5) : *(cos(s*(ma.PI)));
    shaped = (sine+wsine)*sl;
    saw = (phasor(step)-(0.5))*pl;
};

clippedFreq = max(20.0,abs(freq)); // use lf_sawpos(freq) for LFOs (freq < 20 Hz)
saw1l(freq) = 2*os.lf_sawpos(clippedFreq) - 1;
process = saw1l(20000),vcs3osc1(20000,0.5,0,1);
```
