//Sketch para ethernet Matias Serino Marin
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 } ;
EthernetClient client;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  { ; // Solo para el Leonardo  }
  }
  if (Ethernet.begin(mac) == 0)    //Si devuelve error
  {
    Serial.println("No ha sido possible configurar la Ethernet por DHCP");
    while (true );            // No sigas, quédate aquí eternamente
  }
  Serial.print("Mi direccion IP es: ");
  for (byte B = 0; B < 4; B++)
  {
    Serial.print(Ethernet.localIP()[B], DEC);
    Serial.print(".");
  }
  

}


  void loop() {



  }
