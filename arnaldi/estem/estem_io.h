#ifndef _ESTEM_IO_H_
#define _ESTEM_IO_H_

#include "uv.h"
#include "barometro.h"
#include "temperatura.h"

// Pines de control
#define STATUS_LED  13   // Led conectado a DP, de uso general
#define POWER_TF    4    // Pin de control de energia para el modulo TF (PD4 del MCU)
#define CS_TF       10   // CS para la tarjeta SD (PB2/CS1 en el Seeduino Stalker (v2.3))
#define POWER_RF    7    // Pin de control de energia para el modulo RF (DP7)
#define CS_RF       3    // CS para el modulo RF22
#define rfIntPin    0    // Pin de interrupciones para el modulo RF

//#define UVOUT       A8	 //salida del sensor UV
//#define REF_3V3     A9   //3.3V de encendido en el tablero Arduino

#endif
