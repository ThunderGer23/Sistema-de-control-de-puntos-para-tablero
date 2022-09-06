/*        Arduino Mega 2560

Código para la implementación de calculadora

Funcionamiento sugerido para el ahorro de pines
y posterior traslado a un Arduino Pro Micro:

  1.- Activar o desactivar los teclados matriciales
      a fin de ahorrar pines y gestionar el control
      de los mismos (Evitando errores humanos).
  2.- Compartir bus de datos para las LCD 16x8
      esto solo puede hacerse gracias al uso
      especifico de este modelo de display, ya que
      si se requiere un modelo de 128x64 será
      necesario contar con 2 puertos ISP para su
      control.


  Pin's for the circuit:
 * LCD RS pin to digital pin 1
 * LCD Enable pin to digital pin 0
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K potentiometer:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 10K poterntiometer on pin A0
*/

//Including the libraries that are needed for the program to run.:
#include <LiquidCrystal.h>;
#include <SoftwareSerial.h>;
#include "libYugioh.h"
#include "libPokemon.h"
#include "libMagic.h"
#include "libKeypad.h"

char Key, Key2;
int pos;
//Creating an instance of the LiquidCrystal library.
//pinout rs=7, en=6, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
//Creating a second instance of the LiquidCrystal library.
//pinout rs=13, en=12, d4=11, d5=10, d6=9, d7=8;
LiquidCrystal lcd1(13, 12, 11, 10, 9, 8);

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  Menu();
}

int Menu(){
  Key = keypad.getKey();
  if(Key){//-> Obtiene el valor del teclado
    lcd.setCursor(16, 1);
    lcd.autoscroll();
    for (pos = 0; pos < 10; pos++){
      lcd.write(Key);
      delay(500);
    }
    lcd.noAutoscroll();
    lcd.clear();
  }
}


