/*
 * All rights reserved.
 */

/*
 * File:   ProgramEditor.cpp
 * Author: smil
 *
 * Created on January 3, 2017, 10:39 PM
 */

#include "ProgramEditor.h"

ProgramEditor::ProgramEditor(EditProgramPage* parent) :
Page(parent),
parent(parent),
operationsTail(NULL),
current(NULL),
stepsCurrent(NULL),
stepsHead(NULL) {
  parent->SetEditor(this);
}

void ProgramEditor::DrawDefault() {
  lcd.print(current->operationName);
  lcd.setCursor(0, 1);
  uint8_t index = 0;
  ProgramStep *i = stepsHead;
  while (i && i != stepsCurrent) {
    index++;
    i = i->next;
  }
  if (i) {
    lcd.print(index);
    lcd.print(' ');
    lcd.print((long) i);

  } else {
    lcd.print("Empty");
  }
}

void ProgramEditor::Activate() {
  DisposeSteps();

  Program *current = parent->GetCurrent();

}

void ProgramEditor::Save() {

}

void ProgramEditor::Exit() {
  DisposeSteps();
  CurrentPage(parent);
}

void ProgramEditor::DisposeSteps() {
  if (stepsHead) {
    stepsCurrent = stepsHead;
    ProgramStep *next;
    do {
      next = stepsCurrent->next;
      delete stepsCurrent;
      stepsCurrent = next;
    } while ( stepsCurrent != stepsHead);
  }
  stepsHead = NULL;
  stepsCurrent = NULL;
}

void ProgramEditor::ButtonUp() {
  do {
    current = current->prev;
  } while (current->CanActivate() == false);
}

void ProgramEditor::ButtonDown() {
  do {
    current = current->next;
  } while (current->CanActivate() == false);
}

void ProgramEditor::ButtonLeft() {
  current->ButtonPrev();
}

void ProgramEditor::ButtonRight() {
  current->ButtonNext();
}

void ProgramEditor::DoDraw() {
  if (current) {
    current->DoDraw();
  }
}

void ProgramEditor::AddOperation(Operation* operation) {
  if (operationsTail) {
    operationsTail->next->prev = operation;
    operation->next = operationsTail->next;
    operation->prev = operationsTail;
    operationsTail->next = operation;

    operationsTail = operation;
  } else {
    operationsTail = operation;
    current = operation;

    current->next = current;
    current->prev = current;
  }
}

void ProgramEditor::AddBelowCurrent(ProgramStep* step) {
  if (stepsCurrent) {
    stepsCurrent->next->prev = step;
    step->next = stepsCurrent->next;
    step->prev = stepsCurrent;
    stepsCurrent->next = step;
    stepsCurrent = step;

  } else {
    stepsHead = step;
    stepsCurrent = step;
    step->next = step;
    step->prev = step;
  }
}

void ProgramEditor::SetHead() {
  stepsHead = stepsCurrent;
}

bool ProgramEditor::HasOneRowOnly() {
  if ( stepsHead) {
    return stepsHead->next == stepsHead;
  } else {
    return false;
  }
}

bool ProgramEditor::AtFirstRow() {
  if (stepsCurrent) {
    return stepsCurrent == stepsHead;
  } else {
    return false;
  }
}

bool ProgramEditor::AtLastRow() {
  if (stepsCurrent) {
    return stepsCurrent->next == stepsHead;
  } else {
    return false;
  }
}

void ProgramEditor::JumpToFirstRow() {
  stepsCurrent = stepsHead;
}


ProgramStep* ProgramEditor::RemoveCurrent() {
  if (stepsCurrent) {
    ProgramStep *result = stepsCurrent;
    if (stepsCurrent == stepsCurrent->next) {
      stepsCurrent = NULL;
      stepsHead = NULL;
      return result;
    } else {
      bool last = AtLastRow();
      stepsCurrent->next->prev = stepsCurrent->prev;
      stepsCurrent->prev->next = stepsCurrent->next;

      if (last) {
        stepsCurrent = stepsCurrent->prev;
      } else {
        stepsCurrent = stepsCurrent->next;
      }
      return result;
    }
  }

  return NULL;
}

void ProgramEditor::Next() {
  if (stepsCurrent) {
    stepsCurrent = stepsCurrent->next;
  }
}

void ProgramEditor::Prev() {
  if (stepsCurrent) {
    stepsCurrent = stepsCurrent->prev;
  }
}

ProgramStep* ProgramEditor::Current() {
  return stepsCurrent;
}

