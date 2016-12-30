#!/bin/bash
export PATH=/opt/Software/arduino-1.0.5/hardware/tools/avr/bin:/bin:/usr/bin:/usr/share/arduino/hardware/tools/

unset LD_PRELOAD

avrdude -C /usr/share/arduino/hardware/tools/avrdude.conf -c usbasp -p m328p -U flash:w:.build/unoasp/firmware.hex:i