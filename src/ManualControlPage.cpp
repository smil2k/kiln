/*
 * All rights reserved.
 */

/*
 * File:   ManualControlPage.cpp
 * Author: smil
 *
 * Created on January 1, 2017, 8:04 PM
 */

#include "ManualControlPage.h"
#include "common.h"
#include "Thermocouple.h"

void ManualControlPage::DoDraw() {
  char line[20];
  uint8_t error = thermocouple.GetReadError();

  lcd.setCursor(0, 0);
  if (error) {
    lcd.print("TmERR = ");
    lcd.print(error, BIN);
  } else {
    sprintf(line, "I=%3d.%02d C=%3d.%02d ",
            (int) thermocouple.GetColdJunctionTemperature(),
            (int) (thermocouple.GetColdJunctionTemperature()*100.0) % 100,
            (int) thermocouple.GetTemperature(),
            (int) (thermocouple.GetTemperature()*100.0) % 100);
    lcd.print(line);
  }

  lcd.setCursor(0, 1);

  if (dutyMode) {
    lcd.print("Duty = ");
    lcd.print(heater.Duty());
  } else {
    lcd.print("Temp = ");
    lcd.print(heater.Target());
  }
}

void ManualControlPage::ButtonUp() {
  if (dutyMode) {
    uint8_t duty = heater.Duty();
    if (duty > 95) {
      duty = 100;
    } else {
      duty += 5;
    }
    heater.ManualControl(duty);
  } else {
    double target = heater.Target();
    if (target > 1200-10) {
      target = 1200;
    } else {
      target += 10;
    }

    heater.AutoControl(target);
  }
}

void ManualControlPage::ButtonDown() {
  if (dutyMode) {
    uint8_t duty = heater.Duty();
    if (duty < 5) {
      duty = 0;
    } else {
      duty -= 5;
    }
    heater.ManualControl(duty);
  } else {
    double target = heater.Target();
    if (target < 10) {
      target = 0;
    } else {
      target -= 10;
    }

    heater.AutoControl(target);
  }
}

void ManualControlPage::ButtonRight() {
  dutyMode = !dutyMode;

  if (dutyMode) {
    heater.ManualControl( heater.Duty() );
  } else {
    heater.AutoControl( heater.Target() );
  }
}
