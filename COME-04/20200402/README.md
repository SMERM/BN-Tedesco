# Appunti Lezione 2 Aprile 2020

[Cartella Google Drive](https://drive.google.com/drive/folders/0B--_h5RB_vmyR3FnajlkSE1zNG8?usp=sharing)

Biennio, Elettroacustica parte teorica e parte laboratoriale


## Programma

- Argomenti: Amplificazione, Ambisonics, elettronica ed elettrotecnica, piccoli circuiti realizzati in classe

- Materiale nella cartella biennio: 3 dispense (acustica di piccoli e grandi ambienti rientra nel programma di Giordano)

- ESE 01-11 e ESE 02-11

- Articoli di Leonardo Scopece su microfono VMS

## Lezione

Ascolto stereo con 2 altoparlanti attraverso il cross-talk, differisce in accuratezza rispetto all'ascolto che avviene in cuffia attraverso quindi un **ascolto binaurale**

ITD e IID, differenza di tempo e di intensità e larghezza testa (circa 17 cm)

Lunghezza d'onda è _λ=c/f_

Suono con frequenza con lunghezza d'onda minore di 17 cm, la nostra faccia crea un mascheramento nel suono che viene usato ad esempio dal cervello attraverso **HRTF** (Head Related Transfer Function)

Noi possiamo ovviamente simulare queste metodologie usate dal cervello e ricrearle attraverso software

Oltre al suono stereofonico, riprodotto da 2 soli altoparlanti, è peró importante dal punto di vista storico introdurre l'audio multi-canale

Audio multi-canale si è mosso verso 2 direzioni:
1) musica
2) ambito scientifico puro

Nel mondo dell'industria dell'intrattenimento è sempre stato importante diffondere e creare una standardizzazione, mentre nell'ambito scientifico puro, si è cercato sempre di andare avanti e non standardizzarsi

**Primi esperimenti** dell'audio multi-canale nel cinema risalgono agli anni '30, per uno dei primi lungometraggi di animazione di Walt Disney, ovvero Fantasia(1940) film nato dall'idea del compositore Stokowski, audio registrato in maniera ottica(segnale elettrico, tradotto su nastro come una variazione di segnale luminoso, variazione di luminosità tradotta in variazione del suono)

[Approfondimento su registrazioni di Stokowski](https://www.stokowski.org/1939_1940_Electrical_Recordings_Stokowski.htm)

Suono registrato su 8 tracce > mix audio su 3 tracce > poi mixato su 4 tracce di cui una con la traccia di spazializzazione, e spazializzato con 54 altoparlanti in sala, e sistema che Disney ha cercato di standardizzare e chiamò _Fantasound_

Ma non vennero creati altri film con questa tipologia di sistema

Successivamente fino agli anni '60 si passò all'audio mono, passando allo stereo fino agli anni '70 in cui si cercò di passare nuovamente all'audio multi-canale, iniziatori di questo progetto multi-canale per il cinema

Dolby e Gerzon lavorarono insieme e poi si divisero

Dolby > Commercializzazione dei sistemi
Gerzon > ricerca su Ambisonics

Dolby iniziò a commercializzare un sistema multi-canale per un sistema analogico con 4 canali con codifica e decodifica

**Encoder** con 4 canali: Left, Right, Center e unico canale Surround(canale diffuso dietro ed ai lati)

Codifica questi 4 canali e canale centrale -3 db > vuol dire mixare il parlato pan-pottato al centro e attenuato di 3 dB

![Dolby sorround schema](https://github.com/SMERM/BN-Tedesco/blob/master/COME-04/20200402/Dolby_Sorround.png)

sul canale Surround il suono era -3 dB, filtrato, veniva applicato NR(Noise Reduction) e Phase Shifter(spostato di fase di 90º)

**Decoder** faceva il procedimento opposto

Vantaggio di questo sitema era che se avevo un sistema solo stereo, non avevo incompatibilità ed era quindi _Stereo compatibile_

**Primo sistema digitale multi-canale** fu il Dolby 5.1

Ovviamente inizialmente la memoria era limitata, e dunque iniziò ad usarsi la compressione (con mp3 ad esempio, motion picture group 3), riducendo il peso di un dato 
