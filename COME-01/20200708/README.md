# Appunti della lezione di Mercoledí 8 Luglio 2020

- Input VCS3 caratteristiche
- appunti sul riverbero

_______

Filtri TPT -> filtri che mantengono la topologia analogica -> che mantengono in dominio digitale il diagramma analogico

_______

### Matrice

Oggetto che useremo è il _checkbox_ che servirà per realizzare le connessioni all'interno della matrice.

```
import("stdfaust.lib");

switch = checkbox("in") : si.smoo;

process = switch;
```

Ora per realizzare il sistema modulare dobbiamo usare un tot di oggetti.

Ora abbiamo lo switch che accende l'entrata, quindi abbiamo bisogno di dire allo switch che ogni volta che cambia il numero dell'entrata deve cambiare anche l'etichetta, bottone inx deve cambiare l'etichetta.
```
import("stdfaust.lib");

switch(in) = checkbox("IN %3inn") : si.smoo
    with{
     inn = in+(1);
};
process = switch(18);
```

Ora abbiamo realizzato il primo bottone che cambia numero progressivamente

```
import("stdfaust.lib");

//switch integrato
switch(in) = checkbox("IN %3inn") : si.smoo
    with{
     inn = in+(1);
};

//gruppo di switches per l'uscita di una colonna
outcol(in,col) = vgroup("OUT %3coln", par(in, in, *(switch(in)))) :> _
    with{
        coln = col+(1);
};

process = outcol(16,0);
```

Adesso abbiamo la prima colonna della matrice per le uscite.

```
import("stdfaust.lib");

//switch integrato
switch(in) = checkbox("IN %3inn") : si.smoo
    with{
     inn = in+(1);
};

//gruppo di switches per l'uscita di una colonna
outcol(in,col) = vgroup("OUT %3coln", par(in, in, *(switch(in)))) :> _
    with{
        coln = col+(1);
};


matrix(in,out) = hgroup("MATRIX %in x %out", si.bus(in) <: par(out, out, outcol(in,out)));

process = matrix(16,16);
```
Abbiamo dunque realizzato l'ultima funzione necessaria ovvero quella denominata _matrix_, che realizza la vera e propria matrice con 16 entrate e 16 uscite.

Ora va realizzata la rete di feedback e considerando che la nostra matrice è ad un campione di ritardo.

L'oggetto _si.bus_ serve per dare le stesse identiche entrate a tutte le uscite.

Per una visione mixer globale di _Risonananze Erranti_ ad esempio, una visione a matrice è molto utile per avere una visione globale.

Lezioni in più per fine Luglio??
