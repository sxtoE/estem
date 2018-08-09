/* ============================================
Desc: WebClient for arduino Ethernet Shield
Date: 03.03.2015 - kala13x (a.k.a 7th Ghost)
Site: http://off-sec.com/
============================================ */

#include <SPI.h>
#include <Ethernet.h>

// MAC address for controller
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// IP address for controller
IPAddress ip(192,168,40,5);
// Web Server adress
char server[] = "192.168.40.3";

// Initialise Client
EthernetClient client;

void setup() 
{
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect
    }

   Ethernet.begin(mac, ip);

    // give the Ethernet shield a second to initialize
    delay(1000);
    Serial.println("connecting...");

    // if you get a connection, report back via serial
    if (client.connect(server, 25000)) 
    {
        Serial.println("connected");
        // Make a HTTP request
        client.println("GET /");
        client.println("Host: 192.168.0.13");
        client.println("Connection: close");
        client.println();
    } else Serial.println("connection failed");
}

void loop()
{
    // Read and print response from server
    if (client.available()) {
        char c = client.read();
        Serial.print(c);
    }

    // if the server's disconnected, stop the client
    if (!client.connected()) 
    {
        Serial.println();
        Serial.println("disconnecting.");
        client.stop();

        // Do nothing forevermore
        while(true);
    }
}
