#ifndef SPHEREBOT_H
#define SPHEREBOT_H

#include <QObject>
#include <qextserialport.h>
#include <QString>
#include <QtGui>
#include <iostream>
#include <QtCore/QCoreApplication>

class spherebot : public QObject
{
    Q_OBJECT
public:
    QextSerialPort *port;

    bool isConnected();
    bool send(QString cmd);
    explicit spherebot(QObject *parent = 0);
signals:
    void dataSent(QString data);
public slots:
    bool connectWithBot(QString portName);
    bool disconnectWithBot();
private:
    bool port_connected;
};

#endif // SPHEREBOT_H
