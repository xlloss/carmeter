#include "turn_signal.h"
#include "ui_turn_signal.h"
#include "QDebug"

turn_signal::turn_signal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::turn_signal)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timout_update()));
    timer->start();
    flicker = 1;
}

void turn_signal::timout_update()
{

    if (flicker) {
        signal_img = signal_on_img;
    } else {
        signal_img = signal_off_img;
    }

    flicker = flicker ^ 0x01;
    update();
}

turn_signal::~turn_signal()
{
    delete ui;
}

void turn_signal::load_signal_on_img(QString siganl_img_on_name)
{
    signal_on_img.load(siganl_img_on_name);
}

void turn_signal::load_signal_off_img(QString siganl_img_off_name)
{
    signal_off_img.load(siganl_img_off_name);
}


void turn_signal::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, signal_img);

}
