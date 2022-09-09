//This is a preprocessor directive. It is used to prevent the header file from being included more than once.
#ifndef libYugioh_h;
#define libYugioh_h;
#include "arduino.h";

//Creating a custom character.
byte yugioh[8][8] = {
  {
    0b00000,
    0b11000,
    0b01100,
    0b00011,
    0b00011,
    0b00011,
    0b00011,
    0b00111
  },{
    0b00000,
    0b01100,
    0b11000,
    0b00000,
    0b00110,
    0b00010,
    0b00010,
    0b10001
  },{
    0b00000,
    0b00000,
    0b00000,
    0b00011,
    0b11000,
    0b10000,
    0b10000,
    0b11000
  },{
    0b00000,
    0b01100,
    0b10010,
    0b10000,
    0b10000,
    0b10110,
    0b10010,
    0b01100
  },{
    0b00000,
    0b00000,
    0b10000,
    0b00011,
    0b11000,
    0b10000,
    0b10000,
    0b10000
  },{
    0b00000,
    0b01100,
    0b10010,
    0b10010,
    0b10010,
    0b10010,
    0b10010,
    0b01100
  },{
    0b00000,
    0b11000,
    0b01000,
    0b01000,
    0b01100,
    0b01010,
    0b01010,
    0b11011
  },{
    0b11111,
    0b01110,
    0b01110,
    0b00100,
    0b00100,
    0b00000,
    0b01110,
    0b01110
  }
};

A preprocessor directive. It is used to terminate the header file.
#endif;
