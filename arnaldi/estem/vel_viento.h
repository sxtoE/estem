#ifndef _VEL_VIENTO_H_
#define _VEL_VIENTO_H_

volatile short pulses=0; //variable
unsigned long previousMillis = 0;

float vv_medirVelocidad();
void vv_countPulses();

#endif
