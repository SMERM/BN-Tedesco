# Appunti della lezione di Mercoledí 10 Giugno 2020



Il FLY 30 è capace di lavorare a 32 bit in virgola mobile

Introduzione del calcolo in virgola mobile Pellecchia lo spiega, per specificare la precisione dei calcoli raggiunta!

Consorzio IIEE conversione da numeri floating point a interi

1 bit precision è la tecnologia alla base del DSD -> unità minima di descrizione dell'ampiezza a 1.6 MHz

Ritardo di un campione a quella precisione è il ritardo di un bit

Nel DSD ci sono dei problemi ->derivate sulla modulazione, la qualità del DSD è basata sulla qualità della modulazione

post processing a frequenza di campionamento alta

La qualità della DSD dalla demodulazione e quindi dal filtraggio(LP)



Pensare di fare un oscillatore matematico ad un bit di precisione, e l'oscillatore si può fare...

Oscillatore che suona in DSD -> porta audio di Raspberry(i2s) già lavora 

Se si capisce come gestire il ritardo per il DSD in Faust o altro è molto semplice poi fare l'architettura C++

____________

HiFi Berry -> compilazione sistema operativo alta qualità per l'audio

[OWL Pedali](https://www.rebeltech.org/product/owl-pedal/) fatti con Faust

__________________

Articolo di Pellecchia ci deve spingere a fare un lavoro ricerca, dato che in bibliografia non sono specificati articoli inerenti a quella stessa ricerca

Riferimenti di JOS non vanno cosí indietro (al 1991)



succo dell'articolo è che il lavoro è un lavoro di calcolo pesante.

Tramite i coefficenti ->il filtro lavora al limite di stabilità ed ha il comportamento di un oscillatore.

Parametri di controllo per calcolare a quei livelli di controllo in tempo reale

**Difficoltà** è imbrigliare tutti i controlli del filtro in un pomello solo che gestisca da solo esso il filtro oscillante.



Il pomello RESO -> fa cambiare il comportamento da filtro a oscillatore



quali sono i coefficenti che fanno passare il filtro, da filtro a oscillatore



Nel momento in cui un filtro passa da LP a filtro risonante, l'ampiezza cambierà molto



La scelta di frequenza di attacco cambia il punto in cui il filtro si innesca



Considerare che per la logica di accumulazione del filtro, una frequenza grave...



Strategia utilizzabile per gestire i coefficenti puó essere utilizzando z-plane e filtercoeff come strumenti di studio della modulabilità di questi parametri



- studiare il moogladder filter che c'è in Faust, identico in termini di concezione rispetto a questo VCS3 -> il moog ladder è un filtro estremamente complesso ed è estramemente incontrollabile



Strumentazione di Max che permette di analizzare il comportamento del filtro, è preziosa, poichè non c'è nessun controllo



prendere appunti sulle variazioni che accendono il comportamento 



In sintesi digitale di filtri oscillanti, il filtro deve essere acceso, e dunque devo innescare l'oscillazione, il rumore piú piccolo è una cosa trentottesima



- bisogna trovare una strategia per fare innescare il filtro

Coefficente che per noi è b1 e che per Faust è a1 è la 

```Faust
oscb(f) = impulse : fi.tf2(1,0,0,a1,1)
 with {   
a1 = -2*cos(2*ma.PI*f/ma.SR); 
}; 
```

il nostro biquad è uguale a fi.tf2 con i coefficenti girati ed ispirato a Max



La frequenza del filtro oscillante la si puó controllare agendo attraverso il coefficente a1 (per noi b1)

Studiare come filtergraph~ calcola il cutoff



Il grafico e la frequenza utilizzati da Pellecchia dipendono da 96000

#### TO DO LIST

1. carrozzare il sistema con un pitch tracker messo sotto al moltiplicatore per vedere la frequenza reale in uscita

2. equazione per controllare il guadagno di uscita al variare della frequenza (gain freq ratio)

3. controllo da LP a RESON

4. messaggio per far aggiornare il domain spettroscopio in funzione di dspstate~



vicino al limite minimo andiamo verso il -2 

e verso il limite massimo andiamo a metà banda



a 40000 hz ampiezza a 0.00005

a 20000 hz ampiezza a 0.00005

agli estremi di banda l'ampiezza sale 



3469 hz-> frequenza particolare con campana piú stretta con filtro autooscillante 
