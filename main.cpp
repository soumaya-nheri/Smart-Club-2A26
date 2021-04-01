#include "mainwindow.h"
#include "planningcheval.h"
#include "cheval.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
