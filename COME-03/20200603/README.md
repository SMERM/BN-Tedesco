# Appunti della lezione di mercoledí 3 Giugno 2020

La scorsa volta abbiamo elencato i tipi di approccio che si usano nell'analisi degli ambienti(e spazi musicali)

Abbiamo elencato i 3 approcci utilizzati per l'analisi degli ambienti:

- ondulatorio o modale
- geometrico
- statistico
____
Cos'è un modo naturale di un sistema?

Richiamo del significato dei modi naturali, partendo dallo studio dei modi naturali di una coppia di pareti parallele.

Supponendo di avere una coppia di pareti parallele e perfettamente riflettenti.
Esistenza delle 2 pareti riflettenti determina dei vincoli per il campo acustico.
In corrispondenza delle pareti troviamo 2 ventri. Punti massimi di pressione.

Posso dunque stabilire il modo naturale piú grave al centro del sistema.

![pareti](pareti.png)
L = lunghezza fra le pareti
L = λ1/2 -> c = λ1f -> f1=c/2L

Aggiungendo un nodo posso quindi disegnare il profilo di pressione del secondo modo naturale, compatibile con i vincoli imposti dalle pareti e dunuque

L = λ2 -> f2=c/L=2f1

Troviamo quindi una famiglia di modi naturali, per i quali la frequenza associata ad ogni modo è uguale a -> fn=n*f1

Quindi nel momento in cui do energia al sistema(ad esempio sparando un colpo di pistola), tutte le frequenze si propagano nel sistema, ma quelle frequenze che non fanno parte del sistema si spengono piú velocemente; mentre tutte le frequenze che fanno parte della famiglia delle onde stazionarie armoniche, continuano a vivere piú a lungo.

Il risultato della sovrapposizione di queste onde stazionarie, sarà (secondo il Teorema di Fourier) dotato di altezza. Dunque quello che viene fuori dal filtraggio di queste pareti è un suono che è dotato di pitch.

La risposta in frequenza prescinde dal fatto che ci sia un'energia all'interno del sistema, la risposta in frequenza è quindi come è descritto il filtro realizzato dalle 2 pareti.

Se facessi un'analisi della frequenza, troverei che la famiglia delle armoniche viene eccitata.

(Esempio del battere le mani nel garage)

La funzione di trasferimento del filtro è una funzione nel dominio di Laplace, che racchiude dentro di se, il comportamento del filtro.

Se ho un sistema LTI(lineare tempo variante), l'uscita di questo sistema (y(t)) è data dalla convoluzione dell'ingresso e una funzione particolare chiamata risposta all'impulso

![convoluzione_IR](convoluzione_IR.png)

IR è l'uscita del sistema quando io gli do in ingresso una funzione matematica particolare chiamata _impulso di Dirac_, impulso per definizione è una funzione neutra(come se valesse 1), dunque facendo la convoluzione tra i(t) (impulso di dirac).

i(t)•h(t) = h(t)

Un ambiente possiamo considerarlo sicuramente come un filtro, ma non ha un solo filo di uscita, esso deve tener conto della posizione della sorgente e della posizione del microfono.

I database delle IR, sono una possibile risposta all'impulso di un ambiente, poichè sono un accoppiamento di una sorgente ed un ricevitore.

Devo dunque campionare tutto lo spazio per capire come si comporta, avendo un'idea generale del comportamento dello spazio, capendo se ci sono punti in cui ci sono criticità.

A seconda del tipo di destinazione d'uso() spazio reale o spazio non esistente):
- auditorium -> progetto lo spazio della platea, fissando un certo numero di punti, software fa la simulazione e posso quindi avere risultati
- analisi di uno spazio esistente -> riprese diverse per ognuno dei punti che mi interessa, riprendo certo numero di punti in base alle disponibilità che ho

La IR è una funzione del tempo, segnale di ingresso in _t_, segnale di uscita in _t_,  dalla convoluzione ho una risposta in funzione del tempo.

Dalla Risposta all'impulso derivo la **funzione di trasferimento**, _H(s)_

s non è variabile tempo o frequenza, ma è nel dominio di LaPlace, chiamata **variabile di LaPlace**

