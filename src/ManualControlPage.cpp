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
  lcd.setCursor(0, 0);
  lcd.print(" I = ");
  lcd.print(thermocouple.GetColdJunctionTemperature());
  lcd.print("  ");

  double c = thermocouple.GetTemperature();

  lcd.setCursor(0, 1);

  if (isnan(c)) {
    lcd.print(" E = ");
    lcd.print(thermocouple.GetReadError());
  } else {
    lcd.print(" C = ");
    lcd.print(c);
  }

  lcd.print("  ");
}

void ManualControlPage::ButtonUp() {

}

void ManualControlPage::ButtonDown() {

}

void ManualControlPage::ButtonRight() {

}

void ManualControlPage::DoBackgroundLoop() {

}
