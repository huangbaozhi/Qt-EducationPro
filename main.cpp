#include "mainwindow.h"
#include "moveblewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/images/logo.ico"));
    w.show();
    return a.exec();
}
