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

#include "../common.h"
#include "EditProgramPage.h"

class ProgramEditor;

class ProgramStep {
  uint8_t operation;
  uint16_t parameter;

private:
  ProgramStep *next;
  ProgramStep *prev;

  friend class ProgramEditor;
};


class Operation {
public:
  Operation(ProgramEditor* parent, const char* operationName);

  virtual void ButtonPrev() {
    DoAction();
  };

  virtual void ButtonNext() {
    DoAction();
  };

  virtual void DoDraw();
  virtual void DoAction() {};

  virtual bool CanActivate();

protected:
  ProgramEditor *parent;

private:
  const char *operationName;
  Operation *next;
  Operation *prev;
  friend class ProgramEditor;
};

class ProgramEditor : public Page {
public:
  ProgramEditor(EditProgramPage *parent);

  void Save();
  void Exit();
  void DisposeSteps();

  void AddOperation(Operation *operation);

  ProgramStep *RemoveCurrent();
  void AddBelowCurrent(ProgramStep *step);
  void SetHead();
  void JumpToFirstRow();
  void Next();
  void Prev();
  bool HasOneRowOnly();
  bool AtFirstRow();
  bool AtLastRow();

  ProgramStep *Current();
  void DrawDefault();

private:

  virtual void Activate();

  virtual void DoDraw();

  virtual void ButtonDown();

  virtual void ButtonLeft();

  virtual void ButtonRight();

  virtual void ButtonUp();


  Operation *operationsTail;
  Operation *current;
  ProgramStep *stepsHead;
  ProgramStep *stepsCurrent;
  EditProgramPage* parent;
};

#include "ProgramEditorOperations.h"

#endif /* PROGRAMEDITOR_H */
