
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

const int thermoDO = MISO;
const int thermoCS = A0;
const int thermoCLK = SCK;

const int serialTX = 25;
const int serialRX = 26;

const int backLight = A5;

const int buttonUp = 4; //s1
//int buttonDown = ;//s2
//int buttonLeft = ; //S4
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

/*
Adafruit_MAX31855 thermocouple(thermoCLK, thermoCS, thermoDO);
 */

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
  lcd.blink();
  lcd.print("Hello");
#endif

  pinMode(backLight, OUTPUT);

  pinMode(buttonUp, INPUT);
  pinMode(buttonRight, INPUT);

  /* mySerial.begin(9600);


  mySerial.println("MAX31855 test");
  // wait for MAX chip to stabilize
   * */
}

int i = 0;

void loop() {
  int up = digitalRead(buttonUp);
  int down = digitalRead(buttonRight);

  if (up == LOW) {
    i++;
    while (digitalRead(buttonUp) == LOW);
  } else if (down == LOW) {
    i--;
    while (digitalRead(buttonRight) == LOW);
  }

  int pin;
  switch (i) {
    default:
      i = 0;
    case 0: pin = LCD_D0;
      break;

    case 1: pin = LCD_D1;
      break;
    case 2: pin = LCD_D2;
      break;
    case 3: pin = LCD_D3;
      break;
    case 4: pin = LCD_D4;
      break;
    case 5: pin = LCD_D5;
      break;
    case 6: pin = LCD_D6;
      break;
    case 7: pin = LCD_D7;
      break;

    case 8: pin = LCD_RS;
      break;
    case 9: pin = LCD_RW;
      break;

    case -1:
      i = 10;
    case 10: pin = LCD_EN;
      break;

  }


#ifdef TRY_LCD
  lcd.print(i);
#else

  digitalWrite(pin, HIGH);

  for (int k = 0; k <= i; k++) {
    delay(200);
    digitalWrite(backLight, HIGH);
    delay(100);
    digitalWrite(backLight, LOW);
  }

  // digitalWrite(backLight, HIGH); // turn the LED on (HIGH is the voltage level)
  //  digitalWrite(pin, HIGH); // turn the LED on (HIGH is the voltage level)
  //digitalWrite(LCD_EN, HIGH); // turn the LED on (HIGH is the voltage level)
  // digitalWrite(LCD_RW, HIGH); // turn the LED on (HIGH is the voltage level)
  // delay(sleepTime); // wait for a second
  //digitalWrite(backLight, LOW); // turn the LED off by making the voltage LOW
  // digitalWrite(pin, LOW); // turn the LED off by making the voltage LOW
  // digitalWrite(LCD_EN, LOW); // turn the LED on (HIGH is the voltage level)
  // digitalWrite(LCD_RW, LOW); // turn the LED on (HIGH is the voltage level)
  digitalWrite(pin, LOW);

#endif

  delay(500); // wait for a second
  /*
    // basic readout test, just print the current temp
     mySerial.print("Internal Temp = ");
     mySerial.println(thermocouple.readInternal());

     double c = thermocouple.readCelsius();
     if (isnan(c)) {
       mySerial.println("Something wrong with thermocouple!");
     } else {
       mySerial.print("C = ");
       mySerial.println(c);
     }
     //Serial.print("F = ");
     //Serial.println(thermocouple.readFarenheit());

     delay(1000);*/
}
