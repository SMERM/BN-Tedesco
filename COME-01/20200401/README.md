##Appunti della lezione di Mercoledí 1mo Aprile 2020

- Introduzione al progetto SEAM, basato sull'[articolo](https://github.com/s-e-a-m https://www.academia.edu/16348988/Sustainable_live_electro-acoustic_music) di Bernardini e Vidolin

- Esempio del lavoro effettuato lo scorso anno con Risonanze Erranti

- Brani affrontati lo scorso anno e percorso iniziale, descritto in [articolo LAC](https://github.com/s-e-a-m/References/blob/master/draft-paper/LAC-20-SEAM-sent.pdf)

- Per il mondo dopo il Conservatorio serve Bibliografia, serve realizzare articoli per  

- Seguire [corso](https://chigiana.org/live-electronics-2020/) estivo Chigiana, con Vidolin, con la direzione di Nicola Sani, molta musica e poco marketing

- Unico esecutore Fondazione Luigi Nono è Alvise Vidolin, problema di diffusione, danno di cui sentiamo il peso tra 20 o 30 anni

- Vidolin essendo un interprete capisce ed intende ciò che Stockhasuen intendesse attraverso la partitura

- Fondazione Stockhausne, scuola per esecuzione di musica di Stockhasuen

- Ensemble Moderne a Francoforte

---------------------------------------
**Per quest'anno**
- Continuare con Nono > magari per realizzare magari un domani un concerto con tutti brani di Nono

- Primo brano scelto: Post-Praeludim per Donau, brano scritto per Schiaffini(tubista e trombonista), brano per strumentista, partitura è piú uno schema che una partitura vera e propria

- Secondo brano scelto: Scuola Romana, difficoltà nell'accedere al materiale, Incontro, brano di Giorgio Nottoli, quando era studente con Mario Bertoncini > recupero del materiale da parte di Nottoli con operazione di archeologia musicale

---------------------------------------
- ad esempio, facendo pratica continua con "I am sitting in a room", si può sviluppare piú consapevolezza attraverso la pratica

- per brano di Nottoli serve un synth VCS3, che è nel Conservatorio di Pesaro, synth monofonico, synth con una matrice

- dovendo fare un brano che ha in partitura un Synth analogico

- oscillatore analogico, oscillatore con un fasore, oggetto che fa muovere un oscillatore, puntatore alla fase dell'oscillatore, quanto segnale elettronico far uscire dall'oscillatore

- shape, duty cycle, abs > passaggi

- come passo in maniera fluida ?? > alla base di ciò > abs(sin) e -abs(sin)

- matrice > è il cuore del VCS3

- disegno del fasore è invertito

- VCS3 > ha un riverbero a molla all'

- [Faust IDE](https://faustide.grame.fr/) usare l'IDE

- concetto di Fasore, concetto di oscillatore virtuale, struttura piú o meno semplice, capire dunque come è fatto un oscillatore

- inizialmente l'oscillatore di cui si parlava era os.osc(freq) in Faust

- noi usicamo invece 'sin()', 'int()' funzione che restituisce solo la parte intera ed istanzia una variabile, 'floor()' funzione matematica che tiene l'ultimo intero disponibile

- tutti i linguaggi testuali sono una sub-letteratura e da soli parlano, quindi Faust ad Esempio

- oggetto usato da Nono era il Mars, ma non sappiamo come poterlo aprire perchè non è stato mai aperto

-----------------------
**Fasore**

// parte di codice
- fasore in faust > process = +(0.01)~_ //punto e virgola

- praticamente un conta campioni, ma infinito, ma a noi serve che abbia una ciclicità

- controllando il passo del fasore, possiamo controllare la frequenza

- fasore, segnale unipolare > ma se sottraggo il campione al campione precedente > non ce l'ho più unipolare

- offset del segnale che viene per accumulazione dell'imperfezione di calcolo

----------------------
**Sine+Saw**

- risoluzione cambia in base a quanti Hz puó raggiungere

- non avendo una tabella, abbiamo un'accuratezza in base alla frequenza di campionamento

-
