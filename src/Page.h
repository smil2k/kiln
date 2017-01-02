/*
 * All rights reserved.
 */

/*
 * File:   Page.h
 * Author: smil
 *
 * Created on January 1, 2017, 7:40 PM
 */

#ifndef PAGE_H
#define PAGE_H

#include "Metro.h"
#include <Module.h>

class Page : private Module {
protected:

  Page();
  Page(Page *parent);
  virtual ~Page();

  virtual void DoActiveLoop() {};
  virtual void DoBackgroundLoop() {};
  virtual void Activate() {};
  
  virtual void DoDraw() = 0;
public:

  virtual void ButtonUp() {
  }

  virtual void ButtonDown() {
  }

  virtual void ButtonLeft();

  virtual void ButtonRight() {
  }

  virtual void Loop();

  static Page *CurrentPage();
  static void CurrentPage(Page *page);

private:
  Page *parent;
  static Page *currentPage;
  static bool toggle;
  static Metro metro;
};


#endif /* PAGE_H */

