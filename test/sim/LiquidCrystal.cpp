/*
 * All rights reserved.
 */

/*
 * File:   LiquidCrystal.cpp
 * Author: smil
 *
 * Created on February 12, 2017, 3:17 PM
 */

#include "LiquidCrystal.h"
#include "Module.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

Metro rate(100);

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) {
  memory = NULL;
  cols = rows = 0;
}

void LiquidCrystal::Loop() {
  if (rate.check()) {
    // go up 5 lines and then write again.
    printf("\x1b[4A");
    for (int i = 0; i < cols; i++) {
      printf("-");
    }
    printf("\n");
    char *p = memory;
    for (int r = 0; r < rows; r++) {
      p += write(1, p, cols);
      printf("\n");
    }

    for (int i = 0; i < cols; i++) {
      printf("-");
    }
    printf("\n");
  }
}

void LiquidCrystal::begin(uint8_t cols, uint8_t rows, uint8_t charsize) {
  setbuf(stdout, NULL);
  memorySize = cols * rows;
  memory = (char*) malloc(memorySize);
  clear();

  this->rows = rows;
  this->cols = cols;


  printf("Use arrows to navigate, ctrl-c to quit.");
  for (int i = -4; i < rows; i++) {
    printf("\n");
  }
}

void LiquidCrystal::clear() {
  memset(memory, ' ', memorySize);
  setCursor(0, 0);
}

void LiquidCrystal::setCursor(uint8_t col, uint8_t row) {
  cursor = memory + col + row * (cols + 1);
}

void LiquidCrystal::print(const char *text) {
  cursor += sprintf(cursor, "%s", text);
}

void LiquidCrystal::print(char ch) {
  cursor += sprintf(cursor, "%c", ch);
}

void LiquidCrystal::print(long number, int sys) {
  // todo system ignored!
  cursor += sprintf(cursor, "%d", number);
}

void LiquidCrystal::print(int number, int sys) {
  // todo system ignored!
  cursor += sprintf(cursor, "%d", number);
}

void LiquidCrystal::print(double num, int fract) {
  // todo fract ignored!
  cursor += sprintf(cursor, "%f", num);
}