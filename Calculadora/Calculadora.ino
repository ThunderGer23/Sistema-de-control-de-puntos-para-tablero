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

// include the library code:
#include <LiquidCrystal.h>;
#include <SoftwareSerial.h>;
#include "libYugioh.h"
#include "libPokemon.h"

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, S00);
  lcd.createChar(1, S01);
  lcd.createChar(2, S02);
  lcd.createChar(3, S03);
  lcd.createChar(4, S04);
  lcd.createChar(5, S05);
  lcd.createChar(6, S06);
  lcd.createChar(7, S07);
  lcd.createChar(8, S08);
  lcd.createChar(9, S09);
  lcd.createChar(10,S10);
  lcd.setCursor(0,0);
  Serial.begin(9600);
}

void loop(){
  lcd.write(byte(0));
  delay(100);
  lcd.write(byte(1));
  delay(100);
  lcd.write(byte(2));
  delay(100);
  lcd.write(byte(3));
  delay(100);
  lcd.write(byte(4));
  delay(100);
  lcd.write(byte(5));
  delay(100);
  lcd.write(byte(6));
  delay(100);
  lcd.write(byte(7));
  delay(100);
  lcd.write(byte(8));
  delay(100);
  lcd.write(byte(9));
  delay(100);
  lcd.write(byte(10));
  delay(100);
  lcd.write(byte(11));
  delay(100);
  delay(100000);
}
