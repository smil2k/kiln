/*
 * All rights reserved.
 */

/*
 * File:   heater.h
 * Author: smil
 *
 * Created on February 12, 2017, 5:04 PM
 */

#ifndef HEATER_H
#define HEATER_H

#include "Arduino.h"

void SetupHeater( uint8_t pin );
void ControlHeater( uint8_t pin, bool heat);

#endif /* HEATER_H */

