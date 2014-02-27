#ifndef TXTHREAD_H
#define TXTHREAD_H
#include <QThread>
#include <QString>
#include "spherebot.h"
#include <QMessageBox>
#include <QTimer>

//#define Watchdog

class txThread : public QThread
{
    Q_OBJECT
public:
    txThread();
    void set(QString textfile,spherebot &bot);
    void run();
    ~txThread();
    int getLineCounter();
    QTimer *watchdogTimer;

signals:
    void progressChanged(int);
    void fileTransmitted();

public slots:
    void sendNext();
    void watchdogTimeout();
private:
    QString textfile;
    int lineCounter;
    int lineMax;
    spherebot *bot;
};

#endif // TXTHREAD_H
