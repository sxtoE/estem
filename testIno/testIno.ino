#include <hcsr04.h>

#define TRIG_PIN 12
#define ECHO_PIN 13

int aw = 0, counter = 0;
String caquita = "";

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  counter++;
  if ((counter % 500 == 0) || (counter == 1)) {
    caquita = hcsr04.ToString();
    if (caquita.toInt() < 1001 && caquita.toInt() > 45) {
      Serial.print(caquita);
      aw = caquita.toInt();

      aw = map(aw, 45, 1000, 0, 255);
      Serial.print("\t");
      
      analogWrite(9, aw);

      Serial.println(aw);

    }
  }

  if (counter > 999999999) {
    counter = 0;
  }





}
