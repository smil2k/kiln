/*
 * All rights reserved.
 */

/*
 * File:   ProgramPage.cpp
 * Author: smil
 *
 * Created on January 3, 2017, 8:01 PM
 */

#include "EditProgramPage.h"

EditProgramPage::EditProgramPage(MenuPage* parent) : BaseProgramListPage(parent) {
  parent->AddMenu("Edit Programs", this);
}

void EditProgramPage::ButtonRight() {
  CurrentPage(editor);

}
void EditProgramPage::SetEditor(Page* page) {
  this->editor = page;
}