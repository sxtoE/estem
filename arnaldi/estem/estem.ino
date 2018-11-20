/*-----------------------------------------------------------------------------
--	 Estación Meteorológica del Colegio Tecnológico del Sur 2018
--
-- Autores:
-- 6toE - 2018 - CTS
-- Andrade Eluney
-- Argañaraz José
-- Ferrada Joaquín
-- Guevara Tobías
-- Miranda Luciano
-- Sacco Selena
-- Sagaría Facundo
-- Serino Matías
-- Silvera Facundo
-- 
-- Profesor: Ing. L. Horacio Arnaldi
-- 
-------------------------------------------------------------------------------*/

#include "estem_io.h"

<<<<<<< HEAD
Adafruit_BMP085 bmp;           //Iniciamos una instancia de la librería BMP085
//MQ135 sensorMQ = MQ135(MQ_CAL);
DHT dht(DHTPIN, DHTTYPE);
//EthernetClient client;      //Iniciamos como cliente
//char server[] = "192.168.40.2"; // Ip address del servidor
//int t_espera = 1000;      //Tiempo de espera entre envio de datos
float v_dioxido = 0, v_monoxido = 0, v_amoniaco = 0;


=======
DHT dht(PIN_DHT, DHTTYPE);
>>>>>>> 5876fb2e0df9d006f2e0fd23b6ebfc2111e075bb

float v_dioxido = 0, v_monoxido = 0, v_amoniaco = 0;
int intervaloLecturas = 5000; //5s
long t_UltimaLectura  = 0;    //Guarda el tiempo de la última lectura.
float mq_rcero = 0.0;
float dht_temp = 0.0;
float dht_hume = 0.0;
float bmp_temp = 0.0;
float bmp_pres = 0.0; 
float bmp_presnm = 0.0;
float uv_vout = 0.0;
float uv_intensidad = 0.0;
float lm35_temp = 0.0;
float v_lluvia = 0.0;
float v_viento = 0.0;
int   d_viento = 0;
float mq_rs;
float mq_ppm;
int uv_Nivel, uv_refNivel;

void setup()
{
				//configuramos pines de I/O
				pinMode(PIN_UVOUT, INPUT);
				pinMode(PIN_REF3V3, INPUT);
				pinMode(PIN_MQ, INPUT);
				pinMode(STATUS_LED, OUTPUT);
				pinMode(PIN_VVIENTO, INPUT_PULLUP);
				pinMode(PIN_DVIENTO, INPUT_PULLUP);


				//Iniciamos la comunicación serie
				Serial.begin(9600);

								Serial.println("MP8511");
				//barometro
       bmp.begin();
				//if (!bmp.begin()) {  //Si hay un error al iniciar la librería...
				//Mostramos un mensaje
				//Serial.println("No se puede iniciar el sensor BMP085, compruebe las conexiones!"); 
				//while (1) {} //Detenemos la ejecución
				//}
				//fin barometro

				//ethernet
				//Ethernet.begin(mac,myIP);
				eth_inicializarEthernetShield(); //Función que inicializa la placa. 
				//fin ethernet

				//humedad
				//Serial.begin(9600);
				//Serial.println("Iniciando Lectura...");
				dht.begin();
				///fin humedad

				attachInterrupt(digitalPinToInterrupt(PIN_VVIENTO), vv_countPulses, FALLING); // Execute countPulses() if in1 Goes to GND
				//------------------------------------

}

void loop()
{

				if(millis()-t_UltimaLectura>intervaloLecturas)
				{  
								//Primero leemos los sensores
								readSensors();
								//debug
								printDataSerial();
								//end debug
								//ethernet
								eth_enviarDatos(dht_temp, dht_hume, bmp_pres, uv_intensidad, v_viento, v_lluvia, v_dioxido, v_monoxido, v_amoniaco, d_viento); //Función que envía los datos al servidor

								//fin ethernet
								t_UltimaLectura=millis(); //Se actuliza el tiempo de la ultima lectura.
				}
}

