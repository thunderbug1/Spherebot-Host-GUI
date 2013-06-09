#include "txthread.h"

txThread::txThread()
{
    lineCounter = 0;
    bufferCounter = 0;
    checkSendBufferTimer = new QTimer(this);
    connect(checkSendBufferTimer,SIGNAL(timeout()),this,SLOT(checkBuffer()));
}

txThread::~txThread()
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
    bufferCounter = 0;
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
    bufferCounter = 0;
    drawCounter = 0;
    checkSendBufferTimer->start(SENDBUFFERINTERVAL);
}

void txThread::checkBuffer()
{
    //qDebug()<<"buffer check timer timeout";
    if(lineCounter <= lineMax)
    {
        //qDebug()<<"linecounter: " + QString::number(lineCounter);
        qDebug()<<"buffercounter: " + QString::number(bufferCounter);
        //qDebug()<<"drawcounter: " + QString::number(drawCounter);
        if(bufferCounter <= MAXBUFFERCOUNTER)
        {
            QString tmp = textfile.section("\n",lineCounter,lineCounter);
            tmp.append("\n");
            bot->send(tmp);
            double progress= (double) lineCounter/(double)lineMax;
            emit progressChanged(progress*100);
            bufferCounter++;
            lineCounter++;
        }
    }
    else
    {
        checkSendBufferTimer->stop();
        emit fileTransmitted();
    }
}

int txThread::getLineCounter()
{
    return lineCounter;
}

void txThread::checkResponse(QString msg)
{
 //   if(msg.count("G") > 1 || msg.count("M") > 1)
    if(msg.contains("ok"))
   {
        qDebug()<<"processed: " + msg + "\n";
        drawCounter++;
        bufferCounter--;
   }
}
