//-------------Calibración MQ135 Tobías Guevara 6to E -------------------------


#include<MQ135.h>


//---------Funciones para facilitar uso--------

#define entrada(a){pinMode(a,INPUT);}
#define salida(a){pinMode(a,OUTPUT);}

#define imprime(a){Serial.println(a);}
#define serie(a){Serial.begin(a);}


//----------------Variables--------------------

#define lecturaCalibracion A0

MQ135 sensorMQ = MQ135(lecturaCalibracion);
float resistencia_cero;

void setup() {
				entrada(lecturaCalibracion);
				serie(9600);  
}


void loop() {
				float resistencia_cero = sensorMQ.getRZero();
				imprime(resistencia_cero);
}
