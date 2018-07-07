#include "rxthread.h"

rxThread::rxThread(spherebot *uibot)
{
    bot = uibot;
}

rxThread::~rxThread()
{
}

void rxThread::receiveData()
{
    if(bot->port->canReadLine())
    {
        while(bot->port->canReadLine())
        {
            line = bot->port->readLine(1024);
            //qDebug()<< "receiving raw: "<< line<< endl;
            while(line.endsWith('\n')) line.chop(1);
            if( line != "")
            {
                qDebug()<< "receiving: "<< line<< endl;
                emit lineReceived(line);
            }
        }
    }
}

void rxThread::run()
{
    qDebug()<< "start Receiver";
    line = "";
}
