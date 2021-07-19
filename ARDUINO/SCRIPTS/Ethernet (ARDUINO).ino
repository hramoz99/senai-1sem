#include <UIPEthernet.h>

#include <SPI.h>

byte mac [] = {0xBE, 0xF0, 0x4F, 0x95, 0x3B, 0xFC};

EthernetClient client;

void setup() {
  
Ethernet.begin(mac);
Serial.begin (9600);

Serial.print ("O IP do arduino e:");
Serial.println (Ethernet.localIP());

Serial.print("A Mascara de Rede do arduino e:");
Serial.println(Ethernet.subnetMask());

Serial.print ("O Gateway do arduino e:");
Serial.println(Ethernet.gatewayIP());

}

void loop() {
  

}