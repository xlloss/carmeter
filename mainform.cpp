#include "mainform.h"
#include "ui_mainform.h"
#include "speed_meter.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    speedmeter = new SpeedMeter(this);
    speedmeter->show();
    this->setGeometry(0, 0, speedmeter->width, speedmeter->height);
}

MainForm::~MainForm()
{
    delete speedmeter;
    delete ui;

}
