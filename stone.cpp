#include "stone.hpp"
#include "ui_stone.h"

#include <QDebug>
#include "rubotcp.hpp"
#include "log.hpp"

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
    Log("connect button clicked");

    RuboTcp *tcp = new RuboTcp();
    tcp->doConnect();

}








