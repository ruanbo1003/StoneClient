#include "stone.hpp"
#include "ui_stone.h"

#include <QDebug>
#include <QDesktopWidget>
#include <QToolButton>
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

void Stone::init_ui()
{
    this->setWindowIcon(QIcon(":/UI/stone.ico"));

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screen_rect = desktopWidget->availableGeometry();

    Log("height:%d, width:%d", screen_rect.height(), screen_rect.width());

    int width = screen_rect.width()/4;
    int height = screen_rect.height()/4;
    QRect stone_rect = QRect((screen_rect.width()-width)/2, (screen_rect.height()-height)/2, width, height);

    this->setGeometry(stone_rect);
    this->setFixedSize(width, height);
}

void Stone::on_connected()
{
    QPushButton *connectBtn = this->findChild<QPushButton*>("connectBtn");
    if(connectBtn)
    {
        connectBtn->setHidden(true);
    }
}

void Stone::on_disconnected()
{
    QPushButton *connectBtn = this->findChild<QPushButton*>("connectBtn");
    if(connectBtn)
    {
        connectBtn->setHidden(false);
    }
}


void Stone::init()
{
    _tcp = new RuboTcp(this);

    init_ui();
}

void Stone::on_connectBtn_clicked()
{
    if(_tcp->doConnect() == false)
    {
        Log("connect to server failed");
    }
    else
    {
        Log("connect to server success");
    }
}








