const int pin2 = 2; //GPIO 2
const int frec = 5000; //PWM frequency
const int res = 8; //8 bit resolution, values between 0 and 255

void setup() {
  ledcAttach(pin2, frec, res);
  Serial.begin(9600); //initiate serial communication at 9600 bits per second (baud)
}

void loop() {
  if (Serial.available() > 0) //verify availability of serial communication
  {    
    int ciclo = Serial.parseInt(); //read a the value sent from the console (between 0 and 255)

    if (ciclo >= 0 && ciclo <= 255) //verify that the value is between 0 and 255
    {
      analogWrite(pin2, ciclo); //adjust LED brightness (cycle)
    }
  }
}
