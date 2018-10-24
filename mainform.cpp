#include "mainform.h"
#include "ui_mainform.h"
#include "speed_meter.h"
#include "turn_signal.h"

#define  MAIN_FORM_BG ":/meter/png_rec/QML_mask.jpg"
#define  METER1_BG ":/meter/png_rec/SpeedMeterBg.png"
#define  METER2_BG ":/meter/png_rec/MphSpeedMeterBg.png"
#define  METER_NEEDLE ":/meter/png_rec/NeedleBg.png"
#define  METER_L_SIGNAL_ON ":/meter/png_rec/left_turnsignal_on.png"
#define  METER_L_SIGNAL_OFF ":/meter/png_rec/left_turnsignal_off.png"
#define  METER_R_SIGNAL_ON ":/meter/png_rec/right_turnsignal_on.png"
#define  METER_R_SIGNAL_OFF ":/meter/png_rec/right_turnsignal_off.png"
#define  METER_SIGNAL_OFFSET 385

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

    l_trunsignal = new turn_signal(this);
    l_trunsignal->load_signal_on_img(METER_L_SIGNAL_ON);
    l_trunsignal->load_signal_off_img(METER_L_SIGNAL_OFF);
    l_trunsignal->setGeometry(METER_SIGNAL_OFFSET, 0, 48, 48);

    r_trunsignal = new turn_signal(this);
    r_trunsignal->load_signal_on_img(METER_R_SIGNAL_ON);
    r_trunsignal->load_signal_off_img(METER_R_SIGNAL_OFF);
    r_trunsignal->setGeometry(l_trunsignal->x() + 200, 0, 48, 48);


    this->setGeometry(0, 0, mph_speedmeter->width + speedmeter->width + 100, mph_speedmeter->height);
}

MainForm::~MainForm()
{
    delete speedmeter;
    delete mph_speedmeter;
    delete r_trunsignal;
    delete l_trunsignal;
    delete ui;

}
