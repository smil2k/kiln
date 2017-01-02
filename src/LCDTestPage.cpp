/*
 * All rights reserved.
 */

/*
 * File:   LCDTestPage.cpp
 * Author: smil
 *
 * Created on January 2, 2017, 5:54 PM
 */

#include "LCDTestPage.h"
#include "common.h"

void LCDTestPage::DoDraw() {
  char line[4];
  sprintf(line, "idx=%03d ", index);
  lcd.print(line);

  for (int i = 0; i < 11; i++) {
    lcd.print((char) (index + i));
  }

  lcd.setCursor(0,1);

  for (int i = 0; i < 19; i++) {
    lcd.print((char) (index + i + 11));
  }

}

void LCDTestPage::ButtonDown() {
  index += 30;
}

void LCDTestPage::ButtonUp() {
  index -= 30;
}

