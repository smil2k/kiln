/*
 * All rights reserved.
 */

/*
 * File:   Heatelement.cpp
 * Author: smil
 *
 * Created on January 2, 2017, 2:51 PM
 */

#include "common.h"
#include "Heatelement.h"
#include "hw/heater.h"

Heatelement::Heatelement(int pin) :
pin(pin),
heatCheck(100, 1),
autoCheck(1000, 1) {
  SetupHeater(pin);
  ControlHeater(pin, false);
}

void Heatelement::AutoControl(double target) {
  this->target = target;
  this->targetLock = true;
}

void Heatelement::ManualControl(uint8_t duty) {
  this->targetLock = false;
  SetDuty(duty);
}

void Heatelement::SetDuty(uint8_t duty) {
  if (this->duty != duty) {
    this->totalSlots = 0;
    this->heatedSlots = 0;
    this->duty = duty % 101;
  }
}

void Heatelement::KeepDuty() {
  if (heatCheck.check()) {
    switch (duty) {
      case 0:
        ControlHeater(pin, false);
        return;
      case 100:
        ControlHeater(pin, true);
        return;
      default:
        bool heat = false;

        if (totalSlots == 0) {
          heatedSlots = 0;
        }
        totalSlots++;

        if (heatedSlots == 0) {
          heat = true;
        } else {
          heat = ((double) heatedSlots / (double) totalSlots) * (double) 100.0 <= (double) duty;
        }

        if (heat) {
          heatedSlots++;
        }

        ControlHeater(pin, heat);
    }
  }
}

void Heatelement::Loop() {
  KeepDuty();

  if (targetLock) {
    if (thermocouple.GetReadError() == 0) {
      int diff = thermocouple.GetTemperature() - target;

      if (diff > 10) {
        SetDuty(100);
      } else if ( diff < 0 ) {
        SetDuty(0);
      } else {
        SetDuty( diff * 10);
      }

    } else {
      SetDuty(0);
    }
  }
}
