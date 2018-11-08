#ifndef _ESTEM_IO_H_
#define _ESTEM_IO_H_

#include <Wire.h>           //Cargamos la librería Wire
#include <MQ135.h>
#include <Adafruit_BMP085.h>//Cargamos la librería BMP085
#include <UIPEthernet.h> // Used for Ethernet

#include "eth.h"
#include "DHT.h"//Libreria a utilizar.
#include "uv.h"
#include "temp.h"
#include "humedad.h"
#include "mq135.h"
#include "vel_viento.h"
#include "dir_viento.h"

// Pines de control
#define STATUS_LED  13   // Led conectado a DP, de uso general
//Entadas analogicas
#define PIN_LM35    A0   // Variable del pin de entrada del sensor (A0)
#define MQ_PIN      A1   //Entrada de calibracion para el sensor MQ135
#define DIR_VIENTO  A2   //Entrada para leer la direccion del viento
#define UVOUT       A8	 //salida del sensor UV (A8)
#define REF_3V3     A9   //3.3V de encendido en el tablero Arduino (A9)
#define DHTPIN      2    //Pin de conexion.
#define DHTTYPE     DHT22
#define VEL_VIENTO  3



void readSensors();
void printDataSerial();
#endif
