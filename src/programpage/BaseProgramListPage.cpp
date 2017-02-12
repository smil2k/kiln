/*
 * All rights reserved.
 */

/*
 * File:   ProgramPage.cpp
 * Author: smil
 *
 * Created on January 3, 2017, 8:05 PM
 */

#include "../common.h"
#include <avr/eeprom.h>
#include "ProgramPage.h"

bool ProgramPage::programsLoaded;
Program ProgramPage::programs[10];

ProgramPage::ProgramPage(MenuPage* parent) : Page(parent) {
}

void ProgramPage::Begin() {
  if (!programsLoaded) {
    lcd.clear();
    lcd.print("Loading programs...");

    for (uint8_t i = 0; i < 10; i++) {
      Load(i, &programs[i]);
    }
    programsLoaded = true;
  }
}

void ProgramPage::DoDraw() {
  lcd.clear();
  lcd.print("Select program");
  lcd.setCursor(0, 1);
  lcd.print("P");
  lcd.print( current + 1 );
  lcd.print(programs[current].count ? " Used" : " Free");
}

void ProgramPage::ButtonDown() {
  current = (current + 1) % 10;
}

void ProgramPage::ButtonUp() {
  current --;
  if ( current < 0) {
    current = 9;
  }
}

uint8_t *GetPosition(uint8_t index) {
  return (uint8_t *) (index * 100); // exactly: (30 * 3 + 2); // 30 entries, 3 bytes each, + 2 control.
}

void ProgramPage::Load(uint8_t index, Program* p) {
  uint8_t *pos = GetPosition(index);
  uint8_t count = eeprom_read_byte(pos);
  if (count <= 30 && count > 0) {
    pos++;
    eeprom_read_block((void*) p->operations[0], pos, count);
    pos += count;
    eeprom_read_block((void*) p->parameters[0], pos, count * 2);
    pos += count * 2;
    uint8_t count2 = eeprom_read_byte(pos);

    if (count == count2) {
      p->count = count;
      return;
    }
  }
  memset(p, 0, sizeof (Program));
}

void ProgramPage::Save(uint8_t index, Program* p) {
  uint8_t *pos = GetPosition(index);

  eeprom_write_byte(pos, p->count);
  pos++;
  if (p->count > 0) {
    eeprom_write_block((void*) p->operations[0], pos, p->count);
    pos += p->count;
    eeprom_write_block((void*) p->parameters[0], pos, p->count * 2);
    pos += p->count * 2;
    eeprom_write_byte(pos, p->count);
  }
}




