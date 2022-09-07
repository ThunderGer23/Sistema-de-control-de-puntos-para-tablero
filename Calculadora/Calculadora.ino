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
LiquidCrystal lcd1(13, 12, 11, 10, 9, 8);

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
  for(j = 0;j <= 7;j++){
    lcd.createChar(j,yugioh[j]);
    lcd.setCursor(j,0);
    lcd.write(byte(j));
  }
}

void setup() {
  // initiate keypad button matrix
  
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
    lcd.setCursor(15, 0);
    lcd.autoscroll();
    switch(Key){
      case 1:
        writeYugioh();
        break;
      case 2:
        writePokemon();
        break;
      case 3:
        writeMagic();
        break;
      default:
        lcd.setCursor(0,0);
        lcd.write("No valid :(");
    }
    /*for (pos = 0; pos < 10; pos++){
      lcd.clear();
      lcd.write(Key);
      delay(500);
    }*/
    lcd.noAutoscroll();
  }
}
