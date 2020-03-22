declare name 		"karplus_filtrato";
declare version 	"1.0";
declare author 		"DT";
declare license 	"BSD";

//-----------------------------------------------------------
// 				karplus-strong synhtesis based on the GRAME example
//-----------------------------------------------------------
import("stdfaust.lib");
import("music.lib");

// Excitator
//--------

upfront(x) 	= (x-x') > 0.0;
decay(n,x)	= x - (x>0.0)/n;
release(n)	= + ~ decay(n);
trigger(n) 	= upfront : release(n) : >(0.0);

size 		= hslider("excitation (samples)", 128, 2, 512, 1);




// resonator
//-----------------

dur 		= hslider("duration (samples)", 128, 2, 512, 1);
att 		= hslider("attenuation", 0.1, 0, 1, 0.01);
average(x)	= (x+x')/2;

resonator(d, a) = (+ : delay(4096, d-1.5)) ~ (average : *(1.0-a)) ;

process = noise * hslider("level", 0.5, 0, 1, 0.1)
		: vgroup("excitator", *(button("play"): trigger(size)))
		: vgroup("resonator", resonator(dur, att)):
		//filter
  	dm.filterbank_demo
		//stereo splitter
		<:_,_;
