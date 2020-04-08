import("stdfaust.lib");

osc2_g(x) = hgroup("[002]OSCILLATOR 2", x);
freq  = osc2_g(vslider("[001]FREQUENCY[style:knob][scale:exp]", 100,1,10000,0.01) : si.smoo);
//knob non è infinito, come un encoder
shape = osc2_g(vslider("[002]SHAPE[style:knob][scale:exp]", 5,0,10,0.01)/10 : si.smoo);
amplitude = osc2_g(vslider("[003]AMPLITUDE[style:knob][scale:exp]", 0,1,1,0.01)/10 : si.smoo);
vcs3osc2(freq,shape) = square+wsqaure, triangle //quadra e triangolare sono in relazione tra di loro in un modo particolare
  with{
    step = freq/ma.SR;
    phasor(step) = +(step)~ ma.decimal: -(step);
    square = sin(phasor(step)*2*ma.PI):*(0.5*sin(shape*(ma.PI))); //da correggere
    wsquare = sin(phasor(step)*(-1)*ma.PI):+0.5:*(sin(shape*(ma.PI))); //da correggere
    triangle = phasor(step)-(0.5); //da correggere
};

process = vcs3osc2(freq,shape); //importante per dire che l'oscillatore ha pomelli che sono delle entrate
