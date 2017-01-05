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

EditProgramPage::EditProgramPage(MenuPage* parent) : ProgramPage(parent) {
  parent->AddMenu("Edit Program", this);
}

void EditProgramPage::ButtonRight() {
  
}


