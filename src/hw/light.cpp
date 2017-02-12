/*
 * All rights reserved.
 */

/*
 * File:   light.cpp
 * Author: smil
 *
 * Created on January 1, 2017, 7:24 PM
 */
#include <Arduino.h>
#include "light.h"


static long lightsUntil;
static int keep;
static uint8_t backlightPin;

void setupLight(uint8_t _backlightPin, int _startup = 0, int _keep = 10000) {
  lightsUntil = millis() + _startup;
  keep = _keep;
  backlightPin = _backlightPin;
  pinMode(_backlightPin, OUTPUT);
}

void turnOnLight() {
  lightsUntil = millis() + keep;
}

void lightLoop() {
  //digitalWrite(backlightPin, millis() > lightsUntil ? LOW : HIGH);
}

