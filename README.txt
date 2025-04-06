░  ░░░░░░░░        ░░       ░░░░░░░░░       ░░░        ░░  ░░░░  ░░  ░░░░  ░░        ░░       ░░
▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒   ▒▒   ▒▒   ▒▒   ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒
▓  ▓▓▓▓▓▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓▓▓▓  ▓▓▓▓▓        ▓▓        ▓▓      ▓▓▓▓       ▓▓
█  ████████  ████████  ████  ████████  ████  █████  █████  █  █  ██  █  █  ██  ████████  ███  ██
█        ██        ██       █████████       ███        ██  ████  ██  ████  ██        ██  ████  █
                                                                                                
LED Dimmer: Qt GUI + ESP32 (PWM Control)
=========================================

This project demonstrates how to control the brightness of an LED connected to an ESP32 using a desktop GUI developed in Qt (C++), communicating via UART serial.
It combines embedded programming, GUI development, and PWM control to create a simple but complete hardware-software system.

-----------------------------------------
Desktop Application (Qt)
-----------------------------------------

The Qt application provides a GUI with:

- A QSlider widget that allows the user to choose brightness values between 0 and 255 (8-bit resolution).
- A QLabel that displays the current value being sent.
- A QSerialPort instance configured at 9600 baud to send the value over UART.

Build Instructions (Desktop):

1. Open the .pro file in Qt Creator or use qmake.
2. Ensure that the QSerialPort module is enabled.
3. Update the COM port in widget.cpp (e.g., "COM3" on Windows or "/dev/ttyUSB0" on Linux).
4. Compile and run the application.
5. Connect the ESP32 and observe the LED brightness change as you move the slider.

-----------------------------------------
Embedded Code (ESP32 - Arduino)
-----------------------------------------

The Arduino sketch runs on the ESP32 and:

- Initializes PWM on GPIO 2 with:
  - Frequency: 5000 Hz
  - Resolution: 8 bits
- Reads integer values from the serial port (0–255) and updates the PWM duty cycle to change LED brightness.

Upload Instructions (ESP32):

1. Open the .ino file in the Arduino IDE.
2. Select your ESP32 board model and the correct COM port.
3. Upload the code.
4. Make sure an LED is connected to GPIO 2 (with a resistor).
5. The ESP32 will respond to slider values from the Qt app.

-----------------------------------------
ESPAÑOL
-----------------------------------------

Aplicación de Escritorio (Qt):

La aplicación Qt ofrece una interfaz gráfica con:

- Un QSlider para seleccionar valores entre 0 y 255 que controlan el brillo del LED.
- Un QLabel que muestra el valor actual.
- Comunicación por puerto serie UART a 9600 baudios.

Código Embedded (ESP32 - Arduino):

El sketch en Arduino:

- Configura el pin GPIO 2 con PWM a 5000 Hz y resolución de 8 bits.
- Lee valores entre 0–255 desde el puerto serie.
- Controla el ciclo de trabajo PWM del LED según el valor recibido.

-----------------------------------------
Project structure
-----------------------------------------

dimmer_gui/
│
├── qt_gui/
│   ├── dimmer_gui.pro.
│   ├── dimmer_gui.pro.user
│   ├── main.cpp
│   ├── widget.cpp
│   └── widget.h
│
├── esp32_code/
│   └── dimmer_esp32.ino
│
└── README.txt

-----------------------------------------
Future Improvements
-----------------------------------------

- Auto-detect serial port.
- Bi-directional communication with status feedback.
- Add cross-platform build support.
- Package with installer or AppImage.

-----------------------------------------
Author
-----------------------------------------

Developed by Matías Alvarez Franks

Composer and software developer in training, focused on low-level audio programming, embedded systems, and digital signal processing.  
GitHub: https://github.com/mati-alvarez  
Email: matiasalvarezfranks [at] gmail [dot] com

-----------------------------------------
License
-----------------------------------------

This project is open-source and available under the MIT License.



