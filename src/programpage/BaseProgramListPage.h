/*
 * All rights reserved.
 */

/*
 * File:   ProgramPage.h
 * Author: smil
 *
 * Created on January 3, 2017, 8:05 PM
 */

#ifndef PROGRAMPAGE_H
#define PROGRAMPAGE_H

#include "../MenuPage.h"

struct Program {
  int count;
  uint8_t operations[30];
  uint16_t parameters[30];
};

class ProgramPage : public Page {
public:
  ProgramPage(MenuPage *parent);

protected:
  void Load(uint8_t index, Program *p);
  void Save(uint8_t index, Program *p);

private:
  virtual void DoDraw();

  virtual void ButtonDown();
  virtual void ButtonUp();

  virtual void Begin();



  static bool programsLoaded;
  static Program programs[10];
  int8_t current;
};

#endif /* PROGRAMPAGE_H */

