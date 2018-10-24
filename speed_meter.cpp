#include "speed_meter.h"
#include "ui_speed_meter.h"
#include <QPainter>
#include <qdebug.h>
#include <QTimer>

#define ANGLE_99 99
#define ANGLE_360 360
#define ANGLE_224 224

#define SPPED_0 ANGLE_224
#define SPPED_80 ANGLE_360
#define SPPED_140 SPPED_80 + ANGLE_99

#define DIR_RIGHT 0
#define DIR_LEFT 1

SpeedMeter::SpeedMeter(QWidget *parent) :
    QWidget(parent)
    //,ui(new Ui::SpeedMeter)
{
    QTimer *timer = new QTimer(this);;
    QPalette palette;

//    ui->setupUi(this);

    speed_meter_img.load(":/meter/png_rec/MphSpeedMeterBg.png");
    width = speed_meter_img.width();
    height = speed_meter_img.height();

    if (speed_need_img.load(":/meter/png_rec/NeedleBg.png") == false)
        qDebug("speed_need_img load fail");

    palette.setBrush(QPalette::Background, speed_meter_img);
    this->setPalette(palette);
    this->setGeometry(0, 0, speed_meter_img.width(), speed_meter_img.height());

    connect(timer, SIGNAL(timeout()), this, SLOT(timout_update()));
    timer->start(10);

    rot_cnt = SPPED_0;
    rot_dir = DIR_RIGHT;
}

SpeedMeter::~SpeedMeter()
{
//    delete ui;
}

void SpeedMeter::timout_update()
{
    if (rot_cnt >= SPPED_140) {
        rot_dir = DIR_LEFT;
    } else if (rot_cnt <= SPPED_0) {
        rot_dir = DIR_RIGHT;
    }

    if (rot_dir == DIR_RIGHT)
        rot_cnt++;
    else
        rot_cnt--;

    update();
}

void SpeedMeter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QTransform trans;
    painter.drawPixmap(0, 0, speed_meter_img);

    trans.translate(speed_meter_img.width()/2, speed_meter_img.height()/2);
    trans.rotate(rot_cnt);
    trans.translate(-(speed_meter_img.width()/2), -(speed_meter_img.width()/2));
    painter.setTransform(trans);
    painter.drawImage(0, 0, speed_need_img);
}