Funzione di trasferimento ha tutte le risposte che servono della risposta all'impulso, nel momento in cui calcolo H per una variabile _(jω)_ la funzione diviene _H(jω)_

_H(jω)_ la chiamiamo **Risposta in frequenza**, di essa mi interessa sia il modulo(| _H(jω)_ |) che la fase

Quando mi interesso della risposta in frequenza sto tagliando fuori il tempo, dunque la risposta in frequenza è rappresentativa solo di un momento nel tempo in cui un sistema si è assestato.

Se dalla risposta all'impulso mi ricavo la risposta in frequenza mi sto occupando della parte stazionaria del sistema.

![risposta_frequenza_comb](risposta_frequenza_comb.png)
Filtraggio della risposta in frequenza viene chiamato _comb_, poichè assomiglia ad un pettine, dunque qualunque frequenza diversa da quelle che corrispondono ai picchi, viene effettivamente attenuata, solo le frequenze in corrispondenza dei picchi vengono enfatizzati.

Se non so che risposta ho in un'ambiente devo sviluppare un'equazione differenziale (impongo massima pressione sui vincoli alle pareti) con caratteristiche particolari.

Portare l'esempio descritto in un parallelepipedo di 6 pareti, trovando le soluzioni come le abbiamo trovate per le 2 pareti, cioè estendiamo il ragionamento per uno spazio a 3 dimensioni.

Il campo per le 6 pareti, avremo un'equazione a 3 dimensioni, equazione differenziale di funzioni tridimensionali, piú le condizioni di contorno e dunque avremmo qualcosa che si puó risolvere.

Per il parallelepipedo, in teoria dovrebbero essere molto semplici i calcoli...

Attraverso l'utilizzo dell'[applet Falstad](https://www.falstad.com/modebox/), abbiamo 3 indici.

**Modi assiali** o **monodimensionali** (1,0,0) o (0,0,1) che fanno riferimento esclusivamente ad una coppia di pareti.
![1_0_0](1_0_0.png)

(1,1,0), in questo caso sto implicando due indici e dunque 2 coppie di pareti, **modi tangenziali** e sono modi a due dimensioni, ognuno di questi modi ha una sua frequenza associata.
![1_1_0](1_1_0.png)

La velocità del mezzo è in quadratura di fase con la pressione.
Percorso chiuso all'interno delle 4 pareti, dunque nei punti in verde deve essere 0 la velocità del mezzo, ovvero dove la pressione ha un ventre, la velocità del mezzo ha un nodo.
Il percorso che fa l'onda si chiude, e l'onda percorre 2 lunghezze d'onda, facendo venir fuori quello che vediamo nella figura precedente. Considerando un percorso a 2 dimensioni che tocca 4 pareti.

Come abbiamo trovato la frequenza per le 2 pareti parallele, troviamo una relazione che mette in relazione 4 pareti

Questi modi si chiamano modi tangenziali a 2 dimensioni e sono bidimensionali.

Tutte le matrici accostate sono in realtà come il cubo di Rubik.

Modo (1,1,1) ha 3 superfici nodali, in cui ho un piano diverso in ogni dimensione.
![1_1_1](1_1_1.png)
Questo modo implica tutte e 6 le pareti, e questi modi che implicano ed abbracciano tutte e 6 le pareti si chiamano **modi obliqui** o **tridimensionali**.

Membrana è sostanzialmente a 2 dimensioni, lo spazio è invece a 3 dimensioni e dunque abbiamo 3 indici associati alla descrizione.

Nella prima matrice non entra mai in gioco la terza coppia di pareti, mentre nella seconda matrice inizia ad esser presente la terza coppia di pareti.

_________
Dal sito di amacoustics troviamo il [Room Mode Calculator](https://amcoustics.com/tools/amroc?l=500&w=700&h=300&fo=200&fu=21&r60=0.6), che ci permette di calcolare i modi naturali di una stanza, facendoci intendere dove sono i modi naturali relativi di una stanza.

![amroc](amroc.png)

Piú andiamo avanti con la frequenza, piú si infittiscono le frequenze associate ai modi naturali.
