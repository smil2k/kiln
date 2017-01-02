/*
 * All rights reserved.
 */

/*
 * File:   MenuPage.cpp
 * Author: smil
 *
 * Created on January 2, 2017, 5:21 PM
 */

#include "Page.h"
#include "MenuPage.h"
#include "common.h"

MenuPage::MenuPage() : itemCount(0), current(0) {
}

MenuPage::MenuPage(Page* parent) : Page(parent), itemCount(0), current(0) {

}

void MenuPage::AddMenu(const char* itemName, Page* page) {
  if (itemCount < MAX_MENU_ITEMS) {
    items[itemCount].page = page;
    items[itemCount].text = itemName;
    itemCount++;
  }
}

void MenuPage::ButtonDown() {
  current = (current + 1) % itemCount;
}

void MenuPage::ButtonUp() {

  current = (current - 1) % itemCount;
  if (current < 0) {
    current = itemCount - 1;
  }
}

void MenuPage::ButtonRight() {
  if (items[current].page) {
    Page::CurrentPage(items[current].page);
  }
}

void MenuPage::DoDraw() {
  lcd.setCursor(0, 0);
  lcd.print("Menu \x18 \x19,  \x20 to act");
  lcd.setCursor(0, 1);
  if (items[current].text) {
    lcd.print(items[current].text);
  }
}

