/// Dimmer ///

/// Archivo de Qt ///

Código en Qt para controlar el nivel de brillo de un LED en la tarjeta ESP 32 con una GUI.

- Funciona a través de modulación por ancho de pulsos a una frecuencia de 5000 Hz y con una resolución de 8 bits.

- Utiliza el Widget "QSlider" para crear un slider que permita controlar el nivel de brillo del LED. El Slider envía valores entre 0 y 255 debido a la resolución de 8 bits.

- Utiliza el Widget "QLabel" para mostrar el valor enviado a la ESP 32 (0 a 255).


/// Archivo de Arduino ///

Código en Arduino para cargar a la tarjeta ESP 32.

- Configura el pin 2 de la tarjeta ESP 32 para que inicie la configuración serial (9600 baud).

- Lee un valor entre 0 y 255 enviado desde la terminal para controlar el brillo del LED.



 