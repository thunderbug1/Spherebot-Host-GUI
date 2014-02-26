#include "txthread.h"

txThread::txThread()
{
    lineCounter = 0;

    watchdogTimer = new QTimer();
    watchdogTimer->setInterval(1000);       //because of sudden stops during sending a file
}                                           //I use a watchdogTimer to force sending the next
                                            //command if there is a too long pause of communication
txThread::~txThread()                       //This is only a workaround!!
{

}

QString removeComments(QString intext)
{
    ////////////////////////////////////////////////remove comments
    QString outTmp1,outTmp2;
    bool state=1;   //1= send, 0 = ignore
    for(int i=0;i<intext.size();i++)
    {
        if(intext.at(i) == '(' ) state=0;
        if(state == 1) outTmp1.append(intext[i]);
        if(intext.at(i) == ')' ) state=1;
    }
    //////////////////////////////////////////////////remove empty lines
    for(int i=0;i<outTmp1.size();i++)
        {
            if(i != outTmp1.size())
            {
                if(outTmp1[i] == '\n' && outTmp1[i+1] == '\n') i++;
                else outTmp2.append(outTmp1[i]);
            }
        }
        ///////////////////////////////////////////////////
    return outTmp2;
}

void txThread::set(QString intextfile,spherebot &uibot)
{
    lineCounter = 0;
    textfile.clear();
    textfile.append(removeComments(intextfile));
    qDebug()<<"The textfile String is: \n\n" + textfile + "\n\nENDE\n\n";
    lineMax = textfile.count("\n");
    bot = &uibot;
}

void txThread::run()
{
    qDebug()<<"entering run";
    lineCounter = 0;
    watchdogTimer->start();
    sendNext();
}

void txThread::sendNext()
{
    QString tmp;
    if(lineCounter <= lineMax)
    {
        tmp = textfile.section("\n",lineCounter,lineCounter);
        tmp.append("\n");
        bot->send(tmp);
        double progress= (double) lineCounter/(double)lineMax;
        emit progressChanged(progress*100);
        lineCounter++;
    }
    else
    {
        watchdogTimer->stop();
        emit fileTransmitted();
        return;
    }
    watchdogTimer->start();
    if(tmp.contains("G4"))
    {
        msleep(300);
    }
}

void txThread::watchdogTimeout()
{
    qDebug()<<"watchdogTimeout";
    sendNext();
}

int txThread::getLineCounter()
{
    return lineCounter;
}
