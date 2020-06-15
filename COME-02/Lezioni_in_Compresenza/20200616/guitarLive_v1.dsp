/*guitarLive_v1*/
/*Pitch tracker, feedback controller, distortion, amplification*/
import("stdfaust.lib");

/*PITCH TRACKER SECTION*/
ptrack(a,x) = tng(x)
with{
  xcr = (x' < 0) & (x >= 0);
  xcnt = +(xcr)~ %(int(a));
  wnd = xcr & (xcnt == a);
  cnt = (+(1) : *(1 - wnd)) ~ _;
  SH(trig,x) = (*(1 - trig) + x * trig) ~ _;
  nvl = SH(cnt == 0, cnt' + 1);
  tng(x) = a*ma.SR/max(nvl,1) - a*ma.SR*(nvl==0);
};
fptrack(x,a) = x : fi.dcblocker : (fi.lowpass(1) : ptrack(a))~ max(100);

/*FEEDBACK SECTION*/
//button to reset DSP in case the Feedback explode with interpolation
panic_in = *(button("Panic Interpolated")) : si.smoo;
//button to reset DSP in case the Feedback explode instantaneously
panic = *(button("Panic")) : si.smoo;
feedback = _ <: -(panic_in)<: -(panic):> _;

/*DISTORTION SECTION*/
disto = ba.bypass1(on_off, ef.cubicnl_nodc(drive:si.smoo,offset:si.smoo))
with{
	cnl_group(x)  = vgroup("DISTORSIONE [tooltip: Reference:
		https://ccrma.stanford.edu/~jos/pasp/Cubic_Soft_Clipper.html]", x);
	on_off = cnl_group(checkbox("[0] Bypass [tooltip: When this is checked, the
		nonlinearity has no effect]"));
	drive = cnl_group(hslider("[1] Drive [tooltip: Amount of distortion]",
		0, 0, 1, 0.01));
	offset = cnl_group(hslider("[2] Offset [tooltip: Brings in even harmonics]",
		0, 0, 1, 0.01));
};
distortion = disto;

/*FILTERS SECTION*/
filters = fi.dcblocker ;

/*COMPRESSION*/
//compressor = ;
/*GAIN SECTION*/
gain = hslider("Gain",0,0,1,0.0001) : si.smoo;


process = vgroup("guitarLive_v1", _*gain <: distortion : feedback :> filters :/* compressor :*/ _);
