/*
 * All rights reserved.
 */

/*
 * File:   ProgramPage.h
 * Author: smil
 *
 * Created on January 3, 2017, 8:01 PM
 */


#ifndef EDITPROGRAMPAGE_H
#define EDITPROGRAMPAGE_H

#include "ProgramPage.h"

class EditProgramPage : public ProgramPage {
public:
  EditProgramPage(MenuPage *parent);
private:
  virtual void ButtonRight();
};

#endif // EDITPROGRAMPAGE_H

