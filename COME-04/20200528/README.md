# Appunti della lezione di Giovedí 28 Maggio 2020

resistenza e condensatore in serie  -> filtro passa basso

[file spiegazione filtri](https://www.ltpaobserverproject.com/uploads/3/0/2/0/3020041/filtri_passivi.pdf )

in genere in chitarre ->

[convertitore in farad](https://www.translatorscafe.com/unit-converter/IT/electrostatic-capacitance/13-1/microfarad-farad/)

se realizziamo un filtro RC, sapendo la capacità elettrica in Farad -> capiamo la frequenza di taglio del filtro  

Filtro RL al posto della resistenza vi è un'induttanza

Formula filtro RC
![formula_filtro_RC](formula_filtro_RC.png)

1. primo ordine: condensatore e resistore o condesatore e induttanza (2 componenti) -> filtri con la fase piú coerente
2. filtri di secondo ordine ci sono 3 componenti: condensatore, resistore e induttore (3 componenti)
3. filtro di terzo ordine

piú aumenta l'ordine piú aumentano le distorsioni di fase

sia condensatorre che induttore introducono modifiche sulla fase -> sono simili alle linee di ritardo, vantaggio di pendenza piú ripida ma con maggiori problemi in fase

in filtri per crossover -> in genere filtri di primo ordine per non modificare troppo la fase -> la variazione di fase non è la stessa a tutte le frequenze

Delay analogici si fanno in genere con condensatori e induttori

VA -> Visual Analyser -> generatore di segnali

Bug in programma -> white noise non funziona

vediamo il rumore rosa non filtrato sul visualizzatore di spettro

uscita di una scheda audio ha un impedeza di con 600 ohm + 0,022 microfarad -> 900 hz

600 ohm+0,047 microfarad -> 5000 hz

![spettro_senza_condensatore](spettro_senza_condensatore.png)

con 2 condensatori da 0,047 microfarad in serie
![spettro_con_2_condensatori_0,047microfarad_in_parallelo](spettro_con_2_condensatori_0,047microfarad_in_parallelo.png)

potenziometro logaritmico con curva che agisce tutta alla fine -> in genere potenziometro logaritmo ha la sigla che inizia con _b_, esempio di un potenziometro da 10 KOhm _B10K_

Usando un potenziometro come resistenza

![pickuchitarra](single_pu.jpg)

- single coil -> 5000/6000 ohm
- Humbucker 15/16 Kohm  
