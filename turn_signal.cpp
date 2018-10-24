#include "turn_signal.h"
#include "ui_turn_signal.h"

turn_signal::turn_signal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::turn_signal)
{
    ui->setupUi(this);
}

turn_signal::~turn_signal()
{
    delete ui;
}
