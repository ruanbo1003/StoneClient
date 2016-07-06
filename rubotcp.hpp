#ifndef RUBOTCP_HPP
#define RUBOTCP_HPP

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>

class Stone;

class RuboTcp : public QObject
{
    Q_OBJECT
public:
    explicit RuboTcp(Stone* win, QObject *parent = 0);


    bool doConnect();
signals:

public slots:
    void connected();
    void disconnected();
    void byteWritten(qint64 bytes);
    void readyRead();


private:
    Stone *_main_win;
    QTcpSocket *_socket;
};

#endif // RUBOTCP_HPP
