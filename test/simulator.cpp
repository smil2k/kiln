#include <unistd.h>

#include "Arduino.h"


int main(int argc, char** argv) {
  setup();

  while(1) {
    loop();
    usleep(1);
  }

  return 0;
}

