//A header guard. It prevents the header file from being included more than once.
#ifndef libAbout_h;
#define libAbout_h;
#include "arduino.h";

// make some custom characters:
byte about[6][8] ={
    {
        0b11111,
        0b10011,
        0b00011,
        0b00011,
        0b00011,
        0b00011,
        0b00111,
        0b00000
    },{
        0b11100,
        0b00100,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b10000,
        0b00000
    },{
        0b00011,
        0b00011,
        0b00011,
        0b00011,
        0b00011,
        0b00011,
        0b00011,
        0b00000
    },{
        0b11110,
        0b00011,
        0b00011,
        0b00011,
        0b11110,
        0b00110,
        0b00011,
        0b00000
    },{
        0b00011,
        0b00110,
        0b01100,
        0b01100,
        0b01100,
        0b01100,
        0b00110,
        0b00011
    },{
        0b11100,
        0b00110,
        0b00010,
        0b00000,
        0b01110,
        0b00110,
        0b00110,
        0b11100
    }
};

//A header guard. It prevents the header file from being included more than once.
#endif;
