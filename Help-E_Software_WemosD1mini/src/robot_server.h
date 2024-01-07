// robot_server.h
#ifndef ROBOT_SERVER_H
#define ROBOT_SERVER_H

#include <ESP8266WebServer.h>
#include "led_func.h"

extern ESP8266WebServer server;




extern int light_state;

void setupWebServer();
void handleRoot();

void wireSend(int addr, char command);

void handleAllLedOn();
void handleAllLedOff();
void handleBlinkRight();
void handleBlinkLeft();
void handleI2CScan();
#endif
