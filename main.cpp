#include <QApplication>
#include <QTextCodec>
#include "controlviewwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec* codec = QTextCodec::codecForName("Cp866");
    QTextCodec::setCodecForLocale(codec);
    ControlViewWidget widget;
    return a.exec();
}
