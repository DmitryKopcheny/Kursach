#include "mainwindow.h"
#include <QFile>
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile styleF;

    styleF.setFileName(":/new/lightstyle.css");
    styleF.open(QFile::ReadOnly);
    QString cssStr = styleF.readAll();

    qApp->setStyleSheet(cssStr);


    w.show();
    return a.exec();
}
