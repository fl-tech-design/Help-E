// led_func.cpp
#include <Wire.h>

#include "led_func.h"

unsigned long previousMillis = 0;
const long ledToggleInterval = 500; // Intervall für das Umschalten der LEDs in Millisekunden

/* Wire i2c sendfunction */
void wireSend(int addr, char command)
{
    Wire.beginTransmission(addr);
    Wire.write(command);
    Wire.endTransmission();
}

void updateShiftRegister()
{
    digitalWrite(X30_4_RCLK, LOW);
    shiftOut(X30_6_SER, X30_2_SCLK, LSBFIRST, led_register);
    digitalWrite(X30_4_RCLK, HIGH);
}

void lightOff()
{
    led_register = ALL_LED_OFF;
    updateShiftRegister();
    wireSend(NANO_ADDR, '0');
}
void setAllLedsOn()
{
    led_register = ALL_LED_ON;
    updateShiftRegister();
    wireSend(NANO_ADDR, '1');
}
void blinkerLeftLightOff()
{
    unsigned long currentMillis = millis();

    if ((currentMillis / 600) % 2 == 0)
    {
        led_register = LIGHT_OFF_INDI_L_ON;
        updateShiftRegister();
        wireSend(NANO_ADDR, '2');
    }
    else
    {
        led_register = ALL_LED_OFF;
        updateShiftRegister();
        wireSend(NANO_ADDR, '0');
    }
}
void blinkerLeftLightOn()
{
    unsigned long currentMillis = millis();

    if ((currentMillis / 600) % 2 == 0)
    {
        led_register = LIGHT_ON_INDI_L_ON;
        updateShiftRegister();
        wireSend(NANO_ADDR, '3');
    }
    else
    {
        led_register = LIGHT_ON_INDI_L_OFF;
        updateShiftRegister();
        wireSend(NANO_ADDR, '4');
    }
}
void blinkerRightLightOff()
{
    unsigned long currentMillis = millis();

    if ((currentMillis / 600) % 2 == 0)
    {
        led_register = LIGHT_OFF_INDI_R_ON;
        updateShiftRegister();
        wireSend(NANO_ADDR, '7');
    }
    else
    {
        led_register = ALL_LED_OFF;
        updateShiftRegister();
        wireSend(NANO_ADDR, '0');
    }
}
void blinkerRightLightOn()

{
    unsigned long currentMillis = millis();

    if ((currentMillis / 600) % 2 == 0)
    {
        led_register = LIGHT_ON_INDI_R_ON;
        updateShiftRegister();
        wireSend(NANO_ADDR, '5');
    }
    else
    {
        led_register = LIGHT_ON_INDI_R_OFF;
        updateShiftRegister();
        wireSend(NANO_ADDR, '6');
    }
}
