declare name "Stereo filtered distortion";
declare version "0.1";
declare author "JOS, revised by RM, revised by DT";
declare description "Distortion demo application.";

import("stdfaust.lib");

process = fi.allpass_fcomb(1024,10.5,0.95) : dm.cubicnl_demo <: _,_;

