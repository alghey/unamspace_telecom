//#include <SPI.h> //Protocolo de comunicacion para comunicarse bidireccionalmente usando relojs y seleccion de Master Slave
//#include <nRF24L01.h> //Librería de NRF24
//#include <RF24.h> //lIBRERIA DE nrf24

#define POT_1_PIN A0
#define POT_2_PIN A1
#define POT_3_PIN A2
#define POT_4_PIN A3
#define POT_5_PIN A4
#define POT_6_PIN A5

//RF24 radio(9, 10); // Configura los pines CE y CSN

const byte direccion_receptor[6] = "00001"; // Dirección del receptor
short potencia1;
short potencia2;
short potencia3;
short potencia4;
short potencia5;
short potencia6;
//Estructura de datos: 4 enteros
struct Datos {
  short dato1;
  short dato2;
  short dato3;
  short dato4;
  short dato5;
  short dato6;
};

void setup() {
  Serial.begin(9600);
  //radio.begin();
  //radio.openWritingPipe(direccion_receptor);
}

void loop() {

  potencia1 = analogRead(POT_1_PIN);
  potencia2 = analogRead(POT_2_PIN);
  potencia3 = analogRead(POT_3_PIN);
  potencia4 = analogRead(POT_4_PIN);
  potencia5 = analogRead(POT_5_PIN);
  potencia6 = analogRead(POT_6_PIN);

  Datos datos;
  datos.dato1 = potencia1;
  datos.dato2 = potencia2;
  datos.dato3 = potencia3;
  datos.dato4 = potencia4;
  datos.dato5 = potencia5;
  datos.dato6 = potencia6;

  //datos.dato2 = 2806;
  //datos.dato3 = 2106;
  //datos.dato4 = 609;

  // Envía los datos
 // radio.write(&datos, sizeof(datos));
  Serial.println("Pot 1 ");
  Serial.println(datos.dato1);
  Serial.println("Pot 2 ");
  Serial.println(datos.dato2);
  Serial.println("Pot 3 ");
  Serial.println(datos.dato3);
  Serial.println("Pot 4 ");
  Serial.println(datos.dato4);
  Serial.println("Pot 5 ");
  Serial.println(datos.dato5);
  Serial.println("Pot 6 ");
  Serial.println(datos.dato6);
  Serial.println("Datos enviados");

  delay(4000); // Espera un segundo antes de enviar los datos nuevamente
}
