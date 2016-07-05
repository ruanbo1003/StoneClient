#include "stone.hpp"
#include "ui_stone.h"

#include <QtNetwork/QTcpSocket>

Stone::Stone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stone)
{
    ui->setupUi(this);
}

Stone::~Stone()
{
    delete ui;
}

void Stone::on_connectBtn_clicked()
{
    QTcpSocket *client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("127.0.0.1"), 8881);

}
