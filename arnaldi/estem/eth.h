#ifndef _ETH_H_
#define _ETH_H_

#include <UIPEthernet.h> // Used for Ethernet

byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };  //Mac address del ethernet shield
EthernetClient client;      //Iniciamos como cliente
char server[] = "10.10.6.77"; // Ip address del servidor
IPAddress myIP(10,10,6,115);

void eth_inicializarEthernetShield();
void eth_enviarDatos(float vi_temperatura, float vi_humedad, float vi_presion, float vi_uv, float vi_viento, float vi_lluvia, float vi_dioxido, float vi_monoxido, float vi_amoniaco, int dir_viento);


#endif
