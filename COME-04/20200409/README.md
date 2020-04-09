# Appunti della lezione di Giovedi 4 Aprile 2020

Cuffie consigliate:
- https://www.thomann.de/it/beyerdynamic_dt990pro.htm
- https://staxheadphones.com/
- https://www.thomann.de/it/sennheiser_hd_650_new_version_2019.htm?glp=1&gclid=EAIaIQobChMI4aqCjr3b6AIVDbDtCh3_1AL_EAQYASABEgIPGvD_BwE

__________

domande:
- grafico fig.11 pagina 10 dispensa ESE 01-11![Grafico_risposta_percettiva_suoni_posteriori]()
- grafico BBC studio sulla percezione a farfalla > studio fatto su un campione di persone che ci descrive: attraverso le circonferenze la differenza in dB della percezione del suono
- farfallone rosso, come noi percepiamo il suono in base al posizionamento degli altoparlanti
__________

### Dispensa ESE 02-11

La scorsa volta abbiamo visto sistemi molto rigidi, standardizzati e brevettati come Dolby, Sony THX.

Verso un altro fronte si spostó la ricerca di Michael Gerzon(matematico e teorico della fisica e meccanica quantistica)

Michael Gerzon cercó di superare la stereofonia che puó esser considerata limitata nella fedeltà della riproduzione, efficace al 100% solamente in cuffia

La ripresa stereofonica inoltre poteva avere carenze spaziali ed essendo planare, restituiva solamente qualitativamente e spazialmente i luoghi

Primi studi che Gerzon cercó, come appassionato di audio, sistema di ascolto quadricanale, dove veniva riprodotta una registrazione stereofonica con 4 altoparlanti posizionati in un modo specifico![quadrifonia_gerzon](https://github.com/SMERM/BN-Tedesco/blob/master/COME-04/20200409/quadrifonia_gerzon.png)

Pensò inoltre ad un altro sistema a 2 canali, ![tecnica_ambiofonica](https://github.com/SMERM/BN-Tedesco/blob/master/COME-04/20200409/tecnica_ambiofonica.png), tecnica con 2 microfoni a figura otto spaziati, questo sistema viene usato nel software dei televisori, stereofonia simulata con altoparlanti molto vicini

[Sito dedicato all'Ambiphonic](https://www.ambiophonics.org/)

Ambiophonic realizzato con speaker molto vicini

plugin e software open source che simulano la stereofonia con speaker vicina una all'altra> e non c'è perdita e non c'è l'effetto precedenza, spostandosi rimane la posizione stereofonica del suono

Dolby Atmos del cinema è basato sulle tecnologie dell'Ambisonic realizzato da Gerzon e non ascolto

Brevetti Dolby sono tutti secretati

Codifica ambiophonic con [software](https://www.ambiophonics.org/pc-mobile-applications)

[AudioMulch](http://www.audiomulch.com/) software usato per synth e DSP

Gerzon abbandona l'ambiphonic ed ha l'intuazione dell'Ambisonic, da matematico, applicazione della teoria matematica, partendo dall'impianto matematico di Blumlein(che spiegò matematicamente le curve polari dei microfoni), i diagrammi polari hanno una loro funzione mtematica che li descrive

Files in formato [grapher](https://support.apple.com/it-it/guide/grapher/gcalb3dec608/mac) per macos
[cardiode](https://github.com/SMERM/BN-Tedesco/blob/master/COME-04/20200409/cardioide.gcx)
[cardiode_sferico](https://github.com/SMERM/BN-Tedesco/blob/master/COME-04/20200409/cardiode_sferico.gcx)

4 figure polari sovrapposte in una sfera, direzione angolare del suono, senza distanza, la codifica Ambisonic, non ci da informazioni sull'angolazione ma non la distanza

Ambisonic tiene conto solo della direzione angolare del suono

Ho queste forme e gli do un nome:
- componente x: avanti dietro
- componente y: sinistra e destra
- componente z: alto e basso

solo con componenti x,y,x abbiamo la direzione -> con componente w, suono a sempre una parte omnidirezionale del suono
- componente w: diminuire e aumentare la direzionalità del suona, vi è un massimo per la componente che è 0,707

raffinatezza fino a un certo grado dell'angolazione del suono, ambisonic di Primo Ordine

Ambisonic di secondo e terzo ordine > equazioni sferiche piú complesse che indicano una direzionalità

con le componenti w,x,y,z sono 4 tracce che contengo la direzione angolare di un suono,  ma come funziona la decodifica?

[decodifica_ambisonic](https://github.com/SMERM/BN-Tedesco/blob/master/COME-04/20200409/decodifica_ambisonic.png)

angolo tetha:angolo di scostamento orizzontale
angolo phi:angolo di scostamento verticale

Gerzon con Ambisonic posso avere altoparlanti posizionati in modi diversi, e posso diffondere il suono indipendentemente da dove sono posizionati gli altoparlanti

realizzazione con un microfono reale dell'Ambisonic > realizza un array microfonico con 4 capsule microfoniche cardiodi > microfono tetraedrico(A-format) > 4 microfoni cardiodi collocati sulle facce di un tetraedro > ricavo dei microfoni a figura-8, sommando e sottraendo fronti d'onda dei microfoni

[Microfono Rode Soundfiels](https://www.thomann.de/it/rode_nt_sf1.htm)

omni=w=0.5(LFU+LBD+RFD+RBU)
x=

scalata di 0.5 per avere pressione totale all'interno di 1

Ambisonic vero e proprio Gerzon lo chiama Ambisonic B-format:w,x,y,z

mentre il suono che viene registrato dai microfoni è chiamato A-format

formula dell'A-format è solo teorica, quindi dato che ho microfoni non applicati nello stesso punto, poichè suono arriva ritardato alle varie capsule, e dunque subisce un filtraggio, quindi bisogna applicare un filtraggio che va ricompensare comb filtering che vengono realizzati dagli scostamenti della capsula

Dispensa fino alla codifica dell'A-format

formule associate con disegnino 
