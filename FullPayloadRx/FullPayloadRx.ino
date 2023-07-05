/*
UNAM SPACE - Sistema de Telecomonicaciones
Integrantes: Pablo (líder), Johusa, Alejandra, Eder, Homero

FUNCION DEL CÓDIGOo: Recibir datos con los NRF24 usando un payload completo

*/
#include <SPI.h> //Protocolo de comunicacion para comunicarse bidireccionalmente usando relojs y seleccion de Master Slave
#include <RF24.h> //lIBRERIA DE nrf24

//CONFIGURACIÓN PARA TRANSMISIÓN
RF24 radio(9, 10); // Configura los pines CE y CSN
const byte direccion_transmisor[6] = "00001"; // Dirección del receptor

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
    Serial.print("Dato 5: ");
    Serial.println(datos.dato5);
    Serial.print("Dato 6: ");
    Serial.println(datos.dato6);
    Serial.print("Dato 7: ");
    Serial.println(datos.dato7);
    Serial.print("Dato 8: ");
    Serial.println(datos.dato8);
    Serial.print("Dato 9: ");
    Serial.println(datos.dato9);
    Serial.print("Dato 10: ");
    Serial.println(datos.dato10);
    Serial.print("Dato 11: ");
    Serial.println(datos.dato11);
    Serial.print("Dato 12: ");
    Serial.println(datos.dato12);
    Serial.print("Dato 13: ");
    Serial.println(datos.dato13);
    Serial.print("Dato 14: ");
    Serial.println(datos.dato14);
    Serial.print("Dato 15: ");
    Serial.println(datos.dato15);
    Serial.print("Dato 16: ");
    Serial.println(datos.dato16);
    Serial.print("Dato 17: ");
    Serial.println(datos.dato17);
    Serial.print("Dato 18: ");
    Serial.println(datos.dato18);
    Serial.print("Dato 19: ");
    Serial.println(datos.dato19);
    Serial.print("Dato 20: ");
    Serial.println(datos.dato20);
    Serial.print("Dato 21: ");
    Serial.println(datos.dato21);
    Serial.print("Dato 22: ");
    Serial.println(datos.dato22);
    Serial.print("Dato 23: ");
    Serial.println(datos.dato23);
    Serial.print("Dato 24: ");
    Serial.println(datos.dato24);
    Serial.print("Dato 25: ");
    Serial.println(datos.dato25);
    Serial.print("Dato 26: ");
    Serial.println(datos.dato26);
    Serial.print("Dato 27: ");
    Serial.println(datos.dato27);
    Serial.print("Dato 28: ");
    Serial.println(datos.dato28);
    Serial.print("Dato 29: ");
    Serial.println(datos.dato29);
    Serial.print("Dato 30: ");
    Serial.println(datos.dato30);
    Serial.print("Dato 31: ");
    Serial.println(datos.dato31);
    Serial.print("Dato 32: ");
    Serial.println(datos.dato32);
    i = i + 1;
  }
}
