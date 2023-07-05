#include "Arduino.h"
#include "LoRa_E220.h"

LoRa_E220 e220ttl(2, 3); // Arduino RX --> e220 TX - Arduino TX --> e220 RX

void setup() {
  Serial.begin(9600);
  delay(500);

  Serial.println("(W) Adelante  (S) Atrás   (A) Izquierda  (D) Derecha  (E) Detener");
  
  // Startup all pins and UART
  e220ttl.begin();
  ResponseStatus rs = e220ttl.sendMessage("Hello, world?");
  // Check If there is some problem of successfully send
  Serial.println(rs.getResponseDescription());
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readString();

    ResponseStatus rs = e220ttl.sendMessage(input);
    Serial.println(input);

    delay(100); // Agregar un pequeño retraso después de enviar el mensaje
  }
}
