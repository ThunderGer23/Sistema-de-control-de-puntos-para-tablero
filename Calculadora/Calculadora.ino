/*
  LiquidCrystal Library - Custom Characters

 Demonstrates how to add custom characters on an LCD  display.
 The LiquidCrystal library works with all LCD displays that are
 compatible with the  Hitachi HD44780 driver. There are many of
 them out there, and you can usually tell them by the 16-pin interface.

 This sketch prints "I <heart> Arduino!" and a little dancing man
 to the LCD.

  The circuit:
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

 created 21 Mar 2011
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald
 modified 7 Nov 2016
 by Arturo Guadalupi

 Based on Adafruit's example at
 https://github.com/adafruit/SPI_VFD/blob/master/examples/createChar/createChar.pde

 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/LiquidCrystalCustomCharacter

 Also useful:
 http://icontexto.com/charactercreator/

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
int j;
//Creating an instance of the LiquidCrystal library.
//pinout rs=7, en=6, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
//Creating a second instance of the LiquidCrystal library.
//pinout rs=13, en=12, d4=11, d5=10, d6=9, d7=8;
LiquidCrystal lcd1(9, 8, 5, 4, 3, 2);

void writePokemon(){
  for(j = 0;j <= 5;j++){
    lcd.createChar(j,pokeball[j]);
  }
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));

  lcd.setCursor(0,1);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
}

void writeMagic(){
  for(j = 0;j <= 5;j++){
    lcd.createChar(j,magicM[j]);
  }
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));

  lcd.setCursor(0,1);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
}

void writeYugioh(){
  for(j=0;j<=7;j++){
    lcd.setCursor(j,0);
    lcd.createChar(j,yugioh[j]);
    Serial.print(j);
    lcd.write(byte(j));
  }
}

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);
  lcd1.begin(16, 2);
}

byte load1[8] = {
  B01111,
  B01101,
  B00100,
  B00100,
  B00110,
  B00011,
  B00001,
  B00000
};

byte load2[8] = {
  B11111,
  B01010,
  B10101,
  B01010,
  B00100,
  B00000,
  B10101,
  B11011
};

byte load3[8] = {
  B11110,
  B10110,
  B00100,
  B00100,
  B01100,
  B11000,
  B10000,
  B00000
};

byte load4[8] = {
  B00000,
  B00001,
  B00011,
  B00110,
  B00100,
  B00100,
  B01100,
  B01111
};

byte load5[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte load6[8] = {
  B00000,
  B10000,
  B11000,
  B01100,
  B00100,
  B00100,
  B00110,
  B11110
};

byte load1a[8] = {
  B01111,
  B01100,
  B00100,
  B00100,
  B00110,
  B00011,
  B00001,
  B00000
};

byte load2a[8] = {
  B11111,
  B01010,
  B10101,
  B01010,
  B00100,
  B00000,
  B10001,
  B11011
};

byte load5a[8] = {
  B11011,
  B10101,
  B00000,
  B00000,
  B00000,
  B00000,
  B01000,
  B11111
};

byte load2b[8] = {
  B11111,
  B01000,
  B10101,
  B01010,
  B00100,
  B00000,
  B10101,
  B11011
};

byte load5b[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00000,
  B00000,
  B01010,
  B11111
};

byte load2c[8] = {
  B11111,
  B01000,
  B10101,
  B01010,
  B00100,
  B00000,
  B10001,
  B11011
};

byte load3c[8] = {
  B11110,
  B00110,
  B00100,
  B00100,
  B01100,
  B11000,
  B10000,
  B00000
};

byte load5c[8] = {
  B11011,
  B10101,
  B00000,
  B00000,
  B00000,
  B00100,
  B01010,
  B11111
};

byte load2d[] = {
  B11111,
  B00000,
  B10101,
  B01010,
  B00100,
  B00000,
  B10101,
  B11011
};

byte load5d[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00000,
  B00100,
  B01010,
  B11111
};

byte load6d[8] = {
  B00000,
  B10000,
  B11000,
  B01100,
  B00100,
  B00100,
  B10110,
  B11110
};

byte load2e[8] = {
  B11111,
  B00000,
  B10001,
  B01010,
  B00100,
  B00000,
  B10001,
  B11011
};

byte load5e[8] = {
  B11011,
  B10101,
  B00000,
  B00000,
  B00000,
  B10100,
  B01010,
  B11111
};

byte load2f[8] = {
  B11111,
  B00000,
  B00001,
  B01010,
  B00100,
  B00000,
  B10101,
  B11011
};

byte load4f[8] = {
  B00000,
  B00001,
  B00011,
  B00110,
  B00100,
  B00100,
  B01101,
  B01111
};
byte load5f[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00000,
  B10100,
  B01010,
  B11111
};

byte load2g[8] = {
  B11111,
  B00000,
  B00000,
  B01010,
  B00100,
  B00000,
  B10001,
  B11011
};

byte load5g[8] = {
  B11011,
  B10101,
  B00000,
  B00000,
  B00000,
  B10101,
  B01010,
  B11111
};

byte load2h[8] = {
  B11111,
  B00000,
  B00000,
  B01000,
  B00100,
  B00000,
  B10101,
  B11011
};

byte load5h[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00010,
  B10101,
  B01010,
  B11111
};

byte load2i[8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00100,
  B00000,
  B10101,
  B11011
};

byte load5i[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B01010,
  B10101,
  B01010,
  B11111
};

byte load2j[8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10001,
  B11011
};

byte load5j[8] = {
  B11011,
  B10101,
  B00000,
  B00100,
  B01010,
  B10101,
  B01010,
  B11111
};

byte giro1[8] = {
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte giro2[8] = {
  B10000,
  B01000,
  B00100,
  B00100,
  B00100,
  B00100,
  B00110,
  B00011
};

byte giro3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11110
};

byte giro4[8] = {
  B01111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte giro5[8] = {
  B10000,
  B11000,
  B01000,
  B01010,
  B01001,
  B01010,
  B00101,
  B00010
};

byte giro6[8] = {
  B00001,
  B00000,
  B00000,
  B10101,
  B01010,
  B00100,
  B01001,
  B10010
};

byte giro1a[8] = {
  B00000,
  B00000,
  B11000,
  B11110,
  B10011,
  B10000,
  B10000,
  B10000
};

byte giro2a[8] = {
  B00000,
  B00000,
  B00000,
  B00001,
  B10011,
  B11110,
  B01100,
  B00000
};

byte giro3a[8] = {
  B00000,
  B00011,
  B01111,
  B11001,
  B10011,
  B00001,
  B00011,
  B00001
};

byte giro4a[8] = {
  B10000,
  B10000,
  B10001,
  B10011,
  B11110,
  B11000,
  B00000,
  B00000
};

byte giro5a[8] = {
  B01100,
  B11110,
  B10011,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000
};
byte giro6a[8] = {
  B01011,
  B00101,
  B10011,
  B11101,
  B01011,
  B00111,
  B00000,
  B00000
};
///// giro3///
byte giro1b[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01111
};
byte giro2b[8] = {
  B00001,
  B00010,
  B00100,
  B00100,
  B00100,
  B00100,
  B01100,
  B11000
};
byte giro3b[8] = {
  B00011,
  B00001,
  B00000,
  B00101,
  B01010,
  B10101,
  B01010,
  B10101
};
byte giro4b[8] = {
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00001,
  B10011
};
byte giro5b[8] = {
  B00011,
  B00110,
  B00100,
  B00100,
  B00100,
  B00100,
  B01000,
  B10000
};
byte giro6b[8] = {
  B11110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void loop(){
  Menu();
}

void Menu(){
  
  lcd1.setCursor(4, 0);
  lcd1.print("Waiting!");
  for(int i = 0; i <= 2; i++){
    Load();
  }
  Welcome();
}

void Welcome(){
  lcd.setCursor(0,0);
  lcd1.setCursor(0,0);
  lcd.print("Bienvenido a la Mesa");
  lcd1.print("Bienvenido a la Mesa");
  delay(100);
  lcd.setCursor(4,1);
  lcd1.setCursor(4,1);
  lcd.print("de Super Juegos");
  lcd1.print("de Super Juegos");
  delay(100);
  lcd.clear();
  lcd1.clear();
  lcd.setCursor(0,0);
  lcd1.setCursor(0,0);
  lcd.print("Chop Chop Shop");
  lcd1.print("Chop chop Shop");
  delay(100);
  lcd.clear();
  lcd1.clear();
}

void Load(){
  lcd.clear();
  lcd.createChar(0, load1);
  lcd.createChar(1, load2);
  lcd.createChar(2, load3);
  lcd.createChar(3, load4);
  lcd.createChar(4, load5);
  lcd.createChar(5, load6);
  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);
  
  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2a);
  lcd.createChar(2,load3);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5a);
  lcd.createChar(5,load6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);
  
  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2b);
  lcd.createChar(2,load3);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5b);
  lcd.createChar(5,load6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2c);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5c);
  lcd.createChar(5,load6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2d);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5d);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);
  
  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2e);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5e);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2f);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5f);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2g);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5g);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2h);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5h);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);
  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2i);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5i);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2j);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5j);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);

  lcd.clear();
  lcd.createChar(0,giro1);
  lcd.createChar(1,giro2);
  lcd.createChar(2,giro3);
  lcd.createChar(3,giro4);
  lcd.createChar(4,giro5);
  lcd.createChar(5,giro6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);
  
  lcd.clear();
  lcd.createChar(0,giro1a);
  lcd.createChar(1,giro2a);
  lcd.createChar(2,giro3a);
  lcd.createChar(3,giro4a);
  lcd.createChar(4,giro5a);
  lcd.createChar(5,giro6a);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);
  
  lcd.clear();
  lcd.createChar(0,giro1b);
  lcd.createChar(1,giro2b);
  lcd.createChar(2,giro3b);
  lcd.createChar(3,giro4b);
  lcd.createChar(4,giro5b);
  lcd.createChar(5,giro6b);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(100);
}