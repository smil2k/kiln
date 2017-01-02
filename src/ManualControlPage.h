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

class ManualControlPage : private Module, public Page {
public:

  ManualControlPage(Page *parent) : Page(parent) {
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

