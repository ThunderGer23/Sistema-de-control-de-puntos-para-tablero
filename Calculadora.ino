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
#include <SoftwareSerial.h>

LiquidCrystal LCD(27, 26, 25, 24, 23, 22);

void setup(){
  Serial.begin(9600);
  LCD.begin(16, 2);
}

void loop(){
  LCD.setCursor(0, 0);
  LCD.print("Hola mundo :v");
  LCD.setCursor(0, 1);
  LCD.cursor();
}
