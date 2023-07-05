/*
UNAM SPACE - Sistema de Telecomonicaciones
Integrantes: Pablo (líder), Johusa, Alejandra, Eder, Homero

FUNCION DEL CÓDIGOo: Transmitir datos con los NRF24 usando un payload completo

*/
#include <SPI.h> //Protocolo de comunicacion para comunicarse bidireccionalmente usando relojs y seleccion de Master Slave
#include <RF24.h> //lIBRERIA DE nrf24

//CONFIGURACIÓN PARA TRANSMISIÓN
RF24 radio(9, 10); // Configura los pines CE y CSN
const byte direccion_receptor[6] = "00001"; // Dirección del receptor

//Creamos una estructura de datos para transmitir los datos a tarvés del Payload
//Tamaño máximo del Payload = 32 bytes

struct Datos{
  byte dato1;
  byte dato2;
  byte dato3;
  byte dato4;
  byte dato5;
  byte dato6;
  byte dato7;
  byte dato8;
  byte dato9;
  byte dato10;
  byte dato11;
  byte dato12;
  byte dato13;
  byte dato14;
  byte dato15;
  byte dato16;
  byte dato17;
  byte dato18;
  byte dato19;
  byte dato20;
  byte dato21;
  byte dato22;
  byte dato23;
  byte dato24;
  byte dato25;
  byte dato26;
  byte dato27;
  byte dato28;
  byte dato29;
  byte dato30;
  byte dato31;
  byte dato32;
  };

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(direccion_receptor);
}

void loop() {
  Datos datos;
  datos.dato1 = 1;
  datos.dato2 = 2;
  datos.dato3 = 3;
  datos.dato4 = 4;
  datos.dato5 = 5;
  datos.dato6 = 6;
  datos.dato7 = 7;
  datos.dato8 = 8;
  datos.dato9 = 9;
  datos.dato10 = 10;
  datos.dato11 = 11;
  datos.dato12 = 12;
  datos.dato13 = 13;
  datos.dato14 = 14;
  datos.dato15 = 15;
  datos.dato16 = 16;
  datos.dato17 = 17;
  datos.dato18 = 18;
  datos.dato19 = 19;
  datos.dato20 = 20;
  datos.dato21 = 21;
  datos.dato22 = 22;
  datos.dato23 = 23;
  datos.dato24 = 24;
  datos.dato25 = 25;
  datos.dato26 = 26;
  datos.dato27 = 27;
  datos.dato28 = 28;
  datos.dato29 = 29;
  datos.dato30 = 30;
  datos.dato31 = 31;
  datos.dato32 = 44;

  // Envía los datos
  radio.write(&datos, sizeof(datos));

  Serial.println("Datos enviados");

  delay(1000); // Espera un segundo antes de enviar los datos nuevamente
}
