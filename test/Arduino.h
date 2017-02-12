/*
 * All rights reserved.
 */

/*
 * File:   Arduino.h
 * Author: smil
 *
 * Created on February 12, 2017, 1:25 PM
 */

#ifndef ARDUINO_H
#define ARDUINO_H

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

#define SCK 1
#define A3 1
#define A4 1
#define A5 1
#define MISO 1

#define bit(b) (1UL << (b))


long millis();

void setup();
void loop();

#endif /* ARDUINO_H */

