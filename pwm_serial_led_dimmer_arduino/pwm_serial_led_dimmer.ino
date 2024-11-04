const int pin2 = 2; //GPIO 2
const int frec = 5000; //frecuencia de PWM
const int res = 8; //resolución de 8 bits, valores de 0 a 255

void setup() {
  ledcAttach(pin2, frec, res);
  Serial.begin(9600); //inicia la comunicación serial a 9600 bits por seg (baud)
}

void loop() {
  if (Serial.available() > 0) //verifica la disponibilidad de comunicación serial
  {    
    int ciclo = Serial.parseInt(); //lee el valor enviado desde Qt (número entre 0 y 255)

    if (ciclo >= 0 && ciclo <= 255) //verifica que el valor esté entre 0 y 255
    {
      analogWrite(pin2, ciclo); //ajusta el ciclo de trabajo (brillo) del LED
    }
  }
}
