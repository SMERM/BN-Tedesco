declare filename "spanner_1x8.dsp"; declare name "spanner_1x8"; declare name 		"spanner_1x8";
declare version 	"1.0";
declare author 		"THC-SCALAS";
declare license 	"BSD";
declare copyright 	"Cecilia-labs";

//==========================================================
//
// 					    spanner_1x8
//	                traspose panner_1x8 
//
//==========================================================

import("stdfaust.lib");

nch     = 8; //NUMERO DI CANALI IN USCITA
angstep = 360.0/nch; //DISTANZA ANGOLARE INTERSPEAKER IN GRADI
ang 	= nentry("Angle[style:knob]",360,0,360,0.1)  : si.smooth(ba.tau2pole(0.02)); //DIREZIONE ANGOLARE DELLA SORGENTE IN GRADI
sep 	= hslider("Separation", 12, 0, 100, 0.1) : si.smooth(ba.tau2pole(0.02)); //SEPARAZIONE INTERSPEAKER DELLA SORGENTE

angr    = ang*ma.PI/180; //ANGOLO IN RADIANTI
angstepr= angstep*ma.PI/180; //DISTANZA ANGOLARE INTERSPEAKER IN RADIANTI


//*********** CALCOLA I SEGNALE PER TUTTELE 8 USCITE ***********************//

process(sig) =  sig*(pow(10, ((0.5*cos(angstepr*1-angr)-0.5)*sep)*0.2)),
                sig*(pow(10, ((0.5*cos(angstepr*2-angr)-0.5)*sep)*0.2)),
                sig*(pow(10, ((0.5*cos(angstepr*3-angr)-0.5)*sep)*0.2)),
                sig*(pow(10, ((0.5*cos(angstepr*4-angr)-0.5)*sep)*0.2)),
                sig*(pow(10, ((0.5*cos(angstepr*5-angr)-0.5)*sep)*0.2)),
                sig*(pow(10, ((0.5*cos(angstepr*6-angr)-0.5)*sep)*0.2)),
                sig*(pow(10, ((0.5*cos(angstepr*7-angr)-0.5)*sep)*0.2)),
                sig*(pow(10, ((0.5*cos(angstepr*8-angr)-0.5)*sep)*0.2));
