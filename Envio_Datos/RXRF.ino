#include <SPI.h>
///#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // Configura los pines CE y CSN

const byte direccion_transmisor[6] = "00001"; // Dirección del transmisor

struct Datos {
  int dato1;
  int dato2;
  int dato3;
  int dato4;
};
int i = 0;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, direccion_transmisor);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    Datos datos;

    // Lee los datos recibidos
    radio.read(&datos, sizeof(datos));
    Serial.println(i);
    Serial.print("Dato 1: ");
    Serial.println(datos.dato1);
    Serial.print("Dato 2: ");
    Serial.println(datos.dato2);
    Serial.print("Dato 3: ");
    Serial.println(datos.dato3);
    Serial.print("Dato 4: ");
    Serial.println(datos.dato4);
    i = i + 1;
  }
}
