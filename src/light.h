/*
 * All rights reserved.
 */

/*
 * File:   light.h
 * Author: smil
 *
 * Created on January 1, 2017, 7:24 PM
 */

#ifndef LIGHT_H
#define LIGHT_H

#include <stdint.h>


extern void setupLight(uint8_t backlightPin, int startup, int keep);
extern void turnOnLight();
extern void lightLoop();

#endif /* LIGHT_H */

