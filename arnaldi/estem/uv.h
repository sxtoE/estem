#ifndef _UV_H_
#define _UV_H_

const int UVOUT   = A8;   //Salida del sensor
const int REF_3V3 = A9; //3.3V de encendido en el tablero Arduino

int uv_promedioAnalogRead(int pinToRead);
float uv_mapfloat(float x, float in_min, float in_max, float out_min, float out_max);

#endif 
