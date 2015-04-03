#ifndef SPHEREBOT_H
#define SPHEREBOT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QtGui>
#include <iostream>
#include <QtCore/QCoreApplication>
#include <QVector>

#define SENT_LINE_BUFFER_MAX_SIZE 30

class spherebot : public QObject
{
    Q_OBJECT
public:
    QSerialPort *port;

    bool isConnected();
    bool send(QString cmd);
    QString generateChecksumString(QString msg);
    void resendLine();

    explicit spherebot(QObject *parent = 0);
signals:
    void dataSent(QString data);
public slots:
    bool connectWithBot(QString portName);
    bool connectWithBot();
    bool disconnectWithBot();
    void processAnswer(QString answer);
private:
    bool port_connected;
    QString lastLine;
    bool lastLineTransmitted;
    QVector<QString> toSendBuffer;
};

#endif // SPHEREBOT_H
