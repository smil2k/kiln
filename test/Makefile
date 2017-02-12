TARGET = target

VPATH = ../lib/Metro ../lib/Module ../src ../src/kilnoperation ../src/programpage mock

MAIN = $(patsubst ../src/%.cpp,%.o,$(wildcard ../src/*.cpp))
KILN = $(patsubst ../src/kilnoperation/%.cpp,%.o,$(wildcard ../src/kilnoperation/*.cpp))
PRG = $(patsubst ../src/programpage/%.cpp,%.o,$(wildcard ../src/programpage/*.cpp))

MOCKCOMMON = mock/light.o mock/EEPROM.o Metro.o Module.o sim/ThermoHeat.o

CPPFLAGS += -DARDUINO=106 -I.
CPPFLAGS += $(patsubst %,-I%,$(subst :, ,$(VPATH)))
CC = g++

all: simulator

simulator: sim/button.o sim/LiquidCrystal.o sim/RealTime.o $(MOCKCOMMON) $(MAIN) $(KILN) $(PRG)

