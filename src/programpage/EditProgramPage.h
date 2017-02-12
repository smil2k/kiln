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

#include "BaseProgramListPage.h"

class EditProgramPage : public BaseProgramListPage {
public:
  EditProgramPage(MenuPage *parent);
  void SetEditor(Page *page);
private:
  virtual void ButtonRight();

  Page *editor;
};

#endif // EDITPROGRAMPAGE_H

