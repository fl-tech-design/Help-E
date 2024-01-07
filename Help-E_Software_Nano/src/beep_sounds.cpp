// beep_sounds.cpp
#include "beep_sounds.h"

void startBeep(){
    tone(piezoPin, tone_G, 500);
    delay(1000);
    tone(piezoPin, tone_G, 500);
}