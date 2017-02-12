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
operations(NULL),
current(NULL),
stepsCurrent(NULL),
stepsHead(NULL) {
  parent->SetEditor(this);
}

void ProgramEditor::AddOperation(Operation* operation) {
  if (operations) {
    Operation *o = operations;
    while (o->next) {
      o = o->next;
    }
    o->next = operation;
    operation->next = NULL;
  } else {
    operations = operation;
  }
}

void ProgramEditor::Activate() {
  DisposeSteps();

  Program *current = parent->GetCurrent();

}

void ProgramEditor::DisposeSteps() {
  if (stepsHead) {
    ProgramStep *next;
    while (stepsHead->next) {
      next = stepsHead->next;
      delete stepsHead;
      stepsHead = next;
    }
  }
  stepsHead = NULL;
  stepsCurrent = NULL;
}

void ProgramEditor::ButtonUp() {

}
void ProgramEditor::ButtonDown() {

}

void ProgramEditor::ButtonLeft() {

}

void ProgramEditor::ButtonRight() {

}

void ProgramEditor::DoDraw() {

}

