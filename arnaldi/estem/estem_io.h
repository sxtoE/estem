#ifndef _ESTEM_IO_H_
#define _ESTEM_IO_H_

#include <Wire.h>           //Cargamos la librería Wire
#include <MQ135.h>
#include <Adafruit_BMP085.h>//Cargamos la librería BMP085
#include <UIPEthernet.h> // Used for Ethernet

#include "eth.h"
#include "humedad.h"
#include "uv.h"
#include "lm35.h"
#include "mq135.h"
#include "vel_viento.h"
#include "dir_viento.h"

// Pines de control
#define STATUS_LED  13   // Led conectado a DP, de uso general
//Entadas analogicas
#define PIN_LM35    A0   // Variable del pin de entrada del sensor (A0)
#define PIN_MQ      A1   //Entrada de calibracion para el sensor MQ135
#define PIN_DVIENTO A2   //Entrada para leer la direccion del viento
#define PIN_UVOUT   A3	 //salida del sensor UV (A8)
#define PIN_REF3V3  A4   //3.3V de encendido en el tablero Arduino (A9)
#define PIN_DHT     2    //Pin de conexion.
#define PIN_VVIENTO 3    //Velocidad del viento

void readSensors();
void printDataSerial();
#endif
