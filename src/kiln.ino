
/***************************************************
  This is an example for the Adafruit Thermocouple Sensor w/MAX31855K

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

#include <Arduino.h>
//#include <SoftwareSerial.h>
#include "Adafruit_MAX31855.h"
#include "LiquidCrystal.h"
#include "PinChangeInt.h"

const int thermoDO = MISO;
const int thermoCS = 5;
const int thermoCLK = SCK;

const int backLight = A5;

const int buttonUp = 4; //s1
const int buttonDownBMask = bit(6); //s2
const int buttonLeftBMask = bit(7); //S4
const int buttonRight = 6; //s5

int sleepTime = 1000;

const int LCD_RS = A3;
const int LCD_RW = A4;
const int LCD_EN = 11;

const int LCD_D0 = 0;
const int LCD_D1 = 10;

const int LCD_D2 = 1;
const int LCD_D3 = 9;
const int LCD_D4 = 2;
const int LCD_D5 = 8;

const int LCD_D6 = 3;
const int LCD_D7 = 7;

#define TRY_LCD

#ifdef TRY_LCD
LiquidCrystal lcd(LCD_RS, LCD_RW, LCD_EN,
        LCD_D0, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
#endif
//SoftwareSerial mySerial(serialRX, serialTX); // RX, TX


Adafruit_MAX31855 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
#ifndef TRY_LCD
  pinMode(LCD_D0, OUTPUT);
  pinMode(LCD_D1, OUTPUT);
  pinMode(LCD_D2, OUTPUT);
  pinMode(LCD_D3, OUTPUT);
  pinMode(LCD_D4, OUTPUT);
  pinMode(LCD_D5, OUTPUT);
  pinMode(LCD_D6, OUTPUT);
  pinMode(LCD_D7, OUTPUT);

  pinMode(LCD_RS, OUTPUT);
  pinMode(LCD_RW, OUTPUT);
  pinMode(LCD_EN, OUTPUT);
#else
  delay(500);
  lcd.begin(20, 2);
  lcd.noBlink();
  lcd.print("Hello");
#endif

  pinMode(backLight, OUTPUT);

  pinMode(buttonUp, INPUT);
  pinMode(buttonRight, INPUT);

  PCintPort::attachInterruptByMask(PORTB, buttonLeftBMask, &left);
  PCintPort::attachInterruptByMask(PORTB, buttonDownBMask, &down);
  PCintPort::attachInterrupt(buttonRight, &right);
  PCintPort::attachInterrupt(buttonUp, &up);
}

int i = 0;
int j = 0;

void up() {
  j += 10;
}

void down() {
  j -= 10;
}

void right() {
  j++;
}

void left() {
  j--;
}

void loop() {
  i++;
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print(i % 10);
  lcd.print(" I = ");
  lcd.print(thermocouple.readInternal());
  lcd.print("  ");

  double c = thermocouple.readCelsius();
  lcd.setCursor(0, 1);
  lcd.print(j);
  lcd.print(" C = ");
  lcd.print(c);
  lcd.print("   ");

}
