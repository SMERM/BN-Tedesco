# Appunti della lezione di Giovedí 9 Luglio 2020

Oggi vediamo cos'è un overdrive e la differenza tra distorsore, overdrive e Fuzz

Effetti che sono sovrapponibili come suono, ma il circuito e la maniera in cui lavora è qualcosa di totalmente diverso

### Distorsore

Caratteristica di un comportamento non usuale di questi componenti

![transistorcomp](transistorcomp.png)

#### Comportamento elettrico

Fino a un tot di volt il transistor è un moltiplicatore, superato un certo voltaggio si supera la soglia di lavoro del transistor, e diminiuisce l'amplificazione e il transistor non amplifica piú, si raggiunge dunque il punto di saturazione. Il semiconduttore superato quel certo voltaggio si avrà sempre lo stesso valore in uscita, anche la corrente superato un certo punto rimane orizzontale.

#### Comportamento sonoro

Se il picco della sinusoide supera la soglia di distorsione, viene tagliata la parte di sinusoide che supera di saturazione, il segnale viene _pettinato_, il segnale in piú viene tagliato, questa è la vera e propria distorsione.

![distsinu](distsinu.png)

Il distorsore fa lavorare un transistor per far squadrare il segnale.

Ci sono poi delle varianti a questa distorsione.

Il punto da cui il transistor squadra la forma d'onda è chiamato _soglia di saturazione_

Comportamento di questo tipo, l'onda quadra nel punto in cui il segnale cambia livello abbiamo una frequenza d'onda.

In un segnale ciclico l'ampiezza varia nel tempo, mentre in un segnale sinusoidale l'ampiezza varia continuamente.

L'onda quadra reale ha piú una parte tonda orizzontalmente che perfettamente squadrata.

Il distorsore fa lavorare oltre il livello di amplificazione del transistor.

Andando a vedere i datasheet dei transistor troviamo i dati che indicano questa soglia di distorsione, [sito con molti transistor](alltransistors.com)

I transistor non si usano solo in audio, ma anche ad esempio in radio
