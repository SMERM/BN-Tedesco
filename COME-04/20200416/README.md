# Lezione di Giovedí 16 Aprile 2020

- applicativo della spazializzazione binaurale, trasferito in rete per riprodurre bene la spazializzazione iniziale multi-canale

#### Strumenti utili per saldatura
- saldatura  > fare pratica
- saldatore
- stagno
- morsettiera braccetti
- multimetro

- _idea_ realizzazione di tester da cavi

- [sito > per realizzazione pedali](https://www.musikding.de/)

Entro prossima lezione
-------------
Riprendiamo il discorso dell'Ambisonics dalla dispensa 2-11, concetto di codifica e decodifica

#### Codifica e decodifica ambisonics di primo ordine per realizzare uno spazializzatore

![encoder_ambisonic_in_faust](https://github.com/SMERM/BN-Tedesco/blob/master/COME-04/20200416/encoder_ambisonic_in_faust.png)

abbiamo fatto la codifica di un segnale con Ambisonics di primo ordine

Adesso vediamo la decodifica

facciamo una codifica planare, angolo iniziale è sempre 0

![panner_lineare_equipotenziale]()

al centro attenuazione di -3db poichè il nostro sistema di ascolto funziona in maniera logaritmica

panning equipotenziale > se abbiamo una curva logaritmica come curva di attenuazione

somma > in panning anche se dal punto di vista potenziale sfora l'1 noi lo sentiamo in maniera potenziale > il secondo è equpotenziale

formula panpot equipotenziale con piú di 2 canali > quindi multi canale

separazione da 0 a 100 > suono su canali che si muove

su Ambisonic c'è sempre presenza di suono su altoparlanti adiacenti > ciò ha un senso > Ambisonics > viene eliminato l'_effetto spot_

Sento il suono con Ambisonics come se provenisse da uno speaker virtuale

Ambisonics per fare binaurale > sorgente che normalmente è quadrifonica > decoder su 2 canali

Ambisonics > non ha la distanza > movimento su una superfice di una sfera

Binaurale > inserito anche il riverbero > movimento di un suono in una sfera > inserimento di un riverbero > oggetto in movimento produce una variazione di intonazione > Effetto Doppler> tanto maggiore quanto è la distanza dalla sorgente

Ambisonics > oggetti sonori sono in orbita su una sfera > e possono muoversi a distanza prefissata

Ma qual'è questa distanza prefissata > sfera tangete agli altoparlanti > suono lo sentiremo sempre in questa sfera circoscritta dagli altoparlanti

Binaurale ci si puó muovere all'interno della sfera e all'esterno (in ambisonics > direzione angolare)

provare a fare decoder > e codificare disco stereo > ambisonic planare > spostamento -30 e +30 angolo > stereofonia ascolto su casse

seconda situazione > effetto precedenza molto minore su ambisonic

passare da codifica a decodifica & _transcodifica_ > codifica ad esempio da 5.1 a 8.2
