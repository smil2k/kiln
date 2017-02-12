#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include "hw/Thermocouple.h"
#include "LiquidCrystal.h"
#include "config.h"
#include "pitches.h"
#include "Heatelement.h"

extern Thermocouple thermocouple;
extern LiquidCrystal lcd;
extern Heatelement heater;

#endif	// COMMON_H

