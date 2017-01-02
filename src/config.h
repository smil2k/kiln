#ifndef CONFIG_H
#define CONFIG_H

#define PORTB 2
#define PORTC 3
#define PORTD 4

const int thermoDO = MISO;
const int thermoCS = 5;
const int thermoCLK = SCK;

const int PIN_BACKLIGHT = A5;

const int PIN_BUTTON_UP = 4;
const int PIN_MASK_BUTTON_DOWN = bit(6);
const int PIN_PORT_BUTTON_DOWN = PORTB;

const int PIN_MASK_BUTTON_LEFT = bit(7);
const int PIN_PORT_BUTTON_LEFT = PORTB;
const int PIN_BUTTON_RIGHT = 6;

const int PIN_TONE = 11;

const int PIN_HEATER = PIN_BACKLIGHT;

const int LCD_RS = A3;
const int LCD_EN = A4;

const int LCD_D0 = 0;
const int LCD_D1 = 10;

const int LCD_D2 = 1;
const int LCD_D3 = 9;
const int LCD_D4 = 2;
const int LCD_D5 = 8;

const int LCD_D6 = 3;
const int LCD_D7 = 7;


#endif	// CONFIG_H

