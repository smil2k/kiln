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

#define MAX_PROGRAM_STEPS 30
#define MAX_PROGRAMS 10


// Parameter = PARAM_TEMP. Set the target temperature, next instruction
#define OP_SETTEMP 0
// Parameter = PARAM_TIME. Throttles the warm up or the cool down for the give change time
#define OP_CHANGETIME 1
// Parameter = PARAM_TIME, no particular action, just wait
#define OP_WAIT 2
// Parameter = PARAM_NONE, Waits until safe temperature reached
#define OP_SAFETEMP 3
// Parameter = PARAM_NONE, Beep 1. 2. or 3. times
#define OP_BEEP1 4
#define OP_BEEP2 5
#define OP_BEEP3 6

struct Program {
  int count;
  uint8_t operations[MAX_PROGRAM_STEPS];
  uint16_t parameters[MAX_PROGRAM_STEPS];
};

class BaseProgramListPage : public Page {
public:
  BaseProgramListPage(MenuPage *parent);

  Program* GetCurrent();
  void SaveCurrent(Program *program);

protected:
  void Load(uint8_t index, Program *p);
  void Save(uint8_t index, Program *p);

private:
  virtual void DoDraw();

  virtual void ButtonDown();
  virtual void ButtonUp();

  virtual void Begin();



  static bool programsLoaded;
  static Program programs[];
  int8_t current;
};

#endif /* PROGRAMPAGE_H */

