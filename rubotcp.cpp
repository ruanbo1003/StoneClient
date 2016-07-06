#include "rubotcp.hpp"

#include <QDebug>
#include "log.hpp"
#include "stone.hpp"

RuboTcp::RuboTcp(Stone* win, QObject *parent) : QObject(parent)
{
    _main_win = win;
}

bool RuboTcp::doConnect()
{
    _socket = new QTcpSocket(this);

    connect(_socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(_socket, SIGNAL(connected()), _main_win, SLOT(on_connected()));

    connect(_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(_socket, SIGNAL(disconnected()), _main_win, SLOT(on_disconnected()));

    connect(_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(byteWritten(qint64)));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    Log("connecting...");

    _socket->connectToHost("127.0.0.1", 8881);

    if(!_socket->waitForConnected(3000))
    {
        Log("connect failed");
        return false;
    }

    return true;
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

    QByteArray data = _socket->readAll();
}
