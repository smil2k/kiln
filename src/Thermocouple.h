
/***************************************************
  Based on ...

    This is a library for the Adafruit Thermocouple Sensor w/MAX31855K

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

#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include <Module.h>
#include <Metro.h>

class Thermocouple : private Module {
public:
  Thermocouple(int8_t sclk, int8_t miso, int8_t cs);

  double GetTemperature();
  double GetColdJunctionTemperature();
  int GetReadError();

  virtual void Loop();

private:
  int8_t sclk, miso, cs;
  uint32_t currentValue;
  Metro readTimer;
};


#endif /* THERMOCOUPLE_H */

