// led_func.h
#ifndef LED_FUNC_H
#define LED_FUNC_H

#include <Arduino.h>

/* include controlpins and other stuff from main.cpp */
extern const int X30_4_RCLK;
extern const int X30_6_SER;
extern const int X30_2_SCLK;

extern byte led_register;
extern int led_state;
extern int light_state;

extern const byte NANO_ADDR;

/* enum LedState defines the states of the led to set the shift-register*/
enum LedState
{
    LED_OFF,
    LED_ON,
};

/* enum LightState of controlling the Light of Help-E */
enum LightState
{
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_NORMAL,
    BLINK_R_LIGHT_OFF,
    BLINK_R_LIGHT_ON,
    BLINK_L_LIGHT_OFF,
    BLINK_L_LIGHT_ON

};

/* definieren der Bitmasken für die LED */
// const byte INDI_R_ON_LIGHT_OFF = 0b01000000;     // config Arduino Nano
// const byte INDI_L_ON_LIGHT_OFF = 0b00001000;     // config Arduino Nano

const byte ALL_LED_OFF = B00000000; // config Wemos D1 mini
const byte ALL_LED_ON = B11111111; // config Wemos D1 mini

const byte LIGHT_OFF_INDI_R_ON = B00001100; // config Wemos D1 mini

const byte LIGHT_ON_INDI_R_ON = B11001100;  // config Wemos D1 mini
const byte LIGHT_ON_INDI_R_OFF = B11000000; // config Wemos D1 mini

const byte LIGHT_OFF_INDI_L_ON = B11000000; // config Wemos D1 mini

const byte LIGHT_ON_INDI_L_ON = B11001100;  // config Wemos D1 mini
const byte LIGHT_ON_INDI_L_OFF = B00001100; // config Wemos D1 mini

/* initialize methods of led_func.cpp*/
void updateShiftRegister();

void lightControl();

void blinkerLeftLightOff();
void blinkerLeftLightOn();
void blinkerRightLightOff();
void blinkerRightLightOn();

void setAllLedsOn();
void lightOff();

#endif
