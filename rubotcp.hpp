#ifndef RUBOTCP_HPP
#define RUBOTCP_HPP

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>

class RuboTcp : public QObject
{
    Q_OBJECT
public:
    explicit RuboTcp(QObject *parent = 0);

    void doConnect();
signals:

public slots:
    void connected();
    void disconnected();
    void byteWritten(qint64 bytes);
    void readyRead();


private:
    QTcpSocket *socket;
};

#endif // RUBOTCP_HPP
