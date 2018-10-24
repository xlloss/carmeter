#ifndef SPEED_METER_H
#define SPEED_METER_H

#include <QWidget>
#include <QImage>

#define ROTE_LOCATE0 0
#define ROTE_LOCATE1 1
#define ROTE_LOCATE2 2
#define ROTE_LOCATE3 3
#define ROTE_LOCATE4 4

#define DIR_RIGHT 0
#define DIR_LEFT 1


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
    QTimer *timer;

    int rot_cnt;
    int rot_dir;
    int width;
    int height;
    void load_image_bg(QString bg_name);
    void load_image_needle(QString needle_name);
    void start_paint();
    void start_paint(int speed);
    void set_rot_start(int statr_locate);
    void set_rot_dir(int rot_dir_set);

protected:
    void paintEvent(QPaintEvent *);

private slots:
        void timout_update();

private:
    Ui::SpeedMeter *ui;
};

#endif // WIDGET_H
