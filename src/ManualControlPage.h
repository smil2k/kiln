/*
 * All rights reserved.
 */

/*
 * File:   ManualControlPage.h
 * Author: smil
 *
 * Created on January 1, 2017, 8:04 PM
 */

#ifndef MANUALCONTROLPAGE_H
#define MANUALCONTROLPAGE_H

#include <Module.h>
#include "Page.h"
#include "MenuPage.h"

class ManualControlPage : public Page {
public:

  ManualControlPage(MenuPage *parent) : Page(parent) {
    parent->AddMenu("Manual Control", this);
  };

  virtual void ButtonUp();
  virtual void ButtonDown();
  virtual void ButtonRight();

  virtual void DoDraw();
private:
  void SetDuty(uint8_t duty);
  bool dutyMode;
};

#endif /* MANUALCONTROLPAGE_H */

