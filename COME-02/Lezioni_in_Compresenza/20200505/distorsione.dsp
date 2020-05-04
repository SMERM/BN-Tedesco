//---------------------------`(dm.)cubicnl_demo`--------------------------
// Distortion demo application.
//
// #### Usage:
//
// ```
// _ : cubicnl_demo : _;
// ```
//------------------------------------------------------------
//cubicnl_demo = ba.bypass1(bp, ef.cubicnl_nodc(drive:si.smoo,offset:si.smoo))
//with{
//	cnl_group(x)  = vgroup("CUBIC NONLINEARITY cubicnl [tooltip: Reference:
//		https://ccrma.stanford.edu/~jos/pasp/Cubic_Soft_Clipper.html]", x);
//	bp = cnl_group(checkbox("[0] Bypass [tooltip: When this is checked, the
//		nonlinearity has no effect]"));
//	drive = cnl_group(hslider("[1] Drive [tooltip: Amount of distortion]",
//		0, 0, 1, 0.01));
//	offset = cnl_group(hslider("[2] Offset [tooltip: Brings in even harmonics]",
//		0, 0, 1, 0.01));
//};


declare name "distortion";
declare version "0.0";
declare author "JOS, revised by RM";
declare description "Distortion demo application.";

import("stdfaust.lib");

process = dm.cubicnl_demo;

