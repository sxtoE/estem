#include "humedad.h"

float humedad_readTemp(){
      return dht.readTemperature(); //Leemos la temperatura en grados Celsius.
}

float humedad_readHumedad(){
      return dht.readHumidity(); //Leemos la Humedad.
}
