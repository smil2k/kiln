
/***************************************************
  This is an example for the Adafruit Thermocouple Sensor w/MAX31855K

  Designed specifically to work with the Adafruit Thermocouple Sensor
  ----> https://www.adafruit.com/products/269

  These displays use SPI to communicate, 3 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include "common.h"
#include "PinChangeInt.h"
#include "config.h"
#include "ManualControlPage.h"

Thermocouple thermocouple(thermoCLK, thermoCS, thermoDO);

LiquidCrystal lcd(LCD_RS, LCD_EN,
        LCD_D0, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

ManualControlPage manualPage;


void setup() {
  Page::CurrentPage(&manualPage);

  beginModules();

  lcd.begin(20, 2);
  lcd.noBlink();
  lcd.print("Hello");

  setupLight(PIN_BACKLIGHT, 1000, 0);

  pinMode(PIN_BUTTON_UP, INPUT);
  pinMode(PIN_BUTTON_RIGHT, INPUT);

  PCintPort::attachInterruptByMask(PIN_PORT_BUTTON_LEFT, PIN_MASK_BUTTON_LEFT, &left);
  PCintPort::attachInterruptByMask(PIN_PORT_BUTTON_DOWN, PIN_MASK_BUTTON_DOWN, &down);
  PCintPort::attachInterrupt(PIN_BUTTON_RIGHT, &right);
  PCintPort::attachInterrupt(PIN_BUTTON_UP, &up);
}

int i = 0;
int j = 0;
int play = 0;


int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void up() {
  Page *c = Page::CurrentPage();
  if (c) {
    c->ButtonUp();
  }
  turnOnLight();
}

void down() {
  Page *c = Page::CurrentPage();
  if (c) {
    c->ButtonDown();
  }
  turnOnLight();
}

void right() {
  Page *c = Page::CurrentPage();
  if (c) {
    c->ButtonRight();
  }
  turnOnLight();
}

void left() {
  Page *c = Page::CurrentPage();
  if (c) {
    c->ButtonLeft();
  }
  turnOnLight();
}

void loop() {
  lightLoop();
  loopModules();

  if (play) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      //analogWrite(TONE, melody[thisNote] );
      tone(TONE, melody[thisNote], noteDuration);
      //delay(noteDuration);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(TONE);
    }
    play = 0;
  }

}