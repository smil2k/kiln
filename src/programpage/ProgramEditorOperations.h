/*
 * All rights reserved.
 */

/*
 * File:   ProgramEditorOperations.h
 * Author: smil
 *
 * Created on February 11, 2017, 8:07 PM
 */

#ifndef PROGRAMEDITOROPERATIONS_H
#define PROGRAMEDITOROPERATIONS_H

class NewRowOperation : public Operation {
public:

  NewRowOperation(ProgramEditor* parent) : Operation(parent, "New Row Above/Below") {
  }

  virtual void ButtonUp();
  virtual void ButtonDown();
};

class SelectRowOperation : public Operation {
public:

  SelectRowOperation(ProgramEditor* parent) : Operation(parent, "Select Row") {
  }

  virtual void ButtonUp();
  virtual void ButtonDown();
};

class MoveRowOperation : public Operation {
public:

  MoveRowOperation(ProgramEditor* parent) : Operation(parent, "Move Row") {
  }

  virtual void ButtonUp();
  virtual void ButtonDown();
};

class SelectOpCodeOperation : public Operation {
public:

  SelectOpCodeOperation(ProgramEditor* parent) : Operation(parent, "Select Operation") {
  }

  virtual void ButtonUp();
  virtual void ButtonDown();
};

class AlterValueOperation : public Operation {
public:

  AlterValueOperation(ProgramEditor* parent, uint8_t value)
  : Operation(parent, "Value"), value(value) {
  }

  virtual void ButtonUp();
  virtual void ButtonDown();

  uint8_t value;
};

class DeleteRowOperation : public Operation {
public:

  DeleteRowOperation(ProgramEditor* parent) : Operation(parent, "Delete Current Row") {
  }

  virtual void DoAction();
};

class CopyRowOperation : public Operation {
public:

  CopyRowOperation(ProgramEditor* parent) : Operation(parent, "Copy Row") {
  }

  virtual void DoAction();
};

class PasteRowOperation : public Operation {
public:

  PasteRowOperation(ProgramEditor* parent) : Operation(parent, "Paste Row") {
  }

  virtual void DoAction();
};

class DuplicateRowOperation : public Operation {
public:

  DuplicateRowOperation(ProgramEditor* parent) : Operation(parent, " Duplicate Row") {
  }

  virtual void DoAction();
};

class ClearOperation : public Operation {
public:

  ClearOperation(ProgramEditor* parent) : Operation(parent, "Clear all") {
  }

  virtual void DoAction();
};

class BackOperation : public Operation {
public:
  BackOperation(ProgramEditor* parent) : Operation(parent, "Cancel Edit") {
  }

  virtual void DoAction();
};

class SaveAndBackOperation : public Operation {
public:

  SaveAndBackOperation(ProgramEditor* parent) : Operation(parent, "Save And Exit") {
  }

  virtual void DoAction();
};

#endif /* PROGRAMEDITOROPERATIONS_H */

