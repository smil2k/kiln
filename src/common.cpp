/*
 * All rights reserved.
 */

#include "common.h"
#include "MenuPage.h"
#include "ManualControlPage.h"
#include "hw/buttons.h"
#include "hw/light.h"
#include "LCDTestPage.h"
#include "ButtonTestPage.h"
#include "programpage/EditProgramPage.h"
#include "programpage/ProgramEditor.h"

Thermocouple thermocouple(thermoCLK, thermoDO, thermoCS);

LiquidCrystal lcd(LCD_RS, LCD_EN,
        LCD_D0, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

Heatelement heater(PIN_HEATER);


MenuPage mainMenu("Kiln Control Menu");

ManualControlPage manualPage(&mainMenu);
EditProgramPage programPage(&mainMenu);

ProgramEditor editor(&programPage);
BackOperation back(&editor);

MenuPage testMenu("Test Menu", &mainMenu);

LCDTestPage lcdpage(&testMenu);
ButtonTestPage buttonTest(&testMenu);

void setup() {
  lcd.begin(20, 2);
  lcd.noBlink();
  lcd.print("Loading...");
  Page::CurrentPage(&mainMenu);

  setupLight(PIN_BACKLIGHT, 1000, 0);
  setupButtons();

  beginModules();

  lcd.clear();
  lcd.print("Done");
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

void loop() {
  lightLoop();
  loopModules();
  loopButtons();

  /*
  if (play) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      //analogWrite(TONE, melody[thisNote] );
      tone(PIN_TONE, melody[thisNote], noteDuration);
      //delay(noteDuration);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(PIN_TONE);
    }
    play = 0;
  }
*/
}