/*
 * Conexión hardware: 
 * Arduino mega | Ethernet shield
 * pin 50  | so
 * pin 51  | st
 * pin 52  | sck
 * pin 53  | cs 
 *  
 * 
 */
#include "eth.h"

void eth_inicializarEthernetShield() {
  Ethernet.begin(mac,myIP);
  //Ethernet.begin(mac);
  Serial.println("Estacion Meteorologica");
  Serial.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  Serial.print("IP Address        : ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask       : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Default Gateway IP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS Server IP     : ");
  Serial.println(Ethernet.dnsServerIP());
}

void eth_enviarDatos(float vi_temperatura, float vi_humedad, float vi_presion, float vi_uv, float vi_viento, float vi_lluvia, float vi_dioxido, float vi_monoxido, float vi_amoniaco, int dir_viento) {
  // if you get a connection, report back via serial:
  if (client.connect(server, 555)) {//Fixme: Cambiar este puerto por el usado. 
    Serial.println("-> Connected");
    // Make a HTTP request:
    client.print( "GET /eth/index.php?");
    client.print("temperatura=");
    client.print(vi_temperatura);
    client.print("&&");
    client.print("humedad=");
    client.print(vi_humedad);
    client.print("&&");
    client.print("presion=");
    client.print(vi_presion);
    client.print("&&");
    client.print("uv=");
    client.print(vi_uv);
    client.print("&&");
    client.print("viento=");
    client.print(vi_viento);
    client.print("&&");
    client.print("lluvia=");
    client.print(vi_lluvia);
    client.print("&&");
    client.print("dioxido=");
    client.print(vi_dioxido);
    client.print("&&");
    client.print("monoxido=");
    client.print(vi_monoxido);
    client.print("&&");
    client.print("amoniaco=");
    client.print(vi_amoniaco);
    client.print("&&");
    client.print("direccion=");
    client.print(dir_viento);
    client.println( " HTTP/1.1");
    client.print( "Host: " );
    client.println(server);
    client.println( "Connection: close" );
    client.println();
    client.println();
    client.stop();
    //t_espera = 1000;
  }
  else {
    // you didn't get a connection to the server:
    Serial.println("--> connection failed/n");
    //t_espera = 1;
  }

}
