import("stdfaust.lib");
//Primo oscillatore del VCS3 con un oscillatore
decimal(x) = x - floor(x);
freq = vslider("FREQUENCY [style:knob][scale:exp]",1,1,10000,0.01);
step = freq/ma.SR;

phasor(freq) = +(freq/ma.SR)~decimal: -(step);

sine = sin(phasor(freq)*2*ma.PI);

saw = phasor : -(0.5);

process = sine, saw;
