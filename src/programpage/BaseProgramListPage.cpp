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
#include "BaseProgramListPage.h"

bool BaseProgramListPage::programsLoaded;
Program BaseProgramListPage::programs[MAX_PROGRAMS];

BaseProgramListPage::BaseProgramListPage(MenuPage* parent) : Page(parent) {
}

void BaseProgramListPage::Begin() {
  if (!programsLoaded) {
    lcd.clear();
    lcd.print("Loading programs...");

    for (uint8_t i = 0; i < MAX_PROGRAMS; i++) {
      Load(i, &programs[i]);
    }
    programsLoaded = true;
  }
}

void BaseProgramListPage::DoDraw() {
  lcd.clear();
  lcd.print("Select program");
  lcd.setCursor(0, 1);
  lcd.print("P");
  lcd.print(current + 1);
  if (programs[current].count) {
    lcd.print(" ");
    lcd.print(programs[current].count);
    lcd.print(" steps");
  } else {
    lcd.print(" Empty");
  }
}

void BaseProgramListPage::ButtonDown() {
  current = (current + 1) % MAX_PROGRAMS;
}

void BaseProgramListPage::ButtonUp() {
  current--;
  if (current < 0) {
    current = MAX_PROGRAMS - 1;
  }
}

uint8_t *GetPosition(uint8_t index) {
  return (uint8_t *) (index * (MAX_PROGRAM_STEPS * 3 + 2));
}

void BaseProgramListPage::Load(uint8_t index, Program* p) {
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

void BaseProgramListPage::Save(uint8_t index, Program* p) {
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

Program *BaseProgramListPage::GetCurrent() {
  return &programs[current];
}

void BaseProgramListPage::SaveCurrent(Program* program) {
  Save(current, program);
  memcpy(&programs[current], program, sizeof (Program));
}






