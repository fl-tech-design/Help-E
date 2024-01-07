#include <Arduino.h>
#include <Wire.h>

#include "led_func.h"
#include "robot_server.h"

/* definition des Webservers */
ESP8266WebServer server(80); // Definition der server-Variable hier

/* definieren von i2c*/
const byte NANO_ADDR = 0x42;

/* definieren des Shift-Register 74HC595 vom Wemos D1 mini. */
const int X30_2_SCLK = D8;
const int X30_4_RCLK = D6;
const int X30_6_SER = D3;
byte led_register = 0; // Hier speichern wir den Zustand der acht LEDs

/* definieren der verschiedenen Staten der App */
int led_state = LED_OFF;
int light_state = LIGHT_OFF;

/* Setup code*/
void setup()
{
  pinMode(X30_4_RCLK, OUTPUT);
  pinMode(X30_6_SER, OUTPUT);
  pinMode(X30_2_SCLK, OUTPUT);

  delay(1000);
  Serial.begin(9600);

  Wire.begin();
  setupWebServer();

  setAllLedsOn();
  delay(1000);
  lightOff();
}

/* loop */
void loop()
{
  server.handleClient();
  if (led_state == LED_ON && light_state == LIGHT_ON)
  {
    setAllLedsOn();
  }
  else if (led_state == LED_ON && light_state == BLINK_R_LIGHT_ON)
  {
    blinkerRightLightOn();
  }
  else if (led_state == LED_OFF && light_state == BLINK_R_LIGHT_OFF)
  {
    blinkerRightLightOff();
  }
  else if (led_state == LED_ON && light_state == BLINK_L_LIGHT_ON)
  {
    blinkerLeftLightOn();
  }
  else if (led_state == LED_OFF && light_state == BLINK_L_LIGHT_OFF)
  {
    blinkerLeftLightOff();
  }
  else
  {
    Serial.println("else");
    lightOff();
  }
}