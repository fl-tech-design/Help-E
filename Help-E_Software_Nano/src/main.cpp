#include <Arduino.h>
#include <Wire.h>

#include "led_func.h"
#include "beep_sounds.h"

/* i2c configurations*/
const byte NANO_ADDR = 0x42; // I2C Adresse des zweiten 74HC595

/* definieren des Shift-Register 74HC595 vom Arduino Nano. */
const int X30_4_RCLK = 7; // RCLK
const int X30_2_SCLK = 8; // SRCLK
const int X30_6_SER = 4;  // SER
byte led_register = 0;    // Hier speichern wir den Zustand der acht LEDs

/* definieren der verschiedenen Staten der App */
int led_state = LED_OFF;
int light_state = LIGHT_OFF;

/* declaration of methods*/
void receiveEvent(int howMany);

void setup()
{
  Serial.begin(9600);
  Wire.begin(NANO_ADDR);
  Wire.onReceive(receiveEvent); // Funktion für den Empfangs-Event registrieren

  pinMode(X30_4_RCLK, OUTPUT);
  pinMode(X30_2_SCLK, OUTPUT);
  pinMode(X30_6_SER, OUTPUT);

  setAllLedsOn();
  delay(1000);
  setAllLedOff();
  startBeep();
}

void loop()
{
}

void receiveEvent(int howMany)
{
  while (Wire.available())
  {
    char command = Wire.read(); // Befehl lesen

    // Funktion basierend auf dem empfangenen Befehl auslösen
    if (command == '0')
    {
      led_register = ALL_LED_OFF;           // schaltet alle LED aus
      updateShiftRegister();
    }
    if (command == '1')
    {
      led_register = ALL_LED_ON;            // schaltet alle Led ein
      updateShiftRegister();
    }
    if (command == '2')
    {
      led_register = LIGHT_OFF_INDI_L_ON;   // schaltet den linken Blinker ein bei ausgeschaltenem Licht.
      updateShiftRegister();
    }
    if (command == '3')
    {
      led_register = LIGHT_ON_INDI_L_ON;    // schaltet den linken Blinker ein bei eingeschaltenem Licht.
      updateShiftRegister();
    }
    if (command == '4')
    {
      led_register = LIGHT_ON_INDI_L_OFF;   // schaltet den linken Blinker aus bei eingeschaltenem Licht.
      updateShiftRegister();
    }
    if (command == '5')
    {
      led_register = LIGHT_ON_INDI_R_ON;    // schaltet den rechten Blinker ein bei eingeschaltenem Licht.
      updateShiftRegister();
    }
    if (command == '6')
    {
      led_register = LIGHT_ON_INDI_R_OFF;   // schaltet den rechten Blinker aus bei eingeschaltenem Licht.
      updateShiftRegister();
    }
    if (command == '7')
    {
      led_register = LIGHT_OFF_INDI_R_ON;   // schaltet den linken Blinker ein bei ausgeschaltenem Licht.
      updateShiftRegister();
    }
  }
}