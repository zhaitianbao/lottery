#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTextCodec *codec = QTextCodec::codecForName("GBK");
//    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    MainWindow w;
    w.show();
    return a.exec();
}
