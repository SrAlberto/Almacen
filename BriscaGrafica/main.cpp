#include "brisca.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    brisca w;
    w.setStyleSheet("QMainWindow{background-image: url(:/fondo.jpg)}");
    w.show();
    return a.exec();
}
