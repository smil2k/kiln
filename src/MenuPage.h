/*
 * All rights reserved.
 */

/*
 * File:   MenuPage.h
 * Author: smil
 *
 * Created on January 2, 2017, 5:21 PM
 */

#ifndef MENUPAGE_H
#define MENUPAGE_H

#include "Page.h"

#define MAX_MENU_ITEMS 5

struct MenuItem {
  const char *text;
  Page *page;
};

class MenuPage : public Page {
public:
  MenuPage();
  MenuPage(Page * parent);

  void AddMenu(const char *itemName, Page *page);



private:
  virtual void DoDraw();

  virtual void ButtonUp();
  virtual void ButtonDown();
  virtual void ButtonRight();

  int8_t current;
  uint8_t itemCount;
  MenuItem items[MAX_MENU_ITEMS];
};

#endif /* MENUPAGE_H */

