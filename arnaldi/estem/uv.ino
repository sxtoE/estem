#include "uv.h"

// Toma un promedio de lecturas en un pin dado
// Devuelve el promedio
int uv_promedioAnalogRead(int pinToRead)
{
				byte NumeroLecturas = 8;
				unsigned int ValorCorriente = 0; 
				for(int x = 0 ; x < NumeroLecturas ; x++)
								ValorCorriente += analogRead(pinToRead);
				ValorCorriente /= NumeroLecturas;
				return(ValorCorriente);  
}

float uv_mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
				return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

