// led_func.cpp
#include "led_func.h"


void updateShiftRegister()
{
    digitalWrite(X30_4_RCLK, LOW);
    shiftOut(X30_6_SER, X30_2_SCLK, LSBFIRST, led_register);
    digitalWrite(X30_4_RCLK, HIGH);
}


void setAllLedOff()
{
    led_register = 0;
    updateShiftRegister();
}

void setAllLedsOn()
{
    led_register = 0xFF;
    updateShiftRegister();
}

void blinkerLeftLightOff()
{
    unsigned long currentMillis = millis();

    if ((currentMillis / 600) % 2 == 0)
    {
        led_register = LIGHT_OFF_INDI_L_ON;
        updateShiftRegister();
    }
    else
    {
        led_register = ALL_LED_OFF;
        updateShiftRegister();
    }
}
void blinkerLeftLightOn()
{
    unsigned long currentMillis = millis();

    if ((currentMillis / 600) % 2 == 0)
    {
        led_register = LIGHT_ON_INDI_L_ON;
        updateShiftRegister();
    }
    else
    {
        led_register = LIGHT_ON_INDI_L_OFF;
        updateShiftRegister();
    }
}
void blinkerRightLightOff()
{
    unsigned long currentMillis = millis();

    if ((currentMillis / 600) % 2 == 0)
    {
        led_register = LIGHT_OFF_INDI_R_ON;
        updateShiftRegister();
    }
    else
    {
        led_register = ALL_LED_OFF;
        updateShiftRegister();
    }
}
void blinkerRightLightOn()

{
    unsigned long currentMillis = millis();

    if ((currentMillis / 600) % 2 == 0)
    {
        led_register = LIGHT_ON_INDI_R_ON;
        updateShiftRegister();
    }
    else
    {
        led_register = LIGHT_ON_INDI_R_OFF;
        updateShiftRegister();
    }
}
