#ifndef STONE_HPP
#define STONE_HPP

#include <QMainWindow>

namespace Ui {
class Stone;
}

class Stone : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stone(QWidget *parent = 0);
    ~Stone();

private slots:
    void on_connectBtn_clicked();

private:
    Ui::Stone *ui;
};

#endif // STONE_HPP
