#include "videogame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    std::srand(std::time(0));
    QApplication a(argc, argv);
    videogame w;
    w.show();
    return a.exec();
}






