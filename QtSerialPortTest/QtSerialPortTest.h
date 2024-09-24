#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtSerialPortTest.h"
#include <qserialport.h>
#include <QSerialPortInfo>

class QtSerialPortTest : public QMainWindow
{
    Q_OBJECT

public:
    QtSerialPortTest(QWidget* parent = nullptr);
    ~QtSerialPortTest();

private:
    Ui::QtSerialPortTestClass ui;
    QSerialPort* port;

public slots:
    void onOpenPortButtonClicked();
    void onSerialPortReadyRead();
    void onSendMessageButtonClicked();
};