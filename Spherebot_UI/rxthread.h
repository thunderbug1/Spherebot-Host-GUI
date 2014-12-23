#ifndef RXTHREAD_H
#define RXTHREAD_H

#include <QThread>
#include "spherebot.h"
#include <QTimer>
#include <QString>

class rxThread : public QThread
{
    Q_OBJECT
public:
    rxThread(spherebot *);
    void set(QString textfile,spherebot &bot);
    void run();
    ~rxThread();

signals:
    void lineReceived(QString);

public slots:
    void receiveData();
private:
    QString line;
    spherebot *bot;
};

#endif // RXTHREAD_H
