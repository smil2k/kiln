/*
 * All rights reserved.
 */

/*
 * File:   ButtonTestPage.cpp
 * Author: smil
 *
 * Created on January 2, 2017, 6:32 PM
 */

#include "ButtonTestPage.h"

ButtonTestPage::ButtonTestPage(MenuPage* parent) : Page(parent) {
  parent->AddMenu("Button Test", this);
}

void ButtonTestPage::DoDraw() {
  lcd.print("Press L ");
  lcd.print(10-left);
  lcd.print("x to exit");
  lcd.setCursor(0,1);
  lcd.print(pressed);
}

void ButtonTestPage::Activate() {
  memset(pressed, 0, 20);
  cursorPointer=pressed;
  left=0;
}


void ButtonTestPage::AddPressed(char btn) {
  *cursorPointer = btn;
  cursorPointer++;

  if (cursorPointer - pressed > 19) {
    memset(pressed, 0, 20);
    cursorPointer = pressed;
  }
}

void ButtonTestPage::ButtonLeft() {
  AddPressed('L');
  left++;

  if ( left == 10 ) {
    Page::ButtonLeft();
  }
}

void ButtonTestPage::ButtonRight() {
  AddPressed('R');
  left=0;
}

void ButtonTestPage::ButtonDown() {
  AddPressed('D');
  left=0;
}

void ButtonTestPage::ButtonUp() {
  AddPressed('U');
  left=0;
}


