#ifndef TXTHREAD_H
#define TXTHREAD_H
#include <QThread>
#include <QString>
#include "spherebot.h"
#include <QMessageBox>
#include <QTimer>

#define MAXBUFFERCOUNTER 1
#define SENDBUFFERINTERVAL 5

class txThread : public QThread
{
    Q_OBJECT
public:
    txThread();
    void set(QString textfile,spherebot &bot);
    void run();
    ~txThread();
    int getLineCounter();
    QTimer *checkSendBufferTimer;

signals:
    void progressChanged(int);
    void fileTransmitted();

public slots:
    void checkResponse(QString msg);
    void checkBuffer();
private:
    QString textfile;
    int lineCounter;
    int lineMax;
    int bufferCounter;
    int drawCounter;
    spherebot *bot;
};

#endif // TXTHREAD_H
