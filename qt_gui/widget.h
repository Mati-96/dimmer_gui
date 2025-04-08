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
    void onSliderValueChanged(int value); //send slider value

private:
    QSlider *sendSlider; //slider object
    QSerialPort *serial; //serial port object
    QLabel *sentValueLabel;
};
#endif // WIDGET_H
