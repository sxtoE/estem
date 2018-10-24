/*
	 Estación Meteorológica del Colegio Tecnológico del Sur 2018

Autores:
Andrade Eluney
Silvera Facundo
Serino Matías
Guevara Tobías
Sacco Selena

 */
#include "estem_io.h"

#include <Adafruit_BMP085.h>//Cargamos la librería BMP085

Adafruit_BMP085 bmp;           //Iniciamos una instancia de la librería BMP085

void setup()
{
				Serial.begin(9600);
				pinMode(UVOUT, INPUT);
				pinMode(REF_3V3, INPUT);
				Serial.println("MP8511");
//barometro
  Serial.begin(9600);  //Iniciamos la comunicación serie
  if (!bmp.begin()) {  //Si hay un error al iniciar la librería...
  Serial.println("No se puede iniciar el sensor BMP085, compruebe las conexiones!"); //Mostramos un mensaje
  while (1) {} //Detenemos la ejecución
  }
//fin barometro
}
void loop()
{
				int uvNivel = promedioAnalogRead(UVOUT);
				int refNivel = promedioAnalogRead(REF_3V3);
				//Utilice el pin de alimentación de 3.3V como referencia para 
				//obtener un valor de salida muy preciso del sensor
				float outputVoltaje = 3.3 / refNivel * uvNivel;
				float IntencidadUV = mapfloat(outputVoltaje, 0.99, 2.9, 0.0, 15.0);
				Serial.print("Voltaje Recibido: ");
				Serial.print(IntencidadUV);
				Serial.println();
				Serial.print("Indice UV: ");
				Serial.println(outputVoltaje);
				Serial.println();
				delay(400);

//barometro
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
//fin sensor barometro
}

// Toma un promedio de lecturas en un pin dado
// Devuelve el promedio
int promedioAnalogRead(int pinToRead)
{
				byte NumeroLecturas = 8;
				unsigned int ValorCorriente = 0; 
				for(int x = 0 ; x < NumeroLecturas ; x++)
								ValorCorriente += analogRead(pinToRead);
				ValorCorriente /= NumeroLecturas;
				return(ValorCorriente);  
}
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
				return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
