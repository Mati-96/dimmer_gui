#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 300); //tamaño de la ventana de la app
    setWindowTitle("LED dimmer"); //título de la ventana

    //config slider
    sendSlider = new QSlider(Qt::Vertical, this); //slider
    sendSlider->setRange(0, 255); //rango 0-255
    sendSlider->setValue(0); //valor inicial = 0
    sendSlider->setGeometry(100, 70, 90, 130); //posición en ventana
    sendSlider->setTickPosition(QSlider::TicksLeft); //posición de ticks
    sendSlider->setTickInterval(20); //intervalo de ticks
    connect(sendSlider, &QSlider::valueChanged, this, &Widget::onSliderValueChanged); //conectar slider

    //config label de valor enviado a ESP32
    sentValueLabel = new QLabel("Valor enviado: N/A", this);
    sentValueLabel->setGeometry(100, 200, 100, 100);

    //config puerto serie
    serial = new QSerialPort(this); //obj
    serial->setPortName("COM3"); //nombre de puerto serie
    serial->setBaudRate(QSerialPort::Baud9600); //baud com serial 9600 bits p/seg

    //rutina de apertura puerto serie
    if (!serial->open(QIODeviceBase::ReadWrite))
    {
        qDebug()<<"Error al abrir el puerto.";
    }
}

Widget::~Widget() { //destructor de la ventana
    if(serial->isOpen()){ //cerrar el puerto con la ventana
        serial->close();
    }
}

void Widget::onSliderValueChanged(int value) //enviar valor del slider a la ESP32
{
    //qDebug()<<"Slider activo";
    if(serial->isOpen()){
        QByteArray data = QByteArray::number(value) + "\n"; //valor del slider = cadena
        serial->write(data); //enviar valor al puerto serie
        //qDebug()<<value; //mostrar valor en consola
        sentValueLabel->setText(QString("Valor enviado: %1").arg(value));//mostrar valor en label
    }
}