void readSensors()
{
				//Sensor UV
				uv_Nivel = uv_promedioAnalogRead(PIN_UVOUT);
				uv_refNivel = uv_promedioAnalogRead(PIN_REF3V3);
				//Utiliza el pin de alimentación de 3.3V como referencia para 
				//obtener un valor de salida muy preciso del sensor
				uv_vout = (3.3 / uv_refNivel)*uv_Nivel;
				uv_intensidad = uv_mapfloat(uv_vout, 0.99, 2.9, 0.0, 15.0);
				//BMP
				bmp_temp = bmp.readTemperature();
				bmp_pres = bmp.readPressure();
        bmp_pres = bmp_pres/100.0;
				bmp_presnm = bmp.readSealevelPressure();
				//MQ135
				//mq_rcero = sensorMQ.getRZero();
				mq_rs = mq_readMQ(PIN_MQ);      // Obtener la Rs promedio
				mq_ppm = mq_getConcentration(mq_rs/R0);   // Obtener la concentración


				//DHT
				dht_temp = humedad_readTemp();
				dht_hume = humedad_readHumedad();
				//LM35
				lm35_temp = lm35_readTemp();
				//vel_viento
				v_viento = vv_medirVelocidad();
				//dir_viento
				d_viento = dir_direccion();

}

void printDataSerial()
{

				//UV
				Serial.print("UV Voltaje Recibido:\t ");
				Serial.print(uv_vout);
				Serial.println(" V");
				Serial.print("UV Indice UV:\t\t ");
				Serial.print(uv_intensidad);
				Serial.println(" mW/cm^2");
				//BMP
				//Leemos los valores del sensor y sacamos la temperatura por el monitor serie
				Serial.print("BMP Temperatura =\t ");
				Serial.print(bmp_temp);
				Serial.println(" *C");

				//Leemos los valores del sensor y sacamos la presión atmosférica por el monitor serie    
				Serial.print("BMP Presión =\t\t ");
				Serial.print(bmp_pres);
				Serial.println(" hPa");

				//Calculamos la altitud asumiendo la presión barométrica 'standard' a 1013.25 milibares
				//No hace falta
				Serial.print("Altitud =\t\t ");
				Serial.print(bmp.readAltitude());
				Serial.println(" m");
				 
				/*
				//Calculamos la presión a nivel del mar usando una función de la librería
				Serial.print("BMP Presión a nivel del mar (calculada) = ");
				Serial.print(bmp_presnm);
				Serial.println(" Pa");
				 */
				//Podemos obtener una medición de la altitud aun más precisa si conocemos la presión real a nivel del mar
				//Si es de 1015 millibars eso equivale a 101500 Pascals
				//FIXME: ver si esto hace falta
				/*				Serial.print("Altitud real = ");
									Serial.print(bmp.readAltitude(101500));
									Serial.println(" metros");
				 */
				//			Serial.println();  //Espaciado entre lecturas
				//			delay(10000);      //Pausa de 10 segundos entre lecturas
				//fin sensor barometro

				//MQ135
				Serial.print("MQ Concentración:\t ");
				Serial.print(mq_ppm);
				Serial.println(" ppm");

				//Serial.print("MQ135 RZ: ");
				//Serial.println(mq_rcero);
				//fin MQ135
				//humedad
				//Se imprimen los valores en el monitor serial.
				Serial.print("DHT Temperatura:\t ");
				Serial.print(dht_temp);
				Serial.println(" *C");
				Serial.print("DHT Humedad:\t\t ");
				Serial.print(dht_hume);
				Serial.println(" %t");
				//fin humedad

				//lm35
				Serial.print("LM35 Temperatura:\t ");
				Serial.print(lm35_temp);
				Serial.println(" *C");

				//velocidad viento
				Serial.print("VV Veloc. Viento:\t ");
				Serial.print(v_viento);
				Serial.println(" Km/h");

				//direccion viento
        dir_printDir();


}
