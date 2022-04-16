/*
 * All rights reserved.
 */

#include "ProgramEditor.h"

Operation::Operation(ProgramEditor* parent, const char* operationName) :
parent(parent), operationName(operationName) {
  parent->AddOperation(this);
}

bool Operation::CanActivate() {
  // Default implementation skips operation if no row present.
  return parent->Current();
}

void Operation::DoDraw() {
  parent->DrawDefault();
}

void HelpOperation::DoDraw() {
  lcd.print("left/r: select op");
  lcd.setCursor(0, 1);
  lcd.print("up/dn: activate op");
}

void BackOperation::DoAction() {
  parent->Exit();
}

void SaveAndBackOperation::DoAction() {
  parent->Save();
  parent->Exit();
}

void ClearOperation::DoAction() {
  parent->DisposeSteps();
}


void SelectRowOperation::ButtonPrev() {
  parent->Prev();
}

void SelectRowOperation::ButtonNext() {
  parent->Next();
}


void NewRowOperation::ButtonPrev() {
  bool first = parent->AtFirstRow();
  parent->Prev();
  parent->AddBelowCurrent(new ProgramStep());
  if (first) {
    parent->SetHead();
  }
}

void NewRowOperation::ButtonNext() {
  parent->AddBelowCurrent(new ProgramStep());
}

void DeleteRowOperation::DoAction() {
  delete parent->RemoveCurrent();
}



void MoveRowOperation::ButtonPrev() {
  if ( parent->AtFirstRow() == false) {
    ProgramStep *p = parent->RemoveCurrent();
    parent->Prev();
    parent->AddBelowCurrent(p);
  }
}

void MoveRowOperation::ButtonNext() {
  if ( parent->AtLastRow() == false ) {
    ProgramStep *p = parent->RemoveCurrent();
    parent->Next();
    parent->AddBelowCurrent(p);
  }
}

bool MoveRowOperation::CanActivate() {
  return parent->Current() && parent->HasOneRowOnly() == false;
}

