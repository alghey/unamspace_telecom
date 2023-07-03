const int joystickPinX = A0; // Pin analógico del eje X del joystick
const int joystickPinY = A1; // Pin analógico del eje Y del joystick
const int SW = 2; // Pin digital del SW
int valorX = 0; // Variable para almacenar el valor de X
int valorY = 0; // Variable para almacenar el valor de Y
bool boton = false; // Variable para validar el estado del botón

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  valorX = analogRead(joystickPinX); // Lee el valor del eje X (0-1023)
  valorY = analogRead(joystickPinY); // Lee el valor del eje Y (0-1023)
  boton = digitalRead(SW); // Lee el estados del botón: activado o no activado
  // Mapea los valores leídos a un rango de -100 a 100 para acomodarlos en el intervalo [-100, 100]
  int mappedX = map(valorX, 0, 1023, -100, 100);
  int mappedY = map(valorY, 0, 1023, 100, -100);
  // Calcula el ángulo utilizando la función atan2()
  float ang = atan2(mappedY, mappedX) * (180.0 / PI); // Convierte el ángulo a grados
  // Envía las coordenadas del joystick en el formato [a, b]
  Serial.print("La úbicación del Joystick es: [");
  Serial.print(mappedX);
  Serial.print(",");
  Serial.print(mappedY);
  Serial.println("]");
  Serial.print("El ánngulo del Joystick es: ");
  Serial.println(ang);
  Serial.print("El estado del botón es: ");
  Serial.println(boton);
  Serial.println("----------------");
  delay(1000);
  
  
}
