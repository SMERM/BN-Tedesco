declare name "distortion";
declare version "0.0";
declare author "JOS, revised by RM";
declare description "Distortion demo application.";

import("stdfaust.lib");

process = fi.allpass_fcomb(1024,10.5,0.95) : dm.cubicnl_demo <: _,_;

