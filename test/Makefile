TARGET = target

VPATH = ../lib/Metro ../lib/Module ../src ../src/kilnoperation ../src/programpage mock

TESTS = $(patsubst %.cpp,%.o,$(wildcard testcases/*.cpp))
MAIN = $(patsubst ../src/%.cpp,%.o,$(wildcard ../src/*.cpp))
KILN = $(patsubst ../src/kilnoperation/%.cpp,%.o,$(wildcard ../src/kilnoperation/*.cpp))
PRG = $(patsubst ../src/programpage/%.cpp,%.o,$(wildcard ../src/programpage/*.cpp))

MOCKCOMMON = mock/light.o mock/EEPROM.o Metro.o Module.o sim/ThermoHeat.o $(MAIN) $(KILN) $(PRG)

CPPFLAGS += -DARDUINO=106 -I.
CPPFLAGS += $(patsubst %,-I%,$(subst :, ,$(VPATH)))
CC = g++

all: simulator testrunner

test: testrunner
	./testrunner

simulator: sim/button.o sim/LiquidCrystal.o sim/RealTime.o $(MOCKCOMMON)

testrunner: $(TESTS) sim/button.o sim/LiquidCrystal.o sim/RealTime.o $(MOCKCOMMON)
