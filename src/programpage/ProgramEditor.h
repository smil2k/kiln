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

struct ProgramStep {
  uint8_t operation;
  uint16_t parameter;

  ProgramStep *next;
};

class ProgramEditor;

class Operation {
public:
  Operation(ProgramEditor* parent, const char* operationName);

  virtual void ButtonUp() {
    DoAction();
  };

  virtual void ButtonDown() {
    DoAction();
  };

  virtual void DoDraw();
  virtual void DoAction() = 0;

protected:
  ProgramEditor *parent;

private:
  Operation *next;
  const char *operationName;
  friend class ProgramEditor;
};

class ProgramEditor : public Page {
public:
  ProgramEditor(EditProgramPage *parent);

  void Save();
  void Exit();
  void DisposeSteps();

  void AddOperation(Operation *operation);
private:

  virtual void Activate();

  virtual void DoDraw();

  virtual void ButtonDown();

  virtual void ButtonLeft();

  virtual void ButtonRight();

  virtual void ButtonUp();

  Operation *operations;
  Operation *current;
public:
  EditProgramPage* parent;
  ProgramStep *stepsHead;
  ProgramStep *stepsCurrent;
};

#include "ProgramEditorOperations.h"

#endif /* PROGRAMEDITOR_H */
