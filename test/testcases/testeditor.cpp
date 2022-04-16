#include <assert.h>

#include "Arduino.h"
#include "programpage/ProgramEditor.h"
#include <unistd.h>
#include "testrunner.h"

static class DelOperationTest : public TestProgEditor  {
  DeleteRowOperation del;

public:

  DelOperationTest() :
  del(&editor) {
    printf("Starting test: %s\n", __FILE__);
    testDelete();
  }

  void testDelete() {
    ProgramStep *p1 = new ProgramStep();
    ProgramStep *p2 = new ProgramStep();
    ProgramStep *p3 = new ProgramStep();
    ProgramStep *p4 = new ProgramStep();

    editor.AddBelowCurrent(p1);
    editor.AddBelowCurrent(p2);
    editor.AddBelowCurrent(p3);
    editor.AddBelowCurrent(p4);

    assert(editor.Current() == p4); // 1 2 3 *4
    del.DoAction();
    assert(editor.Current() == p3); // 1 2 *3
    editor.Prev();
    assert(editor.Current() == p2); // 1 *2 3
    del.DoAction();
    assert(editor.Current() == p3); // 1 *3
    editor.Prev();
    assert(editor.Current() == p1); // *1 3
    del.DoAction();
    assert(editor.Current() == p3); // *3
    del.DoAction();
    assert(editor.Current() == NULL); //
  }

} test;
