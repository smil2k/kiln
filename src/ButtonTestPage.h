/*
 * All rights reserved.
 */

/*
 * File:   ButtonTestPage.h
 * Author: smil
 *
 * Created on January 2, 2017, 6:32 PM
 */

#ifndef BUTTONTESTPAGE_H
#define BUTTONTESTPAGE_H

#include "common.h"
#include "MenuPage.h"

class ButtonTestPage : public Page {
public:
  ButtonTestPage(MenuPage *parent);


private:
  virtual void ButtonDown();
  virtual void ButtonLeft();
  virtual void ButtonRight();
  virtual void ButtonUp();
  virtual void DoDraw();

  virtual void Activate();

  void AddPressed(char btn);

  char *cursorPointer;
  char pressed[20];

  uint8_t left;
};

#endif /* BUTTONTESTPAGE_H */

