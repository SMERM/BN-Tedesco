# Appunti della lezione di Giovedí 7 Maggio 2020

costant power panning

pag 460 costant power panning in Curtis Roads

##### Bibliografia (Libri da avere a casa)
Curtis Roads - Computer Music Tutorial

JOS site

DFAX book

https://ccrma.stanford.edu/~jos/

_______________
*Appunti*

formula di panning tra canali adiacenti su sistema multicanale

_Ch = cos(angstep*NCH-ang)_

la formula invece di usarla cosí, la si riusa anche come formula esponenziale

_Ch = A^(cos(angstep*NCH-ang))_

e ancora la formula diviene

_Ch = 10^((((1/2)*cos(angstep*Nch-ang)-0.5)*sep*0.2)/2)_

SDK di Max > realizzazione in Max

_______________
visione spanner

```
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
```

n8pan >> versione del panner con distanza, riverbero con movimento con doppler
________________
Aulus riverbero zita programmatore belga

_______________

Auratone > monitor di riferimento > casse molto semplici

_______________

crossover passivo per speaker ??

Fostex > FA100

filtro di primo ordine > resistenza e condensatore

crossover a tre bande per 3 vie

per crossover non si va oltre il secondo ordine in genere

pagina 88 > imparare l'elettronica da zero

elettronica : arte dell'approssimazione > ogni costruttore aggiunge la sua spezia

casse in genere hanno crossover fisso > ma perchè non fare un crossover regolabile?!?

prendere il tweeter prima di tutto

progetto del filtro in base

_______________
mondo hifi > woofer passivo > membrana senza avvolgimento

_______________

calcolo del litraggio del cabinet e parte empirica
