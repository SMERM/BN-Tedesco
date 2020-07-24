# Appunti della lezione di Venerdí 24 Luglio 2020

- chiudere la parte di didattica
- poi parlare delle prospettive di SEAM
______________
## Punto della situazione dal punto di vista didattico

### VCS3

Oggetto che ci ha preso piú tempo, esso ci ha fatto anche andare a fondo sul funzionamento della macchina.

Capendo come esso è fatto all'interno ci ha aiutato e ci ha fatto studiare.

Dal punto di vista interpretativo questo tipo di creazione ha messo in risalto _il ruolo fondamentale dello strumento_.

Siamo arrivati ad una stesura che sta alla base di una proggettazione di quel tipo:
- filtro
- filtro oscillante
- matrice
- oscillatore

Implementare oscillatori limitati in banda di Sanfilippo ci risolve il problema dell'aliasing, inserendo parti di librerie di altri.

- riverbero (riverbero a molla)

_Lezione con cupola su riverberi_, che ci collega al contesto dell'ottica SEAM con il charlie verb.

_articolo di Schoraeder_ sul riverbero, presentazione del filtro _delay line con feedback_, allpass, ultimo riverbero che presenta, è allpass e comb e lo chiama **ambiophonic reverberator**, esso lo si puó implementare in sala da concerto.

**ambiophonic reverberator** -> da provare su cupola -> collegato al fatto che non si fa stereo con 2 canali -> descrizione di un lavoro accurato per la riverberazione

(noi chiamiamo il riverbero un effetto ma per rendere sostenibile la parola riverbero, dovremmo differenziare _riverbero elettroacustico_ e _riverbero effetto_)

Nella logica di sostenibilità dobbiamo riesumare l'oggetto del riverbero acustico ed elettroacustico.

JOS parla solo di stereofonia...

Invece con il riverbero come oggetto acustico

Riverbero a convoluzione ha la una sola risposta ovvero quella all'impulso.

Problemi collaterali per la sostenibilità, poichè abbiamo problemi a lavorare fianco a fianco

______________
mezzi utilizzati -> faust e max -> rafforzare l'idea che serva una trasversalità di competenze ampia

______________

Cose che non siamo riusciti a fare:
- charlieverb di Nottoli -> unico riverbero italiano non entrato mai su mercato hardware

______________

Cosa si pretende per l'esame:
1. un argomento fatto in maniera precisa
  - per arrivare ad avere una piccola bibbia fatta da singoli articoli, per mettere in discussione con il gruppo

Relazione con tipico schema da articolo.
- buon abstract

Tirar fuori un paper dalla bibbia,
______________

## Forma

### Abstract: 150 parole
- problema
- letteratura
- valore aggiunto e soluzione -> come abbiamo risolto e perchè abbiamo fatto quella scelta

Appoggiarsi alla letteratura e risolvere un problema

Abstract scritto in txt, punti e virgole.

### Introduzione

- problematica
- riferimento letterario per appoggiarsi e per contraddire
- accenno a come viene accennata la problematica, punti dell'abstract sviluppati nell'articolo

### Articolo vero e proprio

forma e scelta in base alle necessità

### Conclusioni

unica cosa che si legge l'Articolo

(abstract, conclusioni e bibliografia sono le cose che vengono subito guardate)

### Bibligrafia IEE

articolo tra 5 e 8 pagine

______________
FIR nell'ottica di implementazione hardware può essere implementata

______________
progetto -> portare un articolo a una conferenza per il VCS3

______________

Post praeludim -> basso tuba -> diffuso tridimensionalmente per dare un significato particolare alla disposizione degli altoparlanti in partitura identificando un grande tetraedro intorno al pubblico, con amplificazione tetraedrica e diffusione e elaborazione tridimensionale

- concerto
- poi articolo

______________
Libri per microfonazione:

Tanta pratica per microfonazione

[concerto netti](https://www.youtube.com/watch?v=rLKKsu4y5x0&t)

movimenti dal contenuto tridimensionale

[conferenza prima del concerto](https://www.youtube.com/watch?v=uaX3Ff_tjXQ )

______________

Recuperare materiale al CRM -> secondo probabile step di evoluzione di quello che potremo fare

### Mobile Locale

- programma fatto
- intero lavoro sul percussionista fatto

- manca la fonte FLY30 di lupone -> copiare il codice e fare il porting da un linguaggio all'altro, arrivare alla conferenza di Faust in modo impeccabile

Capire come era scritto il codice nel FLY

______________

Oscillatori di Dario Sanfilippo

Da valutare se fare il submodule della sua libreria:
- square oscillator
- triangle oscillator

[Link alla libreria di Sanfilippo](https://github.com/dariosanfilippo/edgeofchaos)

[Tesi di dottorato di Sanfilippo]

Librerie pensate con aumentare della frequenza per abbassare il numero delle armoniche

- oscillatore -> routing complesso di segnali letto a  frequenza di campionamento -> piccolo esempio di intelligenza artificiale realizzato da Wolfram

le librerie che ci interessano sono alla fine e sono square e triangle

______________

- panning mid-side
- riverbero di Schroeader mid side
- riverbero di Schoraeder ambisonici

______________
## Prossimo anno

Buon oscilloscopio e analizzatore di spettro fatto con Raspberry

- carta con cose scritte sopra
- analizzare e testare cosa facciamo sempre
______________

Allpass diversi sono veramente allpass tutti?

Editor web csound

______________
Per l'esame sottoporre gli argomenti di tesina un po' prima dell'esame per fare un percorso insieme!

12 Novembre -> ciclo intero per archi di Netti -> incontro e concerto -> Feste Milano Musica
