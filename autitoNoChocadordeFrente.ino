#include <hcsr04.h>

#define TRIG_PIN 10
#define ECHO_PIN 11

int aw = 0, counter = 0;
String caquita = "";
int distancia = 0;
HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  caquita = hcsr04.ToString();
  distancia = caquita.toInt();
  Serial.println(caquita);
  if (distancia > 60) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  delay(500);
}

