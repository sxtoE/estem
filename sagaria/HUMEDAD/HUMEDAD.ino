#include "DHT.h"//Libreria a utilizar.
#define DHTPIN 2//Pin de conexion.
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando Lectura...");
  dht.begin();
  pinMode(13, OUTPUT);
}
long tiempoUltimaLectura=0;; //Guarda el tiempo de la última lectura.
void loop() {
  if(millis()-tiempoUltimaLectura>2000)
  {    
      float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius.
      float h = dht.readHumidity(); //Leemos la Humedad.
      //Se impmprimen los valores en el monitor serial.
      Serial.print("Temperatura: ");
      Serial.print(t);
      Serial.println(" *C");
      Serial.print("Humedad: ");
      Serial.print(h);
      Serial.println(" %t");
      tiempoUltimaLectura=millis(); //Se actuliza el tiempo de la ultima lectura.
  }
}

