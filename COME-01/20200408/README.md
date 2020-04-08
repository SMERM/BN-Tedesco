# Appunti lezione Mercoledí 8 Aprile 2020

- Raspberry Pi linkati > per realizzare un mixer ed una matrice linkata

- in libreria vanno solo oggetti che producono suono

- [matrice per Raspberry](https://learn.adafruit.com/untztrument-trellis-midi-instrument)

OSC1 del VCS3 realizzato la lezione precedente

`vcs3osc1(freq) = sine, saw
  with{
    step = freq/ma.SR;
    phasor(step) = +(step)~ ma.decimal;
    sine = sin(phasor(step)*2*ma.PI);
    saw = phasor(step)-(0.5);
};`
