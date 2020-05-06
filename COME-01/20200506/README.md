# Appunti della lezione di Mercoledi 6 Maggio 2020

lezioni in presenza non potranno ripartire prima di Settembre

e da Settambre si ripartirà con la modalità a distanza

Lauree ed esami > in presenza > conservatori termo regolatori

lezioni necessariamente in presenza > strumento > lezioni individuali
_____  
2/3 frequenze importanti

infernal machine > lavorava a 50kHz di fre > macchina con cui Nono faceva Delay phaser e riverberazione

abbiamo quindi dati acustici di ciò che riusciva a fare con l'Infernal machine

phaser > delay molto piccolo + uscita segnale originale > cancellazione > modifichi cancellazione di fase

tempo minimo di ritardo dell'infernal machina 40 microsecondi 0,04 secondi

ritardo di 2 campioni (0.04/1000)x50000=2

a 2 campioni di ritardo > che cancella le fasi

il punto della valle > 0.04 microsecondi e non campioni e usi come freq di sviluppo una diversa da 50000 > effetto

equazione del filtro

freq di campionamento a cui stiamo progettando è cruciale per ottenere il timbro da volere

progettazione > importante

a 44100 non puoi fare un allpass a 0.04 microsecondi

notch > delay frazionario > di max non è uguale a infernal machine

1x50000=0.0004 > periodo

(0.04/1000)x44100=??

Infernal Machine > ritardo minimo sono 40 microsecondi > 2 campioni

controllo in banda polinomiale di JOS > applicato a wsine

1. JOS > introduce rumore
2. gestione dell'aliasing

valore dell'offset del wsine

filtri digitali usati per fare mastering dei CD > realizzati da Gerzon > per evitare l'effetto foldback quando si usano i cd

rx filtro cd  

filtri a muro > wall filter > default per fare mastering a 44100 > filtro a muro come è fatto??

ragionare come se fossimo ad un mastering ad altissima qualità > filtraggio ad altissima risoluzione per evitare che filtro vada a sbattere a nyquist

scegliamo un filtro ottimo a muro > e mettendolo oltre nyquist > lavoriamo sempre

filtro > che stabilisca un criterio di elaborazione dell'analogico > portando la macchina a lavorare a una definizione piú vicina possibile alla velocità di corrente

wap gui builder >>

a 192000 hz > diminuiscono i canali > perchè utilizza i convertitori accoppiati

routing dentro a RME usano FPGA > interno allo stesso dsp

con qt non funziona un pomello esponeziale

a compilare con faust > a freq di campionamento alte > freq la cambia l'applicazione > ma matematica interna rimane uguale

-double >> compilazione in double precision

ordine 4 non possiamo permettercelo

mettere appunto il coefficente da poter ricavare dal 2/π con cui rompiamo l'onda

- cercare documentazione > filtri anti aliasing

non ha molto senso > sbatterci con i controlli in banda
