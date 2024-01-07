// robot_server.cpp
#include <Wire.h>
#include "robot_server.h"

IPAddress apIP(192, 168, 1, 1); // Setze hier die gewünschte feste IP-Adresse ein

const char *ssid = "Help-I";        // Setze hier deinen gewünschten SSID-Namen ein
const char *password = "123123123"; // Setze hier dein gewünschtes Passwort ein

void setupWebServer()
{
    // Starte den Access Point mit fester IP-Adresse
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP(ssid, password);

    server.on("/", HTTP_GET, handleRoot);
    /* handle light commands */
    server.on("/all_on", HTTP_GET, handleAllLedOn);    // Neue Route für I2C-Scannen
    server.on("/all_off", HTTP_GET, handleAllLedOff);  // Neue Route für I2C-Scannen
    server.on("/blink_R", HTTP_GET, handleBlinkRight); // Neue Route für I2C-Scannen
    server.on("/blink_L", HTTP_GET, handleBlinkLeft); // Neue Route für I2C-Scannen

    /* handle other commands*/
    server.on("/i2c_scan", HTTP_GET, handleI2CScan); // Neue Route für I2C-Scannen

    server.begin();
}

void handleRoot()
{
    String message = "Welcome to Robot Control!\n";
    message += "To turn off LEDs: /all_off\n";       // wire cmd = 0
    message += "To turn on LEDs: /all_on\n";         // wire cmd = 1
    message += "To turn on indicator R: /blink_R\n"; // wire cmd = 1
    message += "To turn on indicator R: /blink_L\n"; // wire cmd = 1

    message += "For scannig all i2c devices: /i2c_scan\n";
    server.send(200, "text/plain", message);
}
void handleAllLedOn()
{
    if (led_state == LED_OFF)
    {
        light_state = LIGHT_ON;
        led_state = LED_ON;
    }
    else
    {

    light_state = LIGHT_ON;
    }
}
void handleAllLedOff()
{
    if (led_state == LED_OFF)
    {
        light_state = LIGHT_OFF;
    }
    else
    {
        light_state = LIGHT_OFF;
        led_state = LED_OFF;
    }
}
void handleBlinkRight()
{
    if (led_state == LED_OFF)
    {
        light_state = BLINK_R_LIGHT_OFF;
    }
    else
    {
        light_state = BLINK_R_LIGHT_ON;
    }
}
void handleBlinkLeft()
{
    if (led_state == LED_OFF)
    {
        light_state = BLINK_L_LIGHT_OFF;
    }
    else
    {
        light_state = BLINK_L_LIGHT_ON;
    }
}

void handleI2CScan()
{
    String i2cDevices = "I2C Devices:\n";

    Wire.begin();
    for (byte i = 8; i < 120; i++) // Standard I2C-Adressbereich
    {
        Wire.beginTransmission(i);
        byte error = Wire.endTransmission();

        if (error == 0)
        {
            i2cDevices += "Device found at address 0x" + String(i, HEX) + "\n";
        }
        else if (error == 4)
        {
            i2cDevices += "Unknown error at address 0x" + String(i, HEX) + "\n";
        }
    }

    server.send(200, "text/plain", i2cDevices);
}
