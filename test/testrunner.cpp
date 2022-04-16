#include <assert.h>

#include "Arduino.h"
#include "programpage/ProgramEditor.h"
#include <unistd.h>

#include "Arduino.h"
#include "testrunner.h"

static MenuPage menu("root");

EditProgramPage page(&menu);

TestProgEditor::TestProgEditor() : editor(&page) {
    page.CurrentPage(&page);
}

int main(int argc, char** argv) {
  printf("Success\n");
  /*setup();

  while(1) {
    loop();
    usleep(1);
  }
*/
  return 0;
}

