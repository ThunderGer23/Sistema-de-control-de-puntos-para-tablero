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
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys [FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},  
};

byte pinFilas[FILAS] = {9,8,7,6};
byte pinColumnas[COLUMNAS] = {5,4,3,2};

Keypad teclado = Keypad(makeKeymap(keys), pinFilas, pinColumnas, FILAS, COLUMNAS);
char Tecla;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 1, en = 0, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// make some custom characters:
byte heart[8] = {
  0b00000,
  0b11000,
  0b01100,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00111
};

byte smiley[8] = {
  0b00000,
  0b01100,
  0b11000,
  0b00000,
  0b00110,
  0b00010,
  0b00010,
  0b10001
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00011,
  0b11000,
  0b10000,
  0b10000,
  0b11000
};

byte armsDown[8] = {
  0b00000,
  0b01100,
  0b10010,
  0b10000,
  0b10000,
  0b10110,
  0b10010,
  0b01100
};

byte armsUp[8] = {
  0b00000,
  0b00000,
  0b10000,
  0b00011,
  0b11000,
  0b10000,
  0b10000,
  0b10000
};

byte letter[8] = {
  0b00000,
  0b01100,
  0b10010,
  0b10010,
  0b10010,
  0b10010,
  0b10010,
  0b01100
};

byte lettera[8] = {
  0b00000,
  0b11000,
  0b01000,
  0b01000,
  0b01100,
  0b01010,
  0b01010,
  0b11011
};

byte letterb[8] = {
  0b11111,
  0b01110,
  0b01110,
  0b00100,
  0b00100,
  0b00000,
  0b01110,
  0b01110
};

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, heart);
  // create a new character
  lcd.createChar(1, smiley);
  // create a new character
  lcd.createChar(2, frownie);
  // create a new character
  lcd.createChar(3, armsDown);
  // create a new character
  lcd.createChar(4, armsUp);
  // create a new character
  lcd.createChar(5, letter);
  // create a new character
  lcd.createChar(6, lettera);
  // create a new character
  lcd.createChar(7, letterb);

  // set the cursor to the top left
  lcd.setCursor(0, 0);

  // Print a message to the lcd.
  //lcd.print("I ");
  lcd.write(byte(0)); // when calling lcd.write() '0' must be cast as a byte
  //lcd.print(" Arduino! ");
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.write((byte)6);
  lcd.write((byte)7);
  Serial.begin(9600);
}

void loop() {
  Tecla = teclado.getKey();
  //lcd.setCursor(1, 0);
  if(Tecla){
    Serial.print("La tecla presionada es: " + Tecla);
  }else{
    Serial.print("Esperando tecla presionada");
  }
}
