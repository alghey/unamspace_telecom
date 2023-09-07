//CÓDIGO DE TRANSMISIÓN ENTRE DOS ARDUINOS Y TRANSMISIÓN WIRELESS LORA CON EL EBYTE E220 

//Librerías necesarias para el funcionamiento
#include "Arduino.h"
#include "LoRa_E220.h"

//Se llama un objeto de tipo Lora para la comunicación
LoRa_E220 e220ttl(2, 3); // Arduino RX --> e220 TX - Arduino TX --> e220 RX

//Se crea una estructura para almacenar los diferentes datos de telemetría
struct telemetria {
  float dato1; //+4 bytes = 4 bytes   //  Motor 1
  float dato2; //+4 bytes = 8 bytes   //  Motor 2
  float dato3; //+4 bytes = 12 bytes  //  Motor 3
  float dato4; //+4 bytes = 16 bytes  //  Motor 4
  float dato5; //+4 bytes = 20 bytes  //  Motor 5
  float dato6; //+4 bytes = 24 bytes  //  Motor 6
  float dato7; //+4 bytes = 28 bytes  //  Bascula
  byte dato8; //+1 bytes = 29 bytes   // color
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
  //Datos requeridos para su transmisión
  //ESPACIO PARA ALMACENAR LECTURAS
  tele.dato1 = 95.12; // Lectura de Motor 1
  tele.dato2 = 0.25;  // Lectura de Motor 2
  tele.dato3 = -6.25; // Lectura de Motor 3
  tele.dato4 = 3.25;  // Lectura de Motor 4
  tele.dato5 = -0.25; // Lectura de Motor 5
  tele.dato6 = 25.36; // Lectura de Motor 6
  tele.dato7 = 25.3654; // Lectura de Báscula
  tele.dato8 = 1; // Lectura de color
  
  //if (Serial.available()) {
  Serial.println(i);
  i++;
  ResponseStatus rs = e220ttl.sendMessage(&tele, sizeof(telemetria));
  Serial.println(rs.getResponseDescription()); // Agregar un pequeño retraso después de enviar el mensaje
  //}
}
