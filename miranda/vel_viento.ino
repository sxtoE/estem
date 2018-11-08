
//Definicion de pines digitales de Arduino en libreria  de Myopenlab
//--------------------------------------
#define in1  2     //pin D2, Conectar Pulsos
#define in2 3      //pin D3
#define in3 4      //pin D4
#define in4 5      //pin D5
#define in5 6      //pin D6
#define in6 7      //pin D7
#define out1 8     //pin D8
#define out2 9     //pin D9
#define out3 10    //pin D10
#define out4 11    //pin D11
#define out5 12
#define out6 13
//-------------------------------------

//Definicion de variables
//-------------------------------------

int val;
float viento;
unsigned char cmd; //
volatile short pulses=0; //variable
short freq=0; //variable

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to update Freq (milliseconds)

//-------------------------------------

unsigned char inputs;

void setup()
{
  Serial.begin(9600); // If Element Version is 1.2 included in v3.11.0 use 9600bps If Element Version 1.3 included in v3.12.0 use 115200 bps.
 

  //configuracion de entradas
  //------------------------------------
  pinMode(in1, INPUT_PULLUP);
  /*pinMode(in2, INPUT_PULLUP);
  pinMode(in3, INPUT_PULLUP);
  pinMode(in4, INPUT_PULLUP);
  pinMode(in5, INPUT_PULLUP);
  pinMode(in6, INPUT_PULLUP);*/

  attachInterrupt(digitalPinToInterrupt(in1), countPulses, FALLING); // Execute countPulses() if in1 Goes to GND
  //------------------------------------

  //Configuracion de Salidas
  //------------------------------------
 /* pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);
  pinMode(out6, OUTPUT);*/

  Serial.flush();
}


void sendShort(int val)
{
  Serial.write(val>>8); //HIGH Byte
  Serial.write(val & 0xFF); //LOW Byte
  // Serial.print(val , HEX);//
}

void countPulses(){
  pulses++;
}

void loop()
{
 unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
   // save the last time you updated
   previousMillis = currentMillis;
   freq=pulses; // Save the Pulses Number in the last second in the Freq Variable
     
   viento= ((2*M_PI*0.009*36*pulses)/(3*10));
   Serial.print("VELOCIDAD DE VIENTO: ");  //UnComment Only For Test with Arduino Serial Monitor
   Serial.println(viento);
   Serial.print("Frecuencia: ");  //UnComment Only For Test with Arduino Serial Monitor
   Serial.println(freq);          //UnComment Only For Test with Arduino Serial Monitor
   pulses=0;  // Reset Pulses Count
  }
}


void serialEvent(){
  if (Serial.available()) //if Arduino is Polled!
  { 
    cmd =Serial.read();

    if ( (cmd & (1<<0))>0) digitalWrite(out1,1);      else digitalWrite(out1,0);
    if ( (cmd & (1<<1))>0) digitalWrite(out2,1);      else digitalWrite(out2,0);
    if ( (cmd & (1<<2))>0) digitalWrite(out3,1);      else digitalWrite(out3,0);
    if ( (cmd & (1<<3))>0) digitalWrite(out4,1);      else digitalWrite(out4,0);
    if ( (cmd & (1<<4))>0) digitalWrite(out5,1);      else digitalWrite(out5,0);
    if ( (cmd & (1<<5))>0) digitalWrite(out6,1);      else digitalWrite(out6,0); 

    //Leer entradas
    inputs=0;
    if(digitalRead(in1)==HIGH) inputs|=(1<<0); else inputs&=~(1<<0);
    if(digitalRead(in2)==HIGH) inputs|=(1<<1); else inputs&=~(1<<1);
    if(digitalRead(in3)==HIGH) inputs|=(1<<2); else inputs&=~(1<<2);
    if(digitalRead(in4)==HIGH) inputs|=(1<<3); else inputs&=~(1<<3);
    if(digitalRead(in5)==HIGH) inputs|=(1<<4); else inputs&=~(1<<4);
    if(digitalRead(in6)==HIGH) inputs|=(1<<5); else inputs&=~(1<<5);

    //Enviar valores binarios a las salidas
    Serial.write(inputs);

    //Enviar valores analogicos a MyOpenLab
    sendShort (freq); // Now Send Freq instead A0 Value
    //sendShort (analogRead(0));
    sendShort (analogRead(1));
    sendShort (analogRead(2));
    sendShort (analogRead(3));
    sendShort (analogRead(4));
    sendShort (analogRead(5));
  }
  //----------------------------------------
}



