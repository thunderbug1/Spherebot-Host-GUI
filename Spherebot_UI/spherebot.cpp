#include "spherebot.h"

spherebot::spherebot(QObject *parent) :
    QObject(parent)
{
    port = NULL;
    port_connected = false;
}

bool spherebot::connectWithBot(QString portName)
{
    port = new QextSerialPort(portName , QextSerialPort::Polling); //we create the port


    port->open(QIODevice::ReadWrite); //we open the port
    if(!port->isOpen())
    {
        //QMessageBox::warning(this, "port error", "Impossible to open the port!");
        return 0;
    }

    //we set the port properties
    port->setBaudRate(BAUD115200);//modify the port settings on your own
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    port->setRts( true );
    port->setDtr( true );
    //port->setQueryMode( QextSerialPort::EventDriven );
    port_connected = true;
    return 1;
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
        qDebug()<<"Sending: " + cmd;
        port->write((const char*)cmd.toUtf8(),cmd.length());

    }
    else
    {
        qDebug()<<port->errorString();
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
