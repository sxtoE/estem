/*
-Si la placa del sensor tiene gotas de agua sobre ella; "case1" se activará y "Lluvia" se enviará al monitor serie.
-Si la placa del sensor está seca; "case2" se activará y "No hay precipitaciónes ni nevadas" se enviará al monitor serie.
*/
// lecturas del sensor más bajas y más altas:
const int sensorMin =0; //sensor con lectura minima 
const int sensorMax =1024; //sensor con lectura maxima
void setup() {
Serial.begin(9600);
}

void loop() { 
// lee el sensor en analógico A0:
int sensorReading = analogRead(A0);
int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
// valor de rango:
switch (range){
  case 1: // sensor con lluvia
  Serial.println("Esta Lloviendo");
  break;
  case 2: // sensor seco-Para cerrar esto, elimine "Serial.println (" No lloviendo ");" a continuación.
  Serial.println("No hay Lluvias");
  break;
}
delay(100); // demora entre lecturas
}
