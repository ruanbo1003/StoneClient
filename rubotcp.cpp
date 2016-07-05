#include "rubotcp.hpp"

#include <QDebug>
#include "log.hpp"


RuboTcp::RuboTcp(QObject *parent) : QObject(parent)
{

}

void RuboTcp::doConnect()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(byteWritten(qint64)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    Log("connecting...");

    socket->connectToHost("127.0.0.1", 8881);

    if(!socket->waitForConnected(5000))
    {
        Log("connect failed");
    }
}

void RuboTcp::connected()
{
    Log("connected...");

}

void RuboTcp::disconnected()
{
    Log("disconnected...");
}


void RuboTcp::byteWritten(qint64 bytes)
{
    Log("%lld bytes written", bytes);
}

void RuboTcp::readyRead()
{
    qDebug() << "reading...";

    QByteArray data = socket->readAll();
}
