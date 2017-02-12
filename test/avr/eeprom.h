/*
 * All rights reserved.
 */

/*
 * File:   eeprom.h
 * Author: smil
 *
 * Created on February 12, 2017, 4:01 PM
 */

#ifndef EEPROM_H
#define EEPROM_H

#include <stddef.h>
#include <inttypes.h>

void eeprom_write_block (const void *__src, void *__dst, size_t __n);
void eeprom_read_block (void *__dst, const void *__src, size_t __n);
uint8_t eeprom_read_byte (const uint8_t *__p);
void eeprom_write_byte (uint8_t *__p, uint8_t __value);

#endif /* EEPROM_H */

