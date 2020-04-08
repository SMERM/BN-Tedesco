# Appunti lezione Mercoledí 8 Aprile 2020

- Raspberry Pi linkati > per realizzare un mixer ed una matrice linkata

- in libreria vanno solo oggetti che producono suono

- [matrice per Raspberry](https://learn.adafruit.com/untztrument-trellis-midi-instrument)

- [OSC1](https://github.com/s-e-a-m/faust-libraries/blob/master/vcs3.lib) del VCS3 realizzato la lezione precedente

- libreria [cyclone](https://puredata.info/downloads/cyclone) > libreria per Pure Data con oggetti di Max ricreati

esempio di _biquad_ che suona in modo totalmente diverso in Max e Pure Data

- [matrice risonanze erranti](https://github.com/s-e-a-m/References/blob/master/Nono-Luigi/latex/matrix.pdf) utile come fatto operativo, catena dei processi cambia in base all'esecuzione, matrice diviene uno strumento che porta l'eseguibilità a un livello successivo

- partitura risonanze erranti scritta a scene, alcune scene contengono altre scene piú complesse precedentemente

- prima realizzazione osc2 del VSC3 per il brano di Nottoli [OSC2]()

- differenza di codice è che utilizzo fasori diversi per oscillatori diversi

- differenza oscillatore tabellare ed oscillatore matematico, oscillatori ricavati da filtri risonanti, ultimo oscillatore aggiunto della libreria Casio

- FAUST limitato a 192 KHz

- in [libreria di Faust](https://github.com/grame-cncm/faustlibraries/) a oscillators vediamo come sono fatti tutti gli oscillatori

- CIM atti dei convegni > articolo di pellecchia > che lavorava per il CRM > filtri risonanti da pensare di farci degli oscillatori

- velocità della luce > ciò che si avvicina il piú possibile all'analogico

- creazione dell'oggetto ma.decimal di Faust `decimal(x)= x-(floor(x));`, floor è una funzione matematica che trattiene solo il valore intero, funzione decimal sottrae solo la parte intera
