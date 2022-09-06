#ifndef libKeypad_h;
#define libKeypad_h;
#include "arduino.h";
#include <Key.h>
#include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys[FILAS][COLUMNAS] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'C', '0', '=', '/'},
};

byte pinFilas[FILAS] = {14, 15, 16, 17};
byte pinFilas1[FILAS] = {22, 23, 24, 25};
byte pinColumnas[COLUMNAS] = {18, 19, 20, 21};
byte pinColumnas1[COLUMNAS] = {26, 27, 28, 29};

Keypad keypad = Keypad(makeKeymap(keys), pinFilas, pinColumnas, FILAS, COLUMNAS);
Keypad keypad1 = Keypad(makeKeymap(keys), pinFilas1, pinColumnas1, FILAS, COLUMNAS);

#endif;
