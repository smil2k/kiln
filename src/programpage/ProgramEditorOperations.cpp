/*
 * All rights reserved.
 */

#include "ProgramEditor.h"

Operation::Operation(ProgramEditor* parent, const char* operationName) : parent(parent), operationName(operationName) {

}

void Operation::DoDraw() {
  lcd.print(operationName);
  lcd.setCursor(0,1);
  uint8_t index = 0;
  ProgramStep *i = parent->stepsHead;
  while ( i && i != parent->stepsCurrent) {
    index++;
    i = i->next;
  }
  if (i) {
    lcd.print(index);
    lcd.print(' ');

  } else {
    lcd.print("Empty");
  }
}

void BackOperation::DoAction() {
  parent->DisposeSteps();
  parent->CurrentPage(parent->parent);
}


