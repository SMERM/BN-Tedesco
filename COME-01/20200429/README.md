# Appunti della lezione di Mercoledí 29 Aprile 2020

potremmo sostiture il fasore del osc1 con _os.lf_sawpos_

fasore preciso ed il piú economico possibile

```
import("stdfaust.lib");
phasor(f) = (f/ma.SR) : (+ : ma.decimal)~_;
sine = sin(_*2*ma.PI);
min05 = _<(0.5);
mag05 = _>(0.5);
process = phasor(100) <: _, // phasor
                         sine, // sinusoidal
                         min05*(2)-(1), // square pos
                         mag05*(2)-(1), // square neg
                         *(2)-(1), // saw a
                         *(-2)+(1), // saw d
                         ((((*(2)-(1))*min05)+((*(-2)+(1))*mag05))*2)+1; // triangular
```

priorità > decisioni logiche:

- feedback > devia il flusso audio _~_ > priorità maggiore degli operatori matematici
- priorità in termini di descrizione diagrammi a blocchi

#### Priorità logica degli operatori in Faust:
(descrizione logica e descrizione di un flusso, sintassi deve tener conto che genera, prima di fare processo genera un tragitto, un percorso logico, esso ha la priorità sul calcolo vero e proprio, come ad esempio FPGA>come RME somme, operazioni )

![Priorità_logica_degli_operatori_in_Faust](COME-01/20200429Priorità_logica_degli_operatori_in_Faust.png)

Dopo esse vengono funzioni matematiche

pi greco in double _PI = 3.1415926535897932385_
