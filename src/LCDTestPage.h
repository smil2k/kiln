/*
 * All rights reserved.
 */

/*
 * File:   LCDTestPage.h
 * Author: smil
 *
 * Created on January 2, 2017, 5:54 PM
 */

#ifndef LCDTESTPAGE_H
#define LCDTESTPAGE_H

#include <stdint.h>

#include "Page.h"
#include "MenuPage.h"

class LCDTestPage : public Page {
public:

  LCDTestPage(MenuPage *parent) : Page(parent) {
    parent->AddMenu("LCD Test", this);
  };

private:

  virtual void DoDraw();

  virtual void ButtonUp();
  virtual void ButtonDown();

  uint8_t index;

};

#endif /* LCDTESTPAGE_H */

