#include "spherebot.h"

spherebot::spherebot(QObject *parent) :
    QObject(parent)
{
    port = new QSerialPort();
    bot_connected = false;
//    lineCounter = 0;
    lastLineTransmitted = true;
    timeout_timer = new QTimer();
    timeout_timer->setInterval(5000);
    retry_timer = new QTimer();
    retry_timer->setInterval(50);
    connect(timeout_timer,SIGNAL(timeout()),this,SLOT(resendLine()));
    connect(retry_timer,SIGNAL(timeout()),this,SLOT(trySendBufferLine()));
    resetState();
}

bool spherebot::connectWithBot()
{
    port->open(QIODevice::ReadWrite); //we open the port
    if(!port->isOpen())
    {
        //QMessageBox::warning(this, "port error", "Impossible to open the port!");
        qDebug()<< "Impossible to open the port!" << endl;
        return 0;
    }

    //we set the port properties
    //port->setBaudRate(9600);
    port->setBaudRate(57600);
    //port->setBaudRate(115200);//modify the port settings on your own
    //port->setBaudRate(256000);
    port->setFlowControl(QSerialPort::NoFlowControl);
    port->setParity(QSerialPort::NoParity);
    port->setDataBits(QSerialPort::Data8);
    port->setStopBits(QSerialPort::OneStop);
//    lineCounter = 0;
//    sentLineBuffer.clear();

    return 1;
}

bool spherebot::connectWithBot(QString portName)
{
    port->setPortName(portName);
    lastLineTransmitted = true;
    return connectWithBot();
}

bool spherebot::disconnectWithBot()
{
    qDebug("port closed");
    if(port->isOpen())
        port->close();
    bot_connected = false;
    this->resetState();
    return 1;
}

void spherebot::processAnswer(QString answer)
{
//    int linenumber = getOption(line,"N");
    //qDebug()<< "process answer: " << answer << endl;
    //qDebug()<< "buffer: " << toSendBuffer << endl;
    if(answer.contains("rs"))
    {
        resendLine();
    }
    else if (answer.contains("ok"))
    {
        //qDebug()<< "answer.contains(ok): "<< endl;
        lastLineTransmitted = true;
        timeout_timer->stop();

        if(toSendBuffer.size() > 0)
        {
            trySendBufferLine();
        }
        else if(sendingFile)
        {
            if( toSendBuffer.size() == 0 && lineCounter > lineMax)
            {
               emit fileTransmitted();
            }
            sendNext();
        }
        else
        {
            //everything sent
            retry_timer->stop();
        }
        emit dataSent(lastLine);
    }
    else if(answer.contains("Spherebot"))
    {
        //qDebug() << "received version" << endl;
        bot_connected = true;
    }
    else
    {
        qDebug() << "answer did not contain rs or ok or Spherebot" << endl;
        qDebug() << "answer was:" << answer << endl;
    }
}

QString spherebot::generateChecksumString(QString msg)
{
    QString result = "*";   //"*" is the startcharacter of the checksum
    std::string msgString= msg.toStdString();
    int cs = 0;
    for(int i=0;i<msg.size();i++)
    {
        cs = cs ^ (int)msgString[i];
        cs &= 0xff;  // Defensive programming...
    }
    result += QString::number(cs);
    //qDebug()<<"checksum is: "<< cs <<endl;
    return result;
}

bool spherebot::send(QString cmd)
{
    if(port->isOpen())
    {
        while( lastLine.endsWith('\n') || lastLine.endsWith('\r')) lastLine.chop(1);

        cmd.append(" ");
        cmd.append(generateChecksumString(cmd));
        cmd.append('\n');

        if(bot_connected)
        {
            if(lastLineTransmitted)
            {
                qDebug()<<"Sending: " + cmd;
                int er = port->write((const char*)cmd.toUtf8(),cmd.length());
                if (er == -1)
                    qDebug() << "an error occured while writing to the port!!" << endl;
                //qDebug() << "flush result: " << port->flush();
                lastLine = cmd;
                lastLineTransmitted = false;
                timeout_timer->start();
            }
            else
            {
                toSendBuffer.push_back(cmd);
            }
        }
        else
        {
            toSendBuffer.push_back(cmd);
            qDebug()<<"Buffer: " << toSendBuffer<< endl;
            retry_timer->start();
        }
    }
    else
    {
        qDebug()<<port->errorString()<<" port is not open";
        return false;
    }
    return true;
}

void spherebot::resendLine()
{
    if(lastLine == "")
    {
        timeout_timer->stop();
    }
    else if( bot_connected)
    {
        port->write((const char*)lastLine.toUtf8(),lastLine.length());
        //while( lastLine.endsWith('\n')) lastLine.chop(1);
        qDebug()<<"Resending: " << lastLine << endl;
    }
}

void spherebot::trySendBufferLine()
{
    qDebug()<<"try sending buffer: " << toSendBuffer.front() << endl;
    if(lastLineTransmitted && bot_connected)
    {
        if(toSendBuffer.size() > 0)
        {
            QString cmd = toSendBuffer.front();
            toSendBuffer.pop_front();
            port->write((const char*)cmd.toUtf8(),cmd.length());

            lastLine = cmd;
            lastLineTransmitted = false;
            timeout_timer->start();
        }
        retry_timer->stop();
    }
}

bool spherebot::isConnected()
{
    return bot_connected;
}


void spherebot::resetState()
{
    lineCounter = 0;
    ignoreFirstM01 = true;
    sendingFile = false;
    toSendBuffer.clear();
    lastLine = "";
    lineCounter = 0;
    retry_timer->stop();
    timeout_timer->stop();
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
                if(!(outTmp1[i] == '\n' && outTmp1[i+1] == '\n'))
                {
                    outTmp2.append(outTmp1[i]);
                }
            }
        }
    /////////////////////////////////////////////////// remove last line if empty
    if(outTmp2.endsWith("\n")) outTmp2.chop(1);
    /////////////////////////////////////////////////// remove first line if empty
    if(outTmp2.startsWith("\n")) outTmp2.remove(0,1);
    ///////////////////////////////////////////////////
    return outTmp2;
}

void spherebot::set(QString intextfile)
{
    lineCounter = 0;
    textfile.clear();
    textfile.append(removeComments(intextfile));
    //qDebug()<<"The textfile String is: \n\n" + textfile + "\n\nENDE\n\n";
    lineMax = textfile.count("\n");
}

void spherebot::sendNext()
{
    QString tmp;
    if(lineCounter <= lineMax)
    {
        tmp = textfile.section("\n",lineCounter,lineCounter);
        if(tmp.contains("M01"))
        {
            if(ignoreFirstM01)
            {
                ignoreFirstM01 = false;
            }
            else
            {
                emit layerTransmitted();
            }
        }
        send(tmp);

        double progress= (double) lineCounter/(double)lineMax;
        emit progressChanged(progress*100);
        lineCounter++;
    }
}
