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


#define ROTE_LOCATE0_MODE SPPED_0
#define ROTE_LOCATE1_MODE SPPED_0 + 30
#define ROTE_LOCATE2_MODE SPPED_0 + 50
#define ROTE_LOCATE3_MODE SPPED_0 + 70
#define ROTE_LOCATE4_MODE SPPED_0 + 90


SpeedMeter::SpeedMeter(QWidget *parent) :
    QWidget(parent)
    //,ui(new Ui::SpeedMeter)
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(timout_update()));
//    timer->start(10);

    rot_cnt = SPPED_0;
    rot_dir = DIR_RIGHT;
}

SpeedMeter::~SpeedMeter()
{
//    delete ui;
    delete timer;
}

void SpeedMeter::set_rot_dir(int rot_dir_set)
{
    rot_dir = rot_dir_set;
}

void SpeedMeter::set_rot_start(int statr_locate)
{
    switch (statr_locate) {

    case ROTE_LOCATE0:
        rot_cnt = ROTE_LOCATE0_MODE;
        break;

    case ROTE_LOCATE1:
        rot_cnt = ROTE_LOCATE1_MODE;
        break;

    case ROTE_LOCATE2:
        rot_cnt = ROTE_LOCATE2_MODE;
        break;

    case ROTE_LOCATE3:
        rot_cnt = ROTE_LOCATE3_MODE;
        break;

    case ROTE_LOCATE4:
        rot_cnt = ROTE_LOCATE4_MODE;
        break;

    default:
        break;
    }
}


void SpeedMeter::load_image_bg(QString bg_name)
{
    QPalette palette;
    speed_meter_img.load(bg_name);
    width = speed_meter_img.width();
    height = speed_meter_img.height();

    palette.setBrush(QPalette::Background, speed_meter_img);
    this->setPalette(palette);
    this->setGeometry(0, 0, speed_meter_img.width(), speed_meter_img.height());
}

void SpeedMeter::load_image_needle(QString needle_name)
{
      if (speed_need_img.load(needle_name) == false)
        qDebug("speed_need_img load fail");
}

void SpeedMeter::start_paint(int speed)
{
    timer->start(speed);
}

void SpeedMeter::start_paint()
{
    timer->start(10);
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
