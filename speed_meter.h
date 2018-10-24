#ifndef SPEED_METER_H
#define SPEED_METER_H

#include <QWidget>
#include <QImage>

namespace Ui {
class SpeedMeter;
}

class SpeedMeter : public QWidget
{
    Q_OBJECT

public:
    explicit SpeedMeter(QWidget *parent = 0);
    ~SpeedMeter();
    QPixmap speed_meter_img;
    QImage speed_need_img;
    QBrush bg_img;

    int rot_cnt;
    int rot_dir;
    int width;
    int height;

protected:
    void paintEvent(QPaintEvent *);

private slots:
        void timout_update();

private:
    Ui::SpeedMeter *ui;
};

#endif // WIDGET_H
