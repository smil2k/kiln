/*
 * All rights reserved.
 */

#include "heater.h"

void SetupHeater(uint8_t pin) {
  pinMode(pin, OUTPUT);
}

void ControlHeater(uint8_t pin, bool heat) {
  digitalWrite(pin, heat ? HIGH : LOW);
}
