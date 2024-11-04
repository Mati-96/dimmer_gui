#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>
#include <QSerialPort>
#include <QTimer>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onSliderValueChanged(int value); //enviar valor de slider

private:
    QSlider *sendSlider; //obj slider
    QSerialPort *serial; //obj puerto serie
    QLabel *sentValueLabel;
};
#endif // WIDGET_H
