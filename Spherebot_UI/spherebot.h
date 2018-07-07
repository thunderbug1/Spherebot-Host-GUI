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
#include <QTimer>

#define SENT_LINE_BUFFER_MAX_SIZE 30

class spherebot : public QObject
{
    Q_OBJECT

public:
    QSerialPort *port;

    bool isConnected();
    bool send(QString cmd);
    QString generateChecksumString(QString msg);

    explicit spherebot(QObject *parent = 0);

    bool sendingFile;

signals:
    void dataSent(QString data);

    void progressChanged(int);
    void layerTransmitted();
    void fileTransmitted();

public slots:
    bool connectWithBot(QString portName);
    bool connectWithBot();
    bool disconnectWithBot();
    void processAnswer(QString answer);
    void resendLine();

    void resetState();
    void set(QString intextfile);
    void sendNext();

private slots:
    void trySendBufferLine();

private:

    bool bot_connected;
    QString lastLine;
    bool lastLineTransmitted;
    QVector<QString> toSendBuffer;

    QTimer *timeout_timer;
    QTimer *retry_timer;        //is active if the bot is not connected but data is to be sent

    // variables to send a file
    QString textfile;
    int lineCounter;
    int lineMax;
    bool ignoreFirstM01;
};

#endif // SPHEREBOT_H
