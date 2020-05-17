# Repository del ciclo di Biennio di Davide Tedesco

## [CODM-05](/CODM-05)
_Storia della musica elettroacustica._

- Seminario software per l'analisi

## [COME-01](/COME-01)
_Esecuzione e interpretazione della musica elettroacustica. Ambienti esecutivi e di controllo per il live electronics._
### Brani trattati durante il corso:
- Luigi Nono - Post-prae-ludium n. 1 per Donau
- Giorgio Nottoli - Incontro

#### Giorgio Nottoli - Incontro
- realizzazione del VCS3 in Faust

#### Luigi Nono - Post-prae-ludium n. 1 per Donau
- 
## [COME-02](/COME-02)
_Composizione musicale elettroacustica._
### Primo Progetto: Chitarra Classica

![Guitar](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Bernardini/20200114/Schemi_chitarra_classica/ebguitars_plan_complete_large.png)

Ricerca sulla chitarra classica(acustica con corde in nylon) e primo approccio allo sviluppo di studi per lo strumento "espanso".

- la chitarra come percussione, ovvero catalogazione delle modalità di percussione-> [schema ed esempi](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Bernardini/20200204/Modi%20di%20percussione%20con%20le%20dita.pdf)
- eccitazione del piano armonico attraverso un attuatore [Visaton EX 60 R](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200407/ex60r_8.pdf) -> [analisi spettrale ed esempi](https://github.com/SMERM/BN-Tedesco/tree/master/COME-02/Lezioni_in_Compresenza/20200317/Various_Sweeps)
- ripresa con sensore piezoelettrico dello strumento(Rappresentazione del _micro_, il "da vicino") -> [Esempi]()
- ripresa microfonica con microfono esterno dallo strumento (Rappresentazione del _macro_, il "davanti allo strumento") -> [esempi]()
- catalogazione dei suoni consonantici e vocalici per implementazione in live degli stessi sull'attuatore -> esempi
- criteri per la spazializzazione in sala da concerto ???
- gestione agevole del suono ripreso micro e macro (algoritmo di interpolazione fra i due???)
- algoritmo di sintesi della corda "Karplus-Strong" -> [articolo](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200303/Kevin%20Karplus%20and%20Alex%20Strong%20-%20Digital%20Synthesis%20of%20Plucked-String%20and%20Drum%20Timbres.pdf), [algoritmo realizzato in Faust](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200324/karplus_filtrato.dsp), [Esempi](https://github.com/SMERM/BN-Tedesco/tree/master/COME-02/Lezioni_in_Compresenza/20200331/Esempi_Karplus-Strong_Attuatore_su_chitarra)
- estensioni dell'algoritmo di sintesi della corda "Karplus-Strong" -> [articolo](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200407/David%20A.%20Jaffe%20and%20Julius%20O.%20Smith%20-%20Extensions%20of%20the%20Karplus-Strong%20Plucked-String%20Algorithm.pdf)
- Lettura e studio del manuale "The Contemporary Guitar" di John Schneider -> [Manuale](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200331/The-Contemporary-Guitar-Schneider-Vol-5.pdf)
- Lettura e studio di "Principles of Idiomatic Guitar Writing" di Jonathan Godfrey ->[Testo](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200331/Principles%20of%20Idiomatic%20Guitar%20Writing%20-%20Jonathan%20Godfrey.pdf),  [Esempi Audio](https://github.com/SMERM/BN-Tedesco/tree/master/COME-02/Lezioni_in_Compresenza/20200331/Principles%20of%20Idiomatic%20Guitar%20Writing%20-%20Jonathan%20Godfrey_Audio_Tracks)
- sostegno infinito del suono di chitarra attraverso l'[algoritmo realizzato in Faust](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200324/karplus_filtrato.dsp) -> [esempi]()
- lettura del [testo di Emilio Pujol "The dilemma of Timbre on the Guitar"](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/1979-Emilio-Pujol-Il-Dilemma-del-Timbro-sulla-Chitarra/1979-emilio-pujol-el-dilema-del-sonido-en-la-guitarra.pdf), [traduzione in italiano del testo di Emilio Pujol "The dilemma of Timbre on the Guitar"](https://github.com/SMERM/BN-Tedesco/tree/master/COME-02/Lezioni_in_Compresenza/1979-Emilio-Pujol-Il-Dilemma-del-Timbro-sulla-Chitarra/1979-Emilio-Pujol-Il-Dilemma-del-Timbro-sulla-Chitarra-Traduzione)
- analisi dei brani di [chitarra elettrica contemporanea](https://github.com/SMERM/BN-Tedesco/tree/master/COME-02/Lezioni_in_Compresenza/Chitarra_Elettrica_Contemporanea)
- [VIDEO - esempio chitarra classica distorta](https://youtu.be/K3yqyxcJStg)
- [VIDEO - esempio feedback strutturale(piezo-attuatore) su chitarra classica](https://www.youtube.com/watch?v=TraqAMf5Exo)-> nella descrizione del video, minutaggio segnato di alcuni primi esempi di feedback
- [algoritmo per la gestione del feedback realizzato in Faust(FEEDBACK_CONTROLLER v.0.1)](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200512/FEEDBACK_CONTROLLER.dsp)
![FEEDBACK_CONTROLLER v.0.1](COME-02/Lezioni_in_Compresenza/20200512/FEEDBACK_CONTROLLER%20v.0.1.png)
- IR chitarra classica sistema sensore-attuatore [posizione 1](COME-02/Lezioni_in_Compresenza/20200519/Sistema_Sensore-Attuatore_Posizione_1) ![ir chitarra posizione 1](COME-02/Lezioni_in_Compresenza/20200519/Classica_Attuatore_Posizione_1_Cal.jpg)
- IR chitarra classica sistema sensore-attuatore posizione 2(da fare) ![ir chitarra posizione 2]()
- [VIDEO - implementazione di un LPF e un pedale MIDI(ON/OFF) per controllo del feedback, scordatura durante Feedback](https://youtu.be/7BwwTopM3Ek)


### Lavori 
- [Sketches](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200324/Sketches.pdf)
#### Studi 
- Legenda: [Draft_1_Legenda](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200407/Legenda_Part_Perc.jpg)
- Studio n.1 : [Intenzioni compositive dello Studio n.1](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200505/Intenzioni_compositive_dello_Studio_n.1.md),[Draft_1 Studio n.1 Partitura](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200331/Draft_1_Studio_n.1_Partitura.pdf), [Draft_1 Studio n.1 Audio](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200331/Draft_1_Studio_n.1_Audio.wav), [Draft_2 Studio n.1 Partitura]()
- Studio n.2:[Intenzioni compositive dello Studio n.2](), [Draft_1 Studio n.2 Partitura](https://github.com/SMERM/BN-Tedesco/blob/master/COME-02/Lezioni_in_Compresenza/20200407/Draft_1%20Studio%20n.2%20Partitura.pdf), [Draft_2 Studio n.2 Partitura](), [Draft_2 Studio n.2 Audio]()
- Studio n.3:[Intenzioni compositive dello Studio n.3](COME-02/Lezioni_in_Compresenza/20200519/Intenzioni_compositive_dello_Studio_n.3.md), [Appunti Studio n.3 (a)](COME-02/Lezioni_in_Compresenza/20200519/Appunti_Studio_n.3_a.jpeg)

## [COME-04](/COME-04)
_Elettroacustica_
![farfallone](/COME-04/Spherical_Harmonics_deg3.png)
### Argomenti trattati:
#### Teoria
- Audio multi-canale
- Ambiophonics
- Ambisonics
#### Pratica
- Inizio di saldatura di componenti hardware per l'audio
- La resistenza
- Il Condensatore
- Esempi di primi filtri


