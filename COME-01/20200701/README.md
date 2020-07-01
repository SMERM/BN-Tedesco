# Appunti della lezione di Mercoledí 1mo Luglio 2020

[conferenza consigliata da Luca](http://issta.ie)

Lezioni fino a fine Luglio

Tutto ció che è privato forse non è necessario in un qualcosa.

[archiviziane Giuseppe su Zotero](https://www.zotero.org/giuseppesilvi)

_____________

Hacklily aggiungere files a github

in libreria filters oggetti simili a onepole -> con formula con cui si tagliano i cutoff dei onepole

Formula acor che viene usata per il coefficente di taglio corretto

0 padding -> creare uno spazio di shift, di spostamento dell'oggetto sonoro, sposti l'oggetto sonoro con zeri a sinistra e a destra

Zero padding(spostamento nell'asse temporale di un oggetto sonoro) si usa molto per convoluzione ed analisi

tutto in libreria seam.basic.lib

sba.sweep -> sweep di Faust ma corretto

la lsweep -> sweep in audio fino a Nyquist

zsweep -> oggetto identico di zsweep

leggere specifica tastiera vcs3

filtro passa basso come leak-integrator -> che viene smussato a bassa frequenza
----------
si.smoo -> impulso filtrato nel tempo in maniera molto lenta

sostituito si.smoo con nostro integratore, che fa cambiare il calcolo del coefficente, in cui possiamo dare il coefficente a mano con formula corretta per ricavare il punto in cui il filtro perde di 3dB, che nel caso dei filtri di questo tipo dovrebbe andare da 0 a Nyquist

a quale freq il nostro filtro tira fuori freq simili a si.smoo, ovvero a 10Hz

Attenuato a alte frequenze ma non fermato

Aumentare SR -> viene numero piú piccolo

_____________
La matrice se impariamo ad usarla, la possiamo usare successivamente

- filtri
- connessioni
- utilizzo a livello interpretativo

visione mappata che racconta l'intera procedura e ne traccia tutte le possibili connesioni.
