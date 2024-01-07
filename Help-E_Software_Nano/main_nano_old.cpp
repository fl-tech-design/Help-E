#include "led_func.h"
#include <Wire.h>

#define NANO_ADDR 0x42



const int X30_2_SCLK = 8;
const int X30_4_RCLK = 7;
const int X30_6_SER = 4;

// byte INDI_R = 0b00001100;    config Wemos D1 mini
byte INDI_R = 0b01000000;    // config Arduino Nano
// byte INDI_L = 0b11000000; config Wemos D1 mini
byte INDI_L = 0b00001000;

const int LED_13 = 0;
const int LED_12 = 1;
const int LED_15 = 2;
const int LED_16 = 3;
const int LED_14 = 4;
const int LED_09 = 5;
const int LED_07 = 6;
const int LED_08 = 7;

bool indi_L_active = false;
bool indi_R_active = false;

byte led_register = 0;      // Hier speichern wir den Zustand der acht LEDs

int led_state = LED_ALL_OFF;

void startProcess();
void receiveEvent(int howMany);


void setup() {
    pinMode(X30_4_RCLK, OUTPUT);
    pinMode(X30_6_SER, OUTPUT);  
    pinMode(X30_2_SCLK, OUTPUT);
    pinMode(piezoPin, OUTPUT);

    Serial.begin(9600);

    Wire.begin(NANO_ADDR);
    Wire.onReceive(receiveEvent); // Funktion für den Empfangs-Event registrieren

    startProcess();
}

void loop() {
  ledControl();

}

void startProcess(){
    allLedsOn();
    delay(500);
    allLedsOff();
}
void receiveEvent(int howMany) {
  while (Wire.available()) {
    char command = Wire.read(); // Befehl lesen

    // Funktion basierend auf dem empfangenen Befehl auslösen
    if (command == '0') {
      led_state = LED_ALL_OFF;
    }
    if (command == '1') {
      led_state = LED_ALL_ON;
    }
    if (command == '2') {
      led_state = LED_ALL_BLINK;
    }
    if (command == '3') {
      led_state = LED_TURN_SIGNAL_L;
    }
    if (command == '4') {
      led_state = LED_TURN_SIGNAL_R;
    }
  }
}