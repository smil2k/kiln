/*
 * All rights reserved.
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "Page.h"
#include <Metro.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>

static struct termios orig_termios; /* TERMinal I/O Structure */
static int ttyfd = STDIN_FILENO; /* STDIN_FILENO is 0 by default */

int nbFd;
Metro keyCheck(100, 1);

/* put terminal in raw mode - see termio(7I) for modes */
void tty_raw() {
  struct termios raw;

  raw = orig_termios; /* copy original and then modify below */

  /* input modes - clear indicated ones giving: no break, no CR to NL,
     no parity check, no strip char, no start/stop output (sic) control */
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

  /* local modes - clear giving: echoing off, canonical off (no erase with
     backspace, ^U,...) */
  raw.c_lflag &= ~(ECHO | ICANON);

  /* control chars - set return condition: min number of bytes and timer */
  raw.c_cc[VMIN] = 5;
  raw.c_cc[VTIME] = 8; /* after 5 bytes or .8 seconds
                                                after first byte seen      */
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 0; /* immediate - anything       */
  raw.c_cc[VMIN] = 2;
  raw.c_cc[VTIME] = 0; /* after two bytes, no timer  */
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 8; /* after a byte or .8 seconds */

  /* put terminal in raw mode after flushing */
  if (tcsetattr(ttyfd, TCSAFLUSH, &raw) < 0) {
    printf("can't set raw mode\n");
    exit(0);
  }
}


int tty_reset() {
  /* flush and reset */
  if (tcsetattr(ttyfd, TCSAFLUSH, &orig_termios) < 0) return -1;
  return 0;
}

/* exit handler for tty reset */
void tty_atexit(void)
{
  tty_reset();
}

void setupButtons() {
  nbFd = dup(ttyfd);
  tcgetattr(ttyfd,&orig_termios);
  atexit(tty_atexit);

  fcntl(nbFd, F_SETFL, O_NONBLOCK);
  tty_raw();
}

void loopButtons() {
  Page *c = Page::CurrentPage();
  if (keyCheck.check() && c) {
    char ch;
    int x = read(nbFd, &ch, 1);
    if (x != -1) {
      switch (ch) {
        case 13:
          c->ButtonRight();
          break;
        case 'x':
          exit(0);

        case 27:
          read(0, &ch, 1);
          if (ch != '[') {
            break;
          }
          read(0, &ch, 1);
          switch (ch) {
            case 'A':
              c->ButtonUp();
              break;
            case 'B':
              c->ButtonDown();
              break;
            case 'C':
              c->ButtonRight();
              break;
            case 'D':
              c->ButtonLeft();
              break;
          }
      }
    } else {
      if (errno != EWOULDBLOCK) {
        printf("error getting char: %d\n ", errno);
      }
    }
  }
}