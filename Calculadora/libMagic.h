#ifndef libMagic_h;
#define libMagic_h;
#include "arduino.h";

// make some custom characters:

byte magicM[6][8] = {
  {
    0b00000,
    0b00000,
    0b00001,
    0b00001,
    0b01001,
    0b01011,
    0b01011,
    0b01111
  },{
    0b00100,
    0b00100,
    0b00100,
    0b01110,
    0b01110,
    0b01110,
    0b11111,
    0b11111
  },{
    0b00000,
    0b00000,
    0b10000,
    0b10000,
    0b10010,
    0b11010,
    0b11010,
    0b11110
  },{
    0b01111,
    0b01111,
    0b00011,
    0b00001,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  },{
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00100
  },{
    0b11110,
    0b11110,
    0b11000,
    0b10000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  }
};
//TODO: Si se lograra empaquetar en una sola matriz ser[ia ]

#endif;
