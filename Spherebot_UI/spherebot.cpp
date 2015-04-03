#include "spherebot.h"

spherebot::spherebot(QObject *parent) :
    QObject(parent)
{
    port = new QSerialPort();
    port_connected = false;
//    lineCounter = 0;
    lastLineTransmitted = true;
}

bool spherebot::connectWithBot()
{
    port->open(QIODevice::ReadWrite); //we open the port
    if(!port->isOpen())
    {
        //QMessageBox::warning(this, "port error", "Impossible to open the port!");
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
    port_connected = true;
//    lineCounter = 0;
//    sentLineBuffer.clear();

    return 1;
}

bool spherebot::connectWithBot(QString portName)
{
    port->setPortName(portName);
    return connectWithBot();
    lastLineTransmitted = true;
}

bool spherebot::disconnectWithBot()
{
    qDebug("port closed");
    port->close();
    port_connected = false;
    return 1;
}

void spherebot::processAnswer(QString answer)
{
//    int linenumber = getOption(line,"N");
    qDebug()<< "process answer: " << answer << endl;
    qDebug()<< "buffer: " << toSendBuffer << endl;
    if(answer.contains("rs"))
    {
        resendLine();
    }
    else if (answer.contains("ok"))
    {
        qDebug()<< "answer.contains(ok): "<< endl;
        if(toSendBuffer.size() > 0)
        {
            lastLineTransmitted = true;
            send(toSendBuffer.front());
            toSendBuffer.pop_front();
        }
        else
        {
            lastLineTransmitted = true;
        }
        emit dataSent(lastLine);
    }
    else
    {
        lastLineTransmitted = true;
        qDebug() << "answer did not contain rs or ok" << endl;
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
    qDebug()<<"checksum is: "<< cs <<endl;
    return result;
}

bool spherebot::send(QString cmd)
{
    if(port->isOpen())
    {
        if(lastLineTransmitted)
        {
         //   port->flush();

    //        cmd.remove("N");    //no line numbering is allowed in the line because it is added
    //        cmd = QString("N") + QString::number(lineCounter).append(" ").append(cmd);

            if(cmd.size() != 0)
            {
                if(cmd[cmd.size()-1] == '\n') cmd.chop(1);
            }
            cmd.append(" ");
            cmd.append(generateChecksumString(cmd));
            qDebug()<<"Sending: " + cmd;
            cmd.append("\n");
            //qDebug()<<"sending: " << cmd << endl;
            port->write((const char*)cmd.toUtf8(),cmd.length());

            lastLine = cmd;
            lastLineTransmitted = false;
        }
        else
        {
            toSendBuffer.push_back(cmd);
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
//    for(int i = 0;i < sentLineBuffer.size(); i++)
//    {
//        if(sentLineBuffer[linenumber].linenumber == linenumber)
//        {
//            send(sentLineBuffer[linenumber].content);
//        }
//        else
//        {
//            qDebug()<<"ERROR: could not find line: " << linenumber << " in sentLineBuffer!! " << endl;
//        }
//    }
    qDebug()<<"Resending: " << lastLine << endl;
    port->write((const char*)lastLine.toUtf8(),lastLine.length());
}

bool spherebot::isConnected()
{
    return port_connected;
}
