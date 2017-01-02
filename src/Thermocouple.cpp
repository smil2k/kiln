/*
 * All rights reserved.
 */

/*
 * File:   Thermocouple.cpp
 * Author: smil
 *
 * Created on January 1, 2017, 8:08 PM
 */

#include <Arduino.h>
#include <util/delay.h>
#include "Thermocouple.h"
#include "Metro.h"

Thermocouple::Thermocouple(int8_t sclk, int8_t miso, int8_t cs) :
sclk(sclk), cs(cs), miso(miso), readTimer(1000, 1) {
  // We drive all three pins in open collector mode, therefore they
  // need an external pull up to 3.3v. Some ten k range.
  pinMode(cs, INPUT);
  pinMode(sclk, INPUT);
  pinMode(miso, INPUT);

  // turn off internal pull up
  // Additionally, this case switching to output mode drives the pin to ground.
  digitalWrite(cs, LOW);
  digitalWrite(sclk, LOW);
  digitalWrite(miso, LOW);
}

double Thermocouple::GetColdJunctionTemperature() {
  uint32_t value = currentValue;

  // ignore bottom 4 bits - they're just thermocouple data
  value >>= 4;

  // pull the bottom 11 bits off
  double internal = value & 0x7FF;
  internal *= 0.0625; // LSB = 0.0625 degrees

  // check sign bit!
  if (value & 0x800)
    internal *= -1;

  return internal;
}

uint8_t Thermocouple::GetReadError() {
  return currentValue & 0x7;
}

double Thermocouple::GetTemperature() {
  uint32_t value = currentValue;
  if (value & 0x7) {
    // Error bits set!
    return NAN;
  }

  // get rid of internal temp data, and any fault bits
  value >>= 18;

  return value * 0.25;
}

void Thermocouple::Loop() {
  if (readTimer.check()) {
    uint32_t d = 0;

    pinMode(sclk, OUTPUT); // Drive it low
    delay(1);

    pinMode(cs, OUTPUT); // Drive it low
    delay(1);

    for (int i = 31; i >= 0; i--) {
      pinMode(sclk, OUTPUT); // Drive it low
      delay(1);
      d <<= 1;
      if (digitalRead(miso)) {
        d |= 1;
      }

      pinMode(sclk, INPUT); // Drive it high
      delay(1);
    }

    pinMode(cs, INPUT); // Tristate : Drive it high (by external pull up!)

    currentValue = d;
  }
}

