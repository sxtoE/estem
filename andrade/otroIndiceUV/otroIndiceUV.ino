int UVOUT = A8; //Salida del sensor
int REF_3V3 = A9; //3.3V de encendido en el tablero Arduino
void setup()
{
  Serial.begin(9600);
  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);
  Serial.println("MP8511");
}
void loop()
{
  int uvNivel = promedioAnalogRead(UVOUT);
  int refNivel = promedioAnalogRead(REF_3V3);
//Utilice el pin de alimentación de 3.3V como referencia para obtener un valor de salida muy preciso del sensor
  float outputVoltaje = 3.3 / refNivel * uvNivel;
  float IntencidadUV = mapfloat(outputVoltaje, 0.99, 2.9, 0.0, 15.0);
  Serial.print("Voltaje Recibido: ");
  Serial.print(IntencidadUV);
Serial.println();
  Serial.print("Indice UV: ");
  Serial.println(outputVoltaje);
  Serial.println();
  delay(400);
}

// Toma un promedio de lecturas en un pin dado
// Devuelve el promedio
int promedioAnalogRead(int pinToRead)
{
  byte NumeroLecturas = 8;
  unsigned int ValorCorriente = 0; 
  for(int x = 0 ; x < NumeroLecturas ; x++)
    ValorCorriente += analogRead(pinToRead);
  ValorCorriente /= NumeroLecturas;
  return(ValorCorriente);  
}
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
