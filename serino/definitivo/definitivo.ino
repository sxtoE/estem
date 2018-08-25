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

#include <UIPEthernet.h> // Used for Ethernet
byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };  //Mac address del ethernet shield
EthernetClient client;      //Iniciamos como cliente
char server[] = "192.168.40.2"; // Ip address del servidor
int t_espera = 1000;      //Tiempo de espera entre envio de datos
float v_temperatura = 0, v_humedad = 0, v_presion = 0, v_uv = 0, v_viento = 0, v_lluvia = 0, v_dioxido = 0, v_monoxido = 0, v_amoniaco = 0;


void setup() {
  Serial.begin(9600); //iniciar si o si arriba de inicializarEthernetShield();
  inicializarEthernetShield(); //Función que inicializa la placa. 
  
}

void loop() {


  enviarDatos(v_temperatura, v_humedad, v_presion, v_uv, v_viento, v_lluvia, v_dioxido, v_monoxido, v_amoniaco); //Función que envía los datos al servidor
  delay(t_espera); //Tiempo que esperaremos entre cada send de data al server

}
























void enviarDatos(float vi_temperatura, float vi_humedad, float vi_presion, float vi_uv, float vi_viento, float vi_lluvia, float vi_dioxido, float vi_monoxido, float vi_amoniaco) {
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {//Fixme: Cambiar este puerto por el usado. 
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
    client.println( " HTTP/1.1");
    client.print( "Host: " );
    client.println(server);
    client.println( "Connection: close" );
    client.println();
    client.println();
    client.stop();
    t_espera = 1000;
  }
  else {
    // you didn't get a connection to the server:
    Serial.println("--> connection failed/n");
    t_espera = 1;
  }

}




void inicializarEthernetShield() {
  Ethernet.begin(mac);
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







