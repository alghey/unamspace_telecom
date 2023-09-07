//CÓDIGO DE TRANSMISIÓN ENTRE DOS ARDUINOS Y TRANSMISIÓN WIRELESS LORA CON EL EBYTE E220 

//Librerías necesarias para el funcionamiento
#include "Arduino.h"
#include "LoRa_E220.h"

//Se llama un objeto de tipo Lora para la comunicación
LoRa_E220 e220ttl(2, 3); // Arduino RX --> e220 TX - Arduino TX --> e220 RX

//Se crea una estructura para almacenar los diferentes datos de telemetría
struct telemetria {
  float dato1; //+4 bytes = 4 bytes //Voltaje
  float dato2; //+4 bytes = 8 bytes //
  float dato3; //+4 bytes = 12 bytes
  float dato4; //+4 bytes = 16 bytes
  float dato5; //+4 bytes = 20 bytes
  float dato6; //+4 bytes = 24 bytes
  float dato7; //+4 bytes = 28 bytes
  float dato8; //+4 bytes = 32 bytes
  float dato9; //+4 bytes = 36 bytes
  float dato10; //+4 bytes = 40 bytes
  float dato11; //+4 bytes = 44 bytes
  float dato12; //+4 bytes = 48 bytes
  float dato13; //+4 bytes = 52 bytes
  float dato14; //+4 bytes = 56 bytes
  float dato15; //+4 bytes = 60 bytes
  byte dato16; //+1 bytes = 61 bytes
  byte dato17; //+1 bytes = 62 bytes
  byte dato18; //+1 bytes = 63 bytes
  byte dato19; //+4 bytes = 64 bytes
};


void setup() {
  //Iniciamos comunicacion serial a 9600
  Serial.begin(9600);
  delay(500); //retraso de 0.5 segundos para visualizar los datos
  Serial.println("Prueba");
  
  // Startup all pins and UART
  e220ttl.begin();
  // Check If there is some problem of successfully send
}
//Inicializamos un contador para estar al tanto  del número de iteración
int i = 0;

void loop() {
  telemetria tele; //Creamos una estructura de datos antes mencionada, para crear el paquete a enviar
  tele.dato1 = 95.12; //Espacio para almacenar lecturas
  tele.dato2 = 0.25;
  tele.dato3 = -6.25;
  tele.dato4 = 3.25;
  tele.dato5 = -0.25;
  tele.dato6 = 25.36;
  tele.dato7 = 25.3654;
  tele.dato8 = -0.35;
  tele.dato9 = 2.54;
  tele.dato10 = -9.58;
  tele.dato11 = 0.98;
  tele.dato12 = -0.25;
  tele.dato13 = 6.68;
  tele.dato14 = 4.59;
  tele.dato15 = -4.59;
  tele.dato16 = 1;
  tele.dato17 = 4;
  tele.dato18 = 9;
  tele.dato19 = 10;
  //if (Serial.available()) {
  Serial.println(i);
  i++;
  ResponseStatus rs = e220ttl.sendMessage(&tele, sizeof(telemetria));
  Serial.println(rs.getResponseDescription()); // Agregar un pequeño retraso después de enviar el mensaje
  //}
}
