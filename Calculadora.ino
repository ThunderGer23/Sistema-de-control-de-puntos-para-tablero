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

//Declare constants for the Keypad
const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys[FILAS][COLUMNAS] = {
    {'1', '2', '3', '-'},
    {'4', '5', '6', '+'},
    {'7', '8', '9', '&'},
    {'*', '0', '!', '='},
};

byte pinFilas[FILAS] = {6, 7, 8, 9};
byte pinColumnas[COLUMNAS] = {10, 11, 12, 13};

Keypad keypad = Keypad(makeKeymap(keys), pinFilas, pinColumnas, FILAS, COLUMNAS);
Keypad teclado2 = Keypad(makeKeymap(keys), pinFilas, pinColumnas, FILAS, COLUMNAS);
char Key, Key2;
int Number, Num1, Num2, Number1, Num3, Num4;
int Value = 1;
int Value1 = 1;
int Opera = 0;
int Opera1 = 0;
String Val1, Val2, Val3, Val4;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Key = keypad.getKey();     //-> Obtiene el valor del teclado
  if (Key){                   //Si se presiona la tecla evaluamos que se presiono
    if (Key < 47){            //Si fue un signo?                  
      if(Key >= 42){          //Si se pidio alguna operación
        if(Value){              
          Num1 = Val1.toInt();
          Val1= "";
          Value = 0;
          if(Key == 42){
            Serial.print("*");  
          }else if(Key == 43){
            Serial.print("+");
            Opera += 1;  
          }else{
            Serial.print("-");  
            Opera += 2;
          }
        }else{
          if(Key == 42){
            Serial.print("*");  
          }else if(Key == 43){
            Serial.print("+");
            Opera += 1;  
          }else{
            Serial.print("-");  
            Opera += 2;
          }
        }
      }else if(Key == 38){        
        if(Value){          
          Serial.print("Numero 1: ");
          Val1.remove(Val1.length()-1);
          Serial.println(Val1);
        }else{          
          Serial.print("Numero 2: ");
          Val2.remove(Val2.length()-1);
          Serial.println(Val2);
        }
      }else if(Key == 33){        
        Val1 = "";
        Val2 = "";
        Value = 1;
      }
    }else if (Key == 61){
      //Resultado de la operación   
      Num2 = Val2.toInt();   
      if(Num1 >= 0 && Num2 >= 0 || Num1 <= 0 && Num2 <= 0 || Num1 <= 0 && Num2 >= 0 || Num1 >= 0 && Num2 <= 0){       
        Val2= "";      
        int Res;  
        if(Opera == 1){
          Res = Num1+Num2;
          Serial.print("El resltado es:");
          Serial.println(Res);
        }else if(Opera == 2){
          Res = Num1-Num2;
          Serial.print("El resltado es:");         
          Serial.println(Res);
        }else{
          Res = Num1*Num2;
          Serial.print("El resltado es:");
          Serial.println(Res);
        }      
        Num1 = Res;
        Opera = 0;      
      }
    }else{
      //Concatena numeros en una variable
      if (Value){        
        Serial.print("Numero 1: ");
        Number = Key - 48;
        Val1 += Number;
        Serial.println(Val1);
      }else{
        Serial.print("Numero 2: ");
        Number = Key - 48;
        Val2 += Number;
        Serial.println(Val2);
      } 
    }
  }
}
