#ifndef STONE_HPP
#define STONE_HPP

#include <QMainWindow>
#include <rubotcp.hpp>

namespace Ui {
class Stone;
}

class Stone : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stone(QWidget *parent = 0);
    ~Stone();

private:
    void init_ui();

public slots:
    void on_connected();
    void on_disconnected();

public:
    void init();


private slots:
    void on_connectBtn_clicked();

private:
    Ui::Stone *ui;
    RuboTcp *_tcp;
};

#endif // STONE_HPP
