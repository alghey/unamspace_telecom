const int joystickPinX = A0; // Pin analógico del eje X del joystick
const int joystickPinY = A1; // Pin analógico del eje Y del joystick
const int SW = 2; // Pin digital del SW
float valorX = 0; // Variable para almacenar el valor de X
float valorY = 0; // Variable para almacenar el valor de Y
bool boton = false; // Variable para validar el estado del botón
//Variables para el puente H:
//variables Motores
int MotorIzquierdoAdelante  = 3; //pin Digital
int MotorIzquierdoAtras     = 4; //pin Digital
int MotorDerechoAdelante    = 7; //pin Digital
int MotorDerechoAtras       = 8; //pin Digital
int pinVelocidadDerecha     = 6; //pin PWM
int pinVelocidadIzquierda   = 5; //pin PWM
int velocidad = 125;//velocidad motores(0-255)

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
   //activar señales del puente h
  pinMode(MotorIzquierdoAdelante,OUTPUT);
  pinMode(MotorDerechoAdelante,OUTPUT);
  pinMode(MotorIzquierdoAtras,OUTPUT);
  pinMode(MotorDerechoAtras,OUTPUT);
  Serial.println("Esta es una prueba para el control del puente H");
}

void loop() {
  valorX = analogRead(joystickPinX); // Lee el valor del eje X (0-1023)
  valorY = analogRead(joystickPinY); // Lee el valor del eje Y (0-1023)
  boton = digitalRead(SW); // Lee el estados del botón: activado o no activado
  // Mapea los valores leídos a un rango de -100 a 100 para acomodarlos en el intervalo [-100, 100]
  float mappedX = map(valorX, 0, 1023, -100, 100);
  float mappedY = map(valorY, 0, 1023, 100, -100);
  // Calcula el ángulo utilizando la función atan2()
  float ang = atan2(mappedY, mappedX) * (180.0 / PI); // Convierte el ángulo a grados
  float magnitud = sqrt(pow(mappedY,2)+pow(mappedX,2));
  // Envía las coordenadas del joystick en el formato [a, b]
  Serial.print("La úbicación del Joystick es: [");
  Serial.print(mappedX);
  Serial.print(",");
  Serial.print(mappedY);
  Serial.println("]");
  Serial.print("El ánngulo del Joystick es: ");
  Serial.println(ang);
  Serial.print("La magnitud del vector es: ");
  Serial.println(magnitud);
  Serial.print("El estado del botón es: ");
  Serial.println(boton);
  Serial.println("----------------");
  delay(1000);
  if(ang=0 and mappedX=0 and mappedY=0){
    carroDetenido();
    }
  if(ang=0 and mappedX=100 and mappedY=0){
    carroGiraDerecha();
    }
  if(ang=0 and mappedX=0 and mappedY=100){
    carroGiraIzquierda();
    }
  if(ang>0 and ang<180){
    carroAvanzaAdelante();
    }
  if(ang<0){
    carroAvanzaAtras();
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
