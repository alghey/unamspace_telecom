#include <SPI.h> //Protocolo de comunicacion para comunicarse bidireccionalmente usando relojs y seleccion de Master Slave
//#include <nRF24L01.h> //Librería de NRF24
#include <RF24.h> //lIBRERIA DE nrf24

#define POT_PIN A0

RF24 radio(9, 10); // Configura los pines CE y CSN

const byte direccion_receptor[6] = "00001"; // Dirección del receptor
int potencia;
//Estructura de datos: 4 enteros
struct Datos {
  int dato1;
  int dato2;
  int dato3;
  int dato4;
};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(direccion_receptor);
}

void loop() {

  potencia = analogRead(POT_PIN);

  Datos datos;
  datos.dato1 = potencia;
  datos.dato2 = 2806;
  datos.dato3 = 2106;
  datos.dato4 = 609;

  // Envía los datos
  radio.write(&datos, sizeof(datos));
  //Serial.println(potencia);
  //Serial.println(datos.dato1);
  Serial.println("Datos enviados");

  delay(1000); // Espera un segundo antes de enviar los datos nuevamente
}
