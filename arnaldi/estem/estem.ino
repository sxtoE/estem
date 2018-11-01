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

//Adafruit_BMP085 bmp;           //Iniciamos una instancia de la librería BMP085
//MQ135 sensorMQ = MQ135(MQ_CAL);
DHT dht(DHTPIN, DHTTYPE);

// se llama cuando se completa el request del cliente
static void my_callback (byte status, word off, word len) {
				Serial.println(">>>");
				Ethernet::buffer[off+300] = 0;
				Serial.print((const char*) Ethernet::buffer + off);
				Serial.println("...");
}

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
float mq_rs;
float mq_ppm;
int uv_Nivel, uv_refNivel;

void setup()
{
				//configuramos pines de I/O
				pinMode(UVOUT, INPUT);
				pinMode(REF_3V3, INPUT);
				pinMode(MQ_PIN, INPUT);
				pinMode(STATUS_LED, OUTPUT);

				//Iniciamos la comunicación serie
				Serial.begin(57600);
				//Serial.begin(9600);

/*				Serial.println("MP8511");
				//barometro
				if (!bmp.begin()) {  //Si hay un error al iniciar la librería...
								//Mostramos un mensaje
								Serial.println("No se puede iniciar el sensor BMP085, compruebe las conexiones!"); 
								while (1) {} //Detenemos la ejecución
				}
				//fin barometro

				//ethernet
				//Serial.println(F("\n[webClient]"));

				// Change 'SS' to your Slave Select pin, if you arn't using the default pin
				if (ether.begin(sizeof Ethernet::buffer, mymac, 10) == 0)
								Serial.println(F("Failed to access Ethernet controller"));
				if (!ether.dhcpSetup())
								Serial.println(F("DHCP failed"));

				ether.printIp("IP:  ", ether.myip);
				ether.printIp("GW:  ", ether.gwip);
				ether.printIp("DNS: ", ether.dnsip);

#if 1
				// use DNS to resolve the website's IP address
				if (!ether.dnsLookup(website))
								Serial.println("DNS failed");
#elif 2
				// if website is a string containing an IP address instead of a domain name,
				// then use it directly. Note: the string can not be in PROGMEM.
				char websiteIP[] = "192.168.40.2";
				ether.parseIp(ether.hisip, websiteIP);
#else
				// or provide a numeric IP address instead of a string
				byte hisip[] = { 192,168,40,2 };
				ether.copyIp(ether.hisip, hisip);
#endif

				ether.printIp("SRV: ", ether.hisip);
				//fin ethernet
*/
				//humedad
				//Serial.begin(9600);
				//Serial.println("Iniciando Lectura...");
				dht.begin();
				///fin humedad
}

void loop()
{

				if(millis()-t_UltimaLectura>intervaloLecturas)
				{  
								//Primero leemos los sensores
								readSensors();
                printDataSerial();

								//ethernet
								/*ether.packetLoop(ether.packetReceive());
								Serial.println();
								Serial.print("<<< REQ ");
								ether.browseUrl(PSTR("/foo/"), "bar", website, my_callback);
				*/
				//fin ethernet
				t_UltimaLectura=millis(); //Se actuliza el tiempo de la ultima lectura.
}
}

void readSensors()
{
				//Sensor UV
				uv_Nivel = uv_promedioAnalogRead(UVOUT);
				uv_refNivel = uv_promedioAnalogRead(REF_3V3);
				//Utiliza el pin de alimentación de 3.3V como referencia para 
				//obtener un valor de salida muy preciso del sensor
				uv_vout = (3.3 / uv_refNivel)*uv_Nivel;
				uv_intensidad = uv_mapfloat(uv_vout, 0.99, 2.9, 0.0, 15.0);
				//BMP
/*				bmp_temp = bmp.readTemperature();
				bmp_pres = bmp.readPressure();
				bmp_presnm = bmp.readSealevelPressure();*/
				//MQ135
				//mq_rcero = sensorMQ.getRZero();
 mq_rs = mq_readMQ(MQ_PIN);      // Obtener la Rs promedio
 mq_ppm = mq_getConcentration(mq_rs/R0);   // Obtener la concentración
   

				//DHT
				dht_temp = humedad_readTemp();
				dht_hume = humedad_readHumedad();
       //LM35
       lm35_temp = temp_readTemp();

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
/*				Serial.print("BMP Temperatura = ");
				Serial.print(bmp_temp);
				Serial.println(" *C");

				//Leemos los valores del sensor y sacamos la presión atmosférica por el monitor serie    
				Serial.print("BMP Presión = ");
				Serial.print(bmp_pres);
				Serial.println(" Pa");

				//Calculamos la altitud asumiendo la presión barométrica 'standard' a 1013.25 milibares
				//No hace falta
				Serial.print("Altitud = ");
					Serial.print(bmp.readAltitude());
					Serial.println(" metros");
				 */
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

}
