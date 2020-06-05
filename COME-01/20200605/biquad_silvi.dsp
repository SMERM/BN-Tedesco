import("stdfaust.lib");
//a0c =  vslider("a0[style:knob]",0,0,1,0.01);
//a1c =  vslider("a1[style:knob]",0,0,1,0.01);
//a2c =  vslider("a2[style:knob]",0,0,1,0.01);
//b1c =  vslider("b1[style:knob]",0,0,1,0.01);
//b2c =  vslider("b2[style:knob]",0,0,1,0.01);
a0(a0c) = *(a0c);
a1(a1c) = @(1) : *(a1c);
a2(a2c) = @(2) : *(a2c);
//b1(b1c) = @(1) : *(b1c); // il @1 su una linea ricorsiva equivale a 2 campioni di ritardo, uno della linea, uno della memoria.
//b2(b2c) = @(2) : *(b2c); // idem,… tre campioni.
b1(b1c) = *(b1c);
b2(b2c) = @(1) : *(b2c);
// a(a0c,a1c,a2c) = _ <: a0(a0c), (a1(a1c) : a2(a2c)) :> _; // sono tre percorsi paralleli… ti sei fatto ingannare dalle memorie di ritardo di maxbusta;)
a(a0c,a1c,a2c) = _ <: a0(a0c), (a1(a1c), a2(a2c)) :> _;
b(b1c,b2c) = _ <: b1(b1c), b2(b2c) :> _ ;
biquad(a0c,a1c,a2c,b1c,b2c) = _ <: a(a0c,a1c,a2c) : (-~b(b1c,b2c)) :> _;
// resta così un errore da risolvere… non proprio banale: la sottrazione è di a-b mentre l'operatore recursione in nquesto modo occupa la prima entrata in b-a
//a = a0(0.9), a1(0.1), a2(0.1);
//b = b1(0.2), b2(0.2);
process = biquad(0.9,0.1,0.1,0.2,0.2);
