#include "temp.h"

float temp_readTemp() {
				float tempC;
				int pos = 0;
				float tprom[10];
				float temp = 0.0;

				while (pos < 11) {
								tempC = analogRead(pinLM35);
								// Calculamos la temp con la fórmula
								tempC = (5 * tempC * 100) / 1024;
								tprom[pos] = tempC;
								temp = temp + tprom[pos];
								pos++;
				}
				//pos=0;
				return (temp / 10.0);
}
