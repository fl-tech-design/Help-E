//beep_sounds.h
#ifndef BEEP_SOUND_H
#define BEEP_SOUND_H

#include <Arduino.h>

const int piezoPin = 2; // Der Pin, an dem der Piezo-Summer angeschlossen ist

const int tone_Bf = 3729;
const int tone_B = 3951;
const int tone_C = 4186;
const int tone_Df = 4435;
const int tone_D = 4699;
const int tone_Ef = 4978;
const int tone_E = 5274;
const int tone_F = 5588;
const int tone_Gf = 5920;
const int tone_G = 6272;
const int tone_Af = 6645;
const int tone_A = 7040;

void startBeep();

#endif
