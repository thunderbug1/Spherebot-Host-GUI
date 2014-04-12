#ifndef TXTHREAD_H
#define TXTHREAD_H
#include <QThread>
#include <QString>
#include "spherebot.h"
#include <QMessageBox>
#include <QTimer>
#include <QString>

class txThread : public QThread
{
    Q_OBJECT
public:
    txThread();
    void set(QString textfile,spherebot &bot);
    void run();
    ~txThread();
    int getLineCounter();

signals:
    void progressChanged(int);
    void layerTransmitted();
    void fileTransmitted();

public slots:
    void sendNext();
    void resetState();
private:
    QString textfile;
    int lineCounter;
    int lineMax;
    bool ignoreFirstM01;
    spherebot *bot;
};

#endif // TXTHREAD_H
