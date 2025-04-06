#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 300); //app window size
    setWindowTitle("LED dimmer"); //window title

    //slider config
    sendSlider = new QSlider(Qt::Vertical, this); //slider
    sendSlider->setRange(0, 255); //range 0-255
    sendSlider->setValue(0); //initial value = 0
    sendSlider->setGeometry(100, 70, 90, 130); //position in window
    sendSlider->setTickPosition(QSlider::TicksLeft); //tick position
    sendSlider->setTickInterval(20); //tick interval
    connect(sendSlider, &QSlider::valueChanged, this, &Widget::onSliderValueChanged); //connect slider

    //configure label of the value sent to the ESP32
    sentValueLabel = new QLabel("Sent value: N/A", this);
    sentValueLabel->setGeometry(100, 200, 100, 100);

    //serial port config
    serial = new QSerialPort(this); //object
    serial->setPortName("COM3"); //serial port name
    serial->setBaudRate(QSerialPort::Baud9600); //baud rate: 9600 bits per second

    //serial port opening routine
    if (!serial->open(QIODeviceBase::ReadWrite))
    {
        qDebug()<<"Error opening the port.";
    }
}

Widget::~Widget() { //window destroyer
    if(serial->isOpen()){ //close the serial port along with the window
        serial->close();
    }
}

void Widget::onSliderValueChanged(int value) //send slider value to the ESP32
{
    //qDebug()<<"Slider is active";
    if(serial->isOpen()){
        QByteArray data = QByteArray::number(value) + "\n"; //returns a byte-array representing the slider value as text.
        serial->write(data); //write value to the serial port
        //qDebug()<<value;
        sentValueLabel->setText(QString("Sent value: %1").arg(value));//show slider value on a label
    }
}
