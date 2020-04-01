import("stdfaust.lib");
decimal(x) = x - floor(x);
freq = 440;
step = freq/ma.SR;

phasor(freq) = +(freq/ma.SR)~decimal: -(step);

sine = sin(phasor(freq)*2*ma.PI);

process = sine;
