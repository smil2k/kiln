/*
 * All rights reserved.
 */

/*
 * File:   Buttons.cpp
 * Author: smil
 *
 * Created on January 2, 2017, 2:44 PM
 */

#include "common.h"
#include "buttons.h"
#include "Page.h"
#include "light.h"
#include "PinChangeInt.h"

static void up() {
  Page *c = Page::CurrentPage();
  if (c) {
    c->ButtonUp();
  }
  turnOnLight();
}

static void down() {
  Page *c = Page::CurrentPage();
  if (c) {
    c->ButtonDown();
  }
  turnOnLight();
}

static void right() {
  Page *c = Page::CurrentPage();
  if (c) {
    c->ButtonRight();
  }
  turnOnLight();
}

static void left() {
  Page *c = Page::CurrentPage();
  if (c) {
    c->ButtonLeft();
  }
  turnOnLight();
}

void setupButtons() {
  PCintPort::attachInterruptByMask(PIN_PORT_BUTTON_LEFT, PIN_MASK_BUTTON_LEFT, &left);
  PCintPort::attachInterruptByMask(PIN_PORT_BUTTON_DOWN, PIN_MASK_BUTTON_DOWN, &down);
  PCintPort::attachInterrupt(PIN_BUTTON_RIGHT, &right);
  PCintPort::attachInterrupt(PIN_BUTTON_UP, &up);

  pinMode(PIN_BUTTON_UP, INPUT);
  pinMode(PIN_BUTTON_RIGHT, INPUT);

}

