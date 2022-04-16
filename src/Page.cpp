/*
 * All rights reserved.
 */

/*
 * File:   Page.cpp
 * Author: smil
 *
 * Created on January 1, 2017, 7:40 PM
 */

#include "Page.h"
#include "common.h"

Page *Page::currentPage = 0L;
bool Page::toggle;
Metro Page::metro(200);

Page::Page(Page* parent) : parent(parent) {
}

Page::Page() {
  parent = 0L;
}

Page::~Page() {
}

Page* Page::CurrentPage() {
  return currentPage;
}

void Page::CurrentPage(Page* page) {
  currentPage = page;
  page->Activate();
}

void Page::ButtonLeft() {
  if (parent) {
    currentPage = parent;
  }
}

void Page::Loop() {
  if (currentPage == this) {
    DoActiveLoop();
    if (metro.check()) {
      lcd.clear();
      lcd.setCursor(0, 0);
      DoDraw();
      lcd.setCursor(19, 0);
      lcd.print(toggle ? ' ' : '.');
      toggle = !toggle;
      lcd.setCursor(19, 1);

      char h;
      switch (heater.Duty()) {
        case 0: h = ' ';
          break;
        case 100: h = 'X';
          break;
        default:
          h = '0' + (heater.Duty() / 10);
      }
      lcd.print(h);
    }
  } else {
    DoBackgroundLoop();
  }

}
