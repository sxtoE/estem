float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = 0; // Variable del pin de entrada del sensor (A0)
float tprom[10];
float temperatura = 0;
int posicion = 0;

void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);

}

void loop() {
  while (posicion < 11) {
    // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
    tempC = analogRead(pinLM35);
    // Calculamos la temperatura con la fórmula
    tempC = (5 * tempC * 100) / 1024;
    tprom[posicion] = tempC;
    temperatura = temperatura + tprom[posicion];
    posicion++;
  }
  posicion=0;
  temperatura = temperatura / 10;
  // Envia el dato al puerto serial
  Serial.println("Temperatura Actual");
  Serial.println(temperatura);
  // Salto de línea
  //Serial.print("ln");

  // Esperamos un tiempo para repetir el loop
  delay(1000);
}
