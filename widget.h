#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QPixmap speed_meter_img;
    QImage speed_need_img;
    QBrush bg_img;

    int rot_cnt;
    int rot_dir;

protected:
    void paintEvent(QPaintEvent *);

private slots:
        void timout_update();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
