import("stdfaust.lib");
/*as
a0 = 0.9;
a1 = 0.1;
a2 = 0.1;
b1 = 0.2;
b2 = 0.2;

preInHistory = _ <: _*a0, _*((@(1)*a1):(@(2)*a2)) :> _;
preOutHistory = @(1) <: _*b1, @(2)*b2 :> _ ;
biquad1 = _ <: preInHistory : (-~preOutHistory) :> _;
*/

a0c =  vslider("a0[style:knob]",0,0,1,0.01);
a1c =  vslider("a1[style:knob]",0,0,1,0.01);
a2c =  vslider("a2[style:knob]",0,0,1,0.01);
b1c =  vslider("b1[style:knob]",0,0,1,0.01);
b2c =  vslider("b2[style:knob]",0,0,1,0.01);


a0(a0c) = *(a0c);
a1(a1c) = @(1) : *(a1c);
a2(a2c) = @(2) : *(a2c);

b1(b1c) = @(1) : *(b1c);
b2(b2c) = @(2) : *(b2c);

a(a0c,a1c,a2c) = _ <: a0(a0c), (a1(a1c) : a2(a2c)) :> _;
b(b1c,b2c) = b1(b1c) <: _, b2(b2c) :> _ ;

biquad(a0c,a1c,a2c,b1c,b2c) = _ <: a(a0c,a1c,a2c) : (-~b(b1c,b2c)) :> _;

//a = a0(0.9), a1(0.1), a2(0.1);
//b = b1(0.2), b2(0.2);

process = _ : biquad(a0c,a1c,a2c,b1c,b2c) : _;
