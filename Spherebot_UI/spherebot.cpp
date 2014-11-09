#include "spherebot.h"

spherebot::spherebot(QObject *parent) :
    QObject(parent)
{
    port = new QSerialPort();
    port_connected = false;
    lastSentLine = "";
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
    port->setBaudRate(256000);//modify the port settings on your own
    port->setFlowControl(QSerialPort::NoFlowControl);
    port->setParity(QSerialPort::NoParity);
    port->setDataBits(QSerialPort::Data8);
    port->setStopBits(QSerialPort::OneStop);
    port_connected = true;
    return 1;
}

bool spherebot::connectWithBot(QString portName)
{
    port->setPortName(portName);
    return connectWithBot();
}

bool spherebot::disconnectWithBot()
{
    qDebug("port closed");
    port->close();
    port_connected = false;
    return 1;
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
        port->flush();
        lastSentLine.clear();
        lastSentLine.append(cmd);
        if(cmd.size() != 0)
        {
            if(cmd[cmd.size()-1] == '\n') cmd.chop(1);
        }
        cmd.append(" ");
        cmd.append(generateChecksumString(cmd));
        qDebug()<<"Sending: " + cmd;
        cmd.append("\n");
        port->write((const char*)cmd.toUtf8(),cmd.length());
    }
    else
    {
        qDebug()<<port->errorString()<<" port is not open";
        return false;
    }
    cmd.chop(1);
    emit dataSent(cmd);
    return true;
}

bool spherebot::repeatLastLine()
{
    return send(lastSentLine);
}

bool spherebot::isConnected()
{
    return port_connected;
}
