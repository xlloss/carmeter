#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
    class SpeedMeter *speedmeter;
    class SpeedMeter *mph_speedmeter;
    class turn_signal *r_trunsignal;
    class turn_signal *l_trunsignal;
    QPixmap mianform_bg_img;

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
