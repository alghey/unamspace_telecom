///Programa de prueba de funcionamiento 
/// Transmisor

#include "Arduino.h"
#include "LoRa_E220.h"
#include <SoftwareSerial.h> //utilizando la app Arduino BlueControl se ingresan los números como "2" ó '2'
SoftwareSerial miBT(9,11);
char dato;
String voice;

//variables Motores
int MotorIzquierdoAdelante  = 3; //pin Digital
int MotorIzquierdoAtras     = 4; //pin Digital
int MotorDerechoAdelante    = 7; //pin Digital
int MotorDerechoAtras       = 8; //pin Digital
int pinVelocidadDerecha     = 6; //pin PWM
int pinVelocidadIzquierda   = 5; //pin PWM
int velocidad = 125;//velocidad motores(0-255)

  
 
LoRa_E220 e220ttl(2, 3); // Arduino RX --> e220 TX - Arduino TX --> e220 RX
 
void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("UNAM SPACE Devs");
  // Startup all pins and UART
  e220ttl.begin();
  //Receptor
//activar señales del puente h
  pinMode(MotorIzquierdoAdelante,OUTPUT);
  pinMode(MotorDerechoAdelante,OUTPUT);
  pinMode(MotorIzquierdoAtras,OUTPUT);
  pinMode(MotorDerechoAtras,OUTPUT);
}
 
void loop() {

  if (Serial.available()) {
      String input = Serial.readString();
      e220ttl.sendMessage(input);
  }
}






//FUNCIONES
void carroAvanzaAdelante(){
    Serial.println("avanzando hacia adelante");
    digitalWrite(MotorDerechoAdelante,HIGH);
    digitalWrite(MotorIzquierdoAdelante,HIGH);
    digitalWrite(MotorDerechoAtras,LOW);
    digitalWrite(MotorIzquierdoAtras,LOW);
    delay(1000);
  }
  
void carroAvanzaAtras(){
    Serial.println("avanzando hacia atras");
    digitalWrite(MotorDerechoAdelante,LOW);
    digitalWrite(MotorIzquierdoAdelante,LOW);
    digitalWrite(MotorDerechoAtras,HIGH);
    digitalWrite(MotorIzquierdoAtras,HIGH);
    delay(1000);
  }
  
void carroGiraDerecha(){
    Serial.println("girando a la derecha");
    digitalWrite(MotorDerechoAdelante,LOW);
    digitalWrite(MotorIzquierdoAdelante,HIGH);
    digitalWrite(MotorDerechoAtras,HIGH);
    digitalWrite(MotorIzquierdoAtras,LOW);
    digitalWrite(13,HIGH);
  }
  
void carroGiraIzquierda(){
    Serial.println("girando a la izquierda");
    digitalWrite(MotorDerechoAdelante,HIGH);
    digitalWrite(MotorIzquierdoAdelante,LOW);
    digitalWrite(MotorDerechoAtras,LOW);
    digitalWrite(MotorIzquierdoAtras,HIGH);
    digitalWrite(13,LOW);
  }
  
void carroDetenido(){
    Serial.println("automovil detenido");
    digitalWrite(MotorDerechoAdelante,LOW);
    digitalWrite(MotorIzquierdoAdelante,LOW);
    digitalWrite(MotorDerechoAtras,LOW);
    digitalWrite(MotorIzquierdoAtras,LOW);
  }
void pruebaMotores(){
    Serial.println("automovil detenido");
    digitalWrite(MotorDerechoAdelante,HIGH);
    digitalWrite(MotorIzquierdoAdelante,LOW);
    digitalWrite(MotorDerechoAtras,HIGH);
    digitalWrite(MotorIzquierdoAtras,LOW);
    delay(200);
    velocidad = velocidad+1;
    if (velocidad == 250){
      velocidad = 0;
      }
  }
 