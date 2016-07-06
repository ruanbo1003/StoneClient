#include "stone.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Stone w;
    w.init();

    w.show();

    return a.exec();
}
