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
int pos, j, scroll=0,vida;
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
    lcd.createChar(j,yugioh[j]);
    lcd.setCursor(j,0);
    lcd.write(byte(j));
  }
}

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);
  lcd1.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  //Menu();
  selectGame();
}

void Menu(){

  lcd1.clear();
  lcd.clear();
  lcd1.setCursor(4, 0);
  lcd1.print("Waiting!");
  for(int i = 0; i <= 2; i++){
    Load();
  }
  Welcome();
  lcd1.setCursor(2, 0);
  lcd1.print("Esperando configuración");

  //Aquí hay que poner a pintar las opciones en la primer LCD

}

void Welcome(){
  lcd.clear();
  lcd1.clear();
  lcd.setCursor(0,0);
  lcd1.setCursor(0,0);
  lcd.print("Bienvenido a la Mesa");
  lcd1.print("Bienvenido a la Mesa");
  delay(500);
  lcd.setCursor(4,1);
  lcd1.setCursor(4,1);
  lcd.print("de Super Juegos");
  lcd1.print("de Super Juegos");
  delay(500);
  lcd.setCursor(0,0);
  lcd1.setCursor(0,0);
  lcd.print("Chop Chop Shop");
  lcd1.print("Chop chop Shop");
  delay(500);
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

void selectGame(){
  char Key = keypad.getKey();

  if(scroll==0){
    lcd.setCursor(0,0);
    lcd.write("Selecciona un");
    lcd.setCursor(0,1);
    lcd.write("  modo de juego...");
  }
  
  if(Key){
    lcd.clear();
    switch(Key){
      case '2':
        scroll -= 1;
        break;
      case '8':
        scroll += 1;
        break;
      case '5':
        lcd.setCursor(0,0);
        lcd.print(scroll);
        delay(1000);
    }
    if(scroll<0){scroll=3;}
    if(scroll>3){scroll=0;}
    
    switch(scroll){
      case 1:
        writePokemon();
        vida=8000;
        lcd.setCursor(12,0);
        lcd.print(vida);
        break;
      case 2:
        writeMagic();
        vida=20;
        lcd.setCursor(14,0);
        lcd.print(vida);
        break;
      case 3:
        writeYugioh();
        vida=8000;
        lcd.setCursor(12,0);
        lcd.print(vida);
        break;
      default:
        lcd.setCursor(0,0);
        lcd.write("Selecciona un");
        lcd.setCursor(0,1);
        lcd.write("  modo de juego...");
        break;
        
    }
  }
}
