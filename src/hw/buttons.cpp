/*
 * All rights reserved.
 */

/*
 * File:   Buttons.cpp
 * Author: smil
 *
 * Created on January 2, 2017, 2:44 PM
 */

#include "../common.h"
#include "buttons.h"
#include "../Page.h"
#include "light.h"
#include "PinChangeInt.h"
#include <Metro.h>

static bool upPressed = false;
static bool downPressed = false;
static bool rightPressed = false;
static bool leftPressed = false;

static Metro buttonCheck(50, 1);

static void up() {
  upPressed = true;
  turnOnLight();
}

static void down() {
  downPressed = true;
  turnOnLight();
}

static void right() {
  rightPressed = true;
  turnOnLight();
}

static void left() {
  leftPressed = true;
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

void loopButtons() {
  if (buttonCheck.check()) {
    Page *c = Page::CurrentPage();
    if (c) {
      if (upPressed) {
        c->ButtonUp();
        upPressed = false;
      }
      if (downPressed) {
        c->ButtonDown();
        downPressed = false;
      }
      if (leftPressed) {
        c->ButtonLeft();
        leftPressed = false;
      }
      if (rightPressed) {
        c->ButtonRight();
        rightPressed = false;
      }
    }
  }
}

