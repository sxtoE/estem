#include <Wire.h>           //Cargamos la librería Wire
#include <Adafruit_BMP085.h>//Cargamos la librería BMP085

Adafruit_BMP085 bmp;           //Iniciamos una instancia de la librería BMP085
  
void setup() {
  Serial.begin(9600);  //Iniciamos la comunicación serie
  if (!bmp.begin()) {  //Si hay un error al iniciar la librería...
  Serial.println("No se puede iniciar el sensor BMP085, compruebe las conexiones!"); //Mostramos un mensaje
  while (1) {} //Detenemos la ejecución
  }
}
  
void loop() {
    //Leemos los valores del sensor y sacamos la temperatura por el monitor serie
    Serial.print("Temperatura = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    //Leemos los valores del sensor y sacamos la presión atmosférica por el monitor serie    
    Serial.print("Presión = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    //Calculamos la altitud asumiendo la presión barométrica 'standard' a 1013.25 milibares
    Serial.print("Altitud = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" metros");
    
    //Calculamos la presión a nivel del mar usando una función de la librería
    Serial.print("Presión a nivel del mar (calculada) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

    //Podemos obtener una medición de la altitud aun más precisa si conocemos la presión real a nivel del mar
    //Si es de 1015 millibars eso equivale a 101500 Pascals
    Serial.print("Altitud real = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" metros");
    
    Serial.println();  //Espaciado entre lecturas
    delay(10000);      //Pausa de 10 segundos entre lecturas
}
