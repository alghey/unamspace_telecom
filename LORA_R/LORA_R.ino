#include "Arduino.h"
#include "LoRa_E220.h"

LoRa_E220 e220ttl(2, 3); // Arduino RX --> e220 TX - Arduino TX --> e220 RX

void setup() {
  Serial.begin(9600);
  delay(500);

  Serial.println("Hi, I'm the receiver!");

  // Startup all pins and UART
  e220ttl.begin();
}

void loop() {
    // If something available
  if (e220ttl.available()>1) {
      // read the String message
    ResponseContainer rc = e220ttl.receiveMessage();
    // Is something goes wrong print error
    if (rc.status.code!=1){
        rc.status.getResponseDescription();
    }else{
        // Print the data received
        Serial.println(rc.data);
    }
  }

}
