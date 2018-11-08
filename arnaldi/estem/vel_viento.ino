#include "vel_viento.h"

float vv_medirVelocidad()
{
				const long interval = 1000;
				float v_viento;
        short freq=0;
				unsigned long currentMillis = millis();

				if (currentMillis - previousMillis >= interval) {
								previousMillis = currentMillis;
								freq=pulses; 

								v_viento= ((2*M_PI*0.009*36*pulses)/(3*10));
								//debug
								/* Serial.print("VELOCIDAD DE VIENTO: ");  
									 Serial.println(v_viento);
									 Serial.print("Frecuencia: ");  
									 Serial.println(freq);*/         
								pulses=0;  
				}
				return v_viento;
}

void vv_countPulses()
{
				pulses++;
}
