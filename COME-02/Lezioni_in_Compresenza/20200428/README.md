# Appunti della lezione di Martedí 28 Aprile 2020

### Argomenti della lezione:

- modi di attuazione del pitch tracking
- riflessione sul materiale già elaborato
- metodi di elaborazione del rumore
- approfondimento sul Karplus-Strong
- articolo Pujol

---------

Live-Electronics -> strumenti poco definiti dal punto di vista musicale

Live-Electronics -> sorgente è sempre da un'altra parte

interazione tra sorgente ed elettronica particolare -> cosa più vicina a Live Electronics è la direzione d'orchestra -> come eseguire un certo passaggio

Benedetti-Michelangeli -> interpretazione datata rispetto a Zimmermann

Bolero di Ravel diretto da Toscanini -> direzione datata

Live-Electronics che si fa ora di un pezzo degli anni '90 -> interpretazione diversa -> poichè evolve il modo di vedere e sentire le cose

Paper di Bernardini -> con versione

Trigger di Schmidt -> organizzazione di comparatori -> rilievo dell'ampiezza da decodificare -> tempo in cui l'ampiezza viene rilevata -> SAH -> caratteristico del Sample and hold

---------------

Caso interessante Jacques Linde Risset > traduttrice > voleva tradurre la Divina Commedia

Ruolo del traduttore > attualizzare nel linguaggio (scelta)

Tecnica > opporsi al testo > opposizione preventiva > memorizzare un po' meglio > critica come approccio creativo

Approccio del criticare a priori > per memorizzare e per mantenere alta la guardia

Approccio del buon giornalismo > criticare > approccio produttivo

Pujol -> fotografia

cosa manca all'interno dell'indagine musicale di Pujol??

geografia musicale è figlia di scelte estetiche > con ciò propone un'implicita scelta e consenso

essere avulsi dal pretendere dallo strumento > forzando tecniche, approcci

- solo cultura occidentale??
- quale sarà il futuro dello strumento??
- organizzazione europea del commercio -> 98% mercato chitarre

segnalazione di [Gottardo](https://www.youtube.com/user/gottyboy/videos) -> evoluzione della tecnica chitarristica impressionante

- qualcosa che non possiamo non notare > la chitarra elettrica in Pujol

- scrittura americana > libera tecnica: Blues, Jazz

problemi: chitarra elettrica, asia

europo-centrismo > star attenti al fatto che > in altre culture cambiano le funzioni della musica

Bernardini: cultura indiana > funzione della musica prettamente rituale > certo tipo di regole > funzione speculativa > musica indiana colonalizzata dalla funzione di intrattenimento

generazione giapponese > caratteri cultura anglosassone > Rioji Ikeda

in Giappone > Gagaku, Teatro No

livello di sviluppo di speculazione intellettuale della musica che c'è stato in Occidente è difficile da eguagliare

Aspetto rituale della musica > crollata

_Musica ormai in occidente è intesa come intrattenimento_

molto attenti a confrontare funzione confrontabili

Uso americano della chitarra > aspetto circense

Sassofoni > per far digerire alla musica classica-occidentale le modalità di espressione del Jazz > sassofono Jolivet, Bozard > attegiamento nell'imboccatura chiuso

Lee Coniz, John Zorn > integrare in un linguaggio contemporaneo

strumenti cambiano molto nel tempo > raccogliamo suggestioni che vengono da altre culture, essendo coscenti in quali funzioni avvengono questi cambiamenti > tecniche di tipo circense

per fare qualcosa di contenutisticamente piú profondo > toccare altre corde

Fondamentale di prendere coscienza di questa oggettivizzazione

Viziati da una visione commerciale > i generi non esistono

generi ora servono per taggare

la funzione per cui serve la musica > sono piú neutre rispetto a una visone del mondo, a un'etica

Organizzare musica in base alla funzione > funzioni non sono mai scollate l'una dall'altra

Canto gregoriano > è un canto classificato

fusione tra i generi possibile??

qual'è la funzione che prediligi nel momento che fai una cosa??

scelte in base alla funzione che prediligi > scrivere musica per problemi che ho ad esempi?

modo di percepire acusticamente lo strumento sta cambiando

Aspetto Innovativo per riportare all'ovile della speculazione intellettuale: motivi circensi, di virtuosismo

virtuosismo rocckettaro > virtuosismo che parte dal suonare > aspetto performativo

approccio al contrario > ragioni > e realizzi un qualcosa

integrare il circo e capire > perchè la scrittura è meccanismo fondamentale di pensiero

Laurie Anderson > spettacoli collezioni > chitarra con manico pieghevole di gomma

iato che passa tra idee e estetica > Estetica è una galassia di idee

passaggio dalla performance > wallin marker brown - origins on music

idea sul ragionare sulle funzioni > poichè scrivi certe cose piuttosto che altre

quando si arriva all'elettronica > lo strumento arriva a una tabula rasa

musica indiana > funzione rituale e non evolve > in luce evoluzione che riguarda l'intonazione

condizionati da ascolto temperato che la sensibilità verso i microtoni è viziata

Harry partch > strumenti a percussione

Mettersi in guardia da elementi che vengono da altre culture e la metto qua in mezzo

non dimenticarsi che siamo occidentali

*lettura e sguardo critico della lettura*

Problema del pitch tracking > orecchio percepisce pitch quando c'è organizzazione armonica del suono

- XCR > funziona bene > quando te indichi alla macchina che c'è un pitch > accordatori
altre tecniche piú lente  

- FFT rilevare picchi e vedere se sono armonico
- autocorrelazione > sliding tra suono e se stesso > non funziona velocemente
- quando il pitch non c'è che succede??

per fare un buon pitch detector > devi dargli la maniera da qui a qui (onset detector, envelope shaper) piú indicazioni vieni a dare al pitch detector piú è accurato

orecchio assoluto > filtri passa banda pre intonati su certe frequenze

Xavier Serra > ha lavorato per la Korg > pitch detector > miscela di tecniche > basato su un sistema temperato

bootlog > analisi di membrane in tempo differito con FFT

copista di Berio > Paul Roberts > orecchio assoluto

ranking > delle frequenze per capire che ci sono delle componenti armoniche organizzate e ne rilevi lo spazio fra loro

distorsioni legate alla scala temperata

pitch-tracking si risolve mischiando le tecniche

Roger Dunnenberg > pitch tracking > riusciva a seguire la partitura > sliding window sulla partitura > mischiare partitura e detection > tracking diviene solido

Massimo del Duca ICMC IRCAM 1984 oscillatore 1ms

Barry Vercoe > score follower e pitch tracker

pitch tracking con suoni molti addomesticati

- sonuus I2M > pitch detector note midi > buona capacità di detecting
