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

Adafruit_BMP085 bmp;           //Iniciamos una instancia de la librería BMP085
MQ135 sensorMQ = MQ135(MQ_CAL);
DHT dht(DHTPIN, DHTTYPE);

// se llama cuando se completa el request del cliente
static void my_callback (byte status, word off, word len) {
				Serial.println(">>>");
				Ethernet::buffer[off+300] = 0;
				Serial.print((const char*) Ethernet::buffer + off);
				Serial.println("...");
}

long tiempoUltimaLectura=0;; //Guarda el tiempo de la última lectura.

void setup()
{
				//configuramos pines de I/O
				pinMode(UVOUT, INPUT);
				pinMode(REF_3V3, INPUT);
				pinMode(MQ_CAL, INPUT);
				pinMode(STATUS_LED, OUTPUT);

				//Iniciamos la comunicación serie
				Serial.begin(57600);
				//Serial.begin(9600);

				Serial.println("MP8511");
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

				//humedad
				//Serial.begin(9600);
				Serial.println("Iniciando Lectura...");
				dht.begin();
				///fin humedad
}

void loop()
{
				float r_cero, t, h;
				int uvNivel, refNivel;

				uvNivel = uv_promedioAnalogRead(UVOUT);
				refNivel = uv_promedioAnalogRead(REF_3V3);
				//Utilice el pin de alimentación de 3.3V como referencia para 
				//obtener un valor de salida muy preciso del sensor
				float outputVoltaje = 3.3 / refNivel * uvNivel;
				float IntencidadUV = uv_mapfloat(outputVoltaje, 0.99, 2.9, 0.0, 15.0);
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

				//inicio sensor MQ135
				float resistencia_cero = sensorMQ.getRZero();
				Serial.println(resistencia_cero);
				//fin MQ135

				//ethernet
				ether.packetLoop(ether.packetReceive());

				if (millis() > timer) {
								timer = millis() + 5000;
								Serial.println();
								Serial.print("<<< REQ ");
								ether.browseUrl(PSTR("/foo/"), "bar", website, my_callback);
				}
				//fin ethernet
				//humedad
				if(millis()-tiempoUltimaLectura>2000)
				{  
								//Se impmprimen los valores en el monitor serial.
t = humedad_readTemp();
								Serial.print("Temperatura: ");
								Serial.print(t);
								Serial.println(" *C");
h = humedad_readTemp();
								Serial.print("Humedad: ");
								Serial.print(h);
								Serial.println(" %t");
								tiempoUltimaLectura=millis(); //Se actuliza el tiempo de la ultima lectura.
				}

				//fin humedad
}
