#include "mainform.h"
#include "ui_mainform.h"
#include "speed_meter.h"

#define  MAIN_FORM_BG ":/meter/png_rec/QML_mask.jpg"
#define  METER1_BG ":/meter/png_rec/SpeedMeterBg.png"
#define  METER2_BG ":/meter/png_rec/MphSpeedMeterBg.png"
#define  METER_NEEDLE ":/meter/png_rec/NeedleBg.png"


MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    QPalette palette;
    mianform_bg_img.load(MAIN_FORM_BG);

    ui->setupUi(this);

    palette.setBrush(QPalette::Background, mianform_bg_img);
    this->setPalette(palette);

    speedmeter = new SpeedMeter(this);
    speedmeter->load_image_bg(METER1_BG);
    speedmeter->load_image_needle(METER_NEEDLE);
    speedmeter->start_paint();
    speedmeter->setGeometry(0, 0, speedmeter->width, speedmeter->height);
    speedmeter->show();


    mph_speedmeter = new SpeedMeter(this);
    mph_speedmeter->load_image_bg(METER2_BG);
    mph_speedmeter->load_image_needle(METER_NEEDLE);
    mph_speedmeter->set_rot_start(ROTE_LOCATE2);
    mph_speedmeter->set_rot_dir(DIR_LEFT);

    mph_speedmeter->start_paint(50);
    mph_speedmeter->setGeometry(speedmeter->width + 50, 0,
        mph_speedmeter->width, mph_speedmeter->height);

    mph_speedmeter->show();

    this->setGeometry(0, 0, mph_speedmeter->width + speedmeter->width + 100, mph_speedmeter->height);
}

MainForm::~MainForm()
{
    delete speedmeter;
    delete ui;

}
