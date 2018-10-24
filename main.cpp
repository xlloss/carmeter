#include "mainform.h"
#include <QApplication>
#include "speed_meter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm main;
    main.show();

    return a.exec();
}
