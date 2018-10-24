#include "mainform.h"
#include <QApplication>
#include "speed_meter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   Widget w;
 //   w.show();
    MainForm main;
    main.show();

//      SpeedMeter s;
//      s.show();
    return a.exec();
}
