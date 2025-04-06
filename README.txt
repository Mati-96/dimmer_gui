/// Dimmer ///

ENG

/// Qt file ///

Qt code controlls the brightness level of an LED in the ESP32 card with a GUI.

- The code uses PWM at 5000 Hz and 8 bit resolution.

- The "QSlider" Widget creates a slider to allow the user to control the LEDs brightness level. The slider sends values between 0 and 255 (8 bit resolution).

- The "QLabel" Widget shows the value sent to the ESP32 card (0 to 255).


/// Arduino file ///

Arduino code to load in the ESP 32 card.

- Configures the 2nd pin of the ESP32 card to initiate serial configuration (at 9600 baud).

- Reads a value between 0 and 255 sent through the terminal to control the brightness level of the ESP32's LED.


ESP

/// Archivo de Qt ///

Código en Qt para controlar el nivel de brillo de un LED en la tarjeta ESP 32 con una GUI.

- Funciona a través de modulación por ancho de pulsos a una frecuencia de 5000 Hz y con una resolución de 8 bits.

- Utiliza el Widget "QSlider" para crear un slider que permita controlar el nivel de brillo del LED. El Slider envía valores entre 0 y 255 debido a la resolución de 8 bits.

- Utiliza el Widget "QLabel" para mostrar el valor enviado a la ESP 32 (0 a 255).


/// Archivo de Arduino ///

Código en Arduino para cargar a la tarjeta ESP 32.

- Configura el pin 2 de la tarjeta ESP 32 para que inicie la configuración serial (9600 baud).

- Lee un valor entre 0 y 255 enviado desde la terminal para controlar el brillo del LED.
