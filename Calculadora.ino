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
#include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys [FILAS][COLUMNAS] = {
  {'1','2','3','-'},
  {'4','5','6','+'},
  {'7','8','9','='},
  {'*','0','(',')'},  
};

byte pinFilas[FILAS] = {6,7,8,9};
byte pinColumnas[COLUMNAS] = {10,11,12,13};

Keypad teclado = Keypad(makeKeymap(keys), pinFilas, pinColumnas, FILAS, COLUMNAS);
char Tecla;


void setup() {
  Serial.begin(9600);
}

void loop() {
  Tecla = teclado.getKey();  
  if(Tecla){
    Serial.print("La tecla presionada es: ");
    Serial.println(Tecla);
    if (Tecla < 47)
    {
      Serial.print("Signo");
    }
  }
}
