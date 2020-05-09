/*FEEDBACK CONTROLLER*/
import("stdfaust.lib");

//Pitch Guessing function
//pitchguess= ; 

/*PANIC BUTTONS SECTION*/
//button to reset DSP in case the Feedback explode with interpolation
panic_in = *(button("Panic Interpolated")) : si.smoo;

//button to reset DSP in case the Feedback explode instantaneously
panic = *(button("Panic"));

/*GAIN SECTION*/
gain = hslider("Gain",0,0,1,0.0001) : si.smoo; //be cautious with it

/*FILTERS SECTION*/
//filters = ;
process = vgroup("FEEDBACK CONTROLLER",_*gain <: (-(panic_in)<: -(panic)) :> _);
