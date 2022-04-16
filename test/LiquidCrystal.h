/*
 * All rights reserved.
 */

/*
 * File:   LiquidCrystal.h
 * Author: smil
 *
 * Created on February 12, 2017, 3:17 PM
 */

#ifndef LIQUIDCRYSTAL_H
#define LIQUIDCRYSTAL_H

#include "Arduino.h"

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#include "Module.h"
#include "Metro.h"

class LiquidCrystal : public Module {
public:
  LiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);

  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

  void clear();

  virtual void Loop();

  void noDisplay() {
  };

  void display() {
  };

  void noBlink() {
  };

  void blink() {
  };

  void noCursor() {
  };

  void autoscroll() {
  };

  void noAutoscroll() {
  };

  void setCursor(uint8_t, uint8_t);

  void print(const char *text);
  void print(char ch);
  void print(int, int = DEC);
  void print(long, int = DEC);
  void print(double, int = 2);
private:
  char *memory;
  char *cursor;
  int memorySize;
  int cols;
  int rows;
};

#endif /* LIQUIDCRYSTAL_H */

