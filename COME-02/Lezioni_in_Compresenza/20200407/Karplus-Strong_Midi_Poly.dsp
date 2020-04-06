declare name 		"Karplus-Strong_Midi_Poly";
declare version 	"1.0";
declare author 		"DT";
declare license 	"BSD";
declare options "[osc:on]"; //MIDI e OSC implementation
declare options "[midi:on][nvoices:6]";

//-----------------------------------------------------------
// 				Karplus-Strong synhtesis based on the GRAME example
//-----------------------------------------------------------
import("stdfaust.lib");
import("music.lib");
// Eccitatore
//--------
upfront(x) 	= (x-x') > 0.0;
decay(n,x)	= x - (x>0.0)/n;
release(n)	= + ~ decay(n);
trigger(n) 	= upfront : release(n) : >(0.0);

size 				= hslider("excitation (samples)", 256, 2, 1024, 1);
// Risuonatore
//-----------------
dur 				= hslider("duration (samples)", 256, 2, 1024, 1);
att 				= hslider("attenuation", 0.1, 0, 1, 0.01);
average(x)	= (x+x')/2;

resonator(d, a) = (+ : delay(4096, d-1.5)) ~ (average : *(1.0-a)) ;

process = noise * hslider("Volume", 0.5, 0, 1, 0.01)
		: vgroup("Eccitatore", *(button("play"): trigger(size)))
		: vgroup("Risuonatore", resonator(dur, att))
		:dm.filterbank_demo<: attach(_,abs : ba.linear2db : hbargraph("Level[style:dB]",-60,0));
