#include "spherebot.h"

spherebot::spherebot(QObject *parent) :
    QObject(parent)
{
    port = new QSerialPort();
    port_connected = false;
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
    port->setBaudRate(QSerialPort::Baud115200);//modify the port settings on your own
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

bool spherebot::send(QString cmd)
{
    if(port->isOpen())
    {
        port->flush();
        if(cmd[cmd.size()-1] != '\n') cmd.append("\n");
        //qDebug()<<"Sending: " + cmd;
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

bool spherebot::isConnected()
{
    return port_connected;
}
