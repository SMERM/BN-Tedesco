import("stdfaust.lib");

//variabili
a0 = 0;
a1 = 0;
a2 = 0;
b1 = 0;
b2 = 0;

histx1 = @(1);
histx2 = @(2);

histy1 = @(1);
histy2 = @(2);

preInHistory(a0,a1,a2) = _*a0 : histx1*a1 : histx2*a2; //input signal
preOutHistory(b1,b2) = (histy1*b1 : histy2*b2) ; //output signal

biquad(a0,a1,a2,b1,b2) = preInHistory(a0,a1,a2) - (-~preOutHistory(b1,b2));


process = biquad(a0,a1,a2,b1,b2);
