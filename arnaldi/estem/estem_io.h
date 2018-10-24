#ifndef _ESTEM_IO_H_
#define _ESTEM_IO_H_

#include "uv.h"
//#include "barometro.h"
#include "temperatura.h"

// Pines de control
#define STATUS_LED  13   // Led conectado a DP, de uso general
//Entadas analogicas
#define pinLM35     0   // Variable del pin de entrada del sensor (A0)
#define UVOUT       8	 //salida del sensor UV (A8)
#define REF_3V3     9   //3.3V de encendido en el tablero Arduino (A9)

#endif
