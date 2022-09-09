//A header guard. It prevents the header file from being included more than once.
#ifndef libPokemon_h;
#define libPokemon_h;
#include "arduino.h";

//Creating a 2D array of bytes.
byte pokeball[6][8] = {
  {//01
    0b00000,
    0b00011,
    0b00100,
    0b01000,
    0b01000,
    0b10000,
    0b10000,
    0b11100
  },{//02
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b10001
  },{//03
    0b00000,
    0b11000,
    0b00100,
    0b00010,
    0b00010,
    0b00001,
    0b00001,
    0b00111
  },{//11
    0b10011,
    0b10000,
    0b01000,
    0b01000,
    0b00100,
    0b00011,
    0b00000,
    0b00000
  },{//12
    0b10001,
    0b10001,
    0b01110,
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b00000
  },{//13
    0b11001,
    0b00001,
    0b00010,
    0b00010,
    0b00100,
    0b11000,
    0b00000,
    0b00000
  }
}; 

//A header guard. It prevents the header file from being included more than once.
#endif;
