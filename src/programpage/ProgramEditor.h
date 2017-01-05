/*
 * All rights reserved.
 */

/*
 * File:   ProgramEditor.h
 * Author: smil
 *
 * Created on January 3, 2017, 10:39 PM
 */

#ifndef PROGRAMEDITOR_H
#define PROGRAMEDITOR_H

class ProgramEditor : public Page {
public:
  ProgramEditor(Page *parent);
private:

  virtual void DoDraw();

  virtual void ButtonDown();

  virtual void ButtonLeft();

  virtual void ButtonRight();

  virtual void ButtonUp();
  
};

#endif /* PROGRAMEDITOR_H */

