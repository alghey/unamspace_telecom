#include "Arduino.h"
#include "LoRa_E220.h"

LoRa_E220 e220ttl(2, 3); // Arduino RX --> e220 TX - Arduino TX --> e220 RX

struct telemetria {
  float dato1;
  float dato2;
  float dato3;
  float dato4;
  float dato5;
  float dato6;
  float dato7;
};


void setup() {
  Serial.begin(9600);
  delay(500);

  Serial.println("Prueba");
  
  // Startup all pins and UART
  e220ttl.begin();
  // Check If there is some problem of successfully send
}
int i = 0;
void loop() {
  telemetria tele;
  tele.dato1 = 95.12;
  tele.dato2 = 0.25;
  tele.dato3 = -6.25;
  tele.dato4 = 3.25;
  tele.dato5 = -0.25;
  tele.dato6 = 25.36;
  tele.dato7 = 25.365;

  //if (Serial.available()) {
  Serial.println(i);
  i++;
  ResponseStatus rs = e220ttl.sendMessage(&tele, sizeof(telemetria));
  Serial.println(rs.getResponseDescription()); // Agregar un pequeño retraso después de enviar el mensaje
  //}
}
