/*
 * All rights reserved.
 */

#include "Heatelement.h"
#include "hw/Thermocouple.h"
#include "hw/heater.h"

void SetupHeater(uint8_t pin) {
}

void ControlHeater(uint8_t pin, bool heat) {
}

Thermocouple::Thermocouple(int8_t sclk, int8_t miso, int8_t cs) :
sclk(sclk), cs(cs), miso(miso), readTimer(1000, 1) {
}

double Thermocouple::GetColdJunctionTemperature() {
  return 24;
}

uint8_t Thermocouple::GetReadError() {
  return 0;
}

double Thermocouple::GetTemperature() {
  return 23;
}

void Thermocouple::Loop() {
}

