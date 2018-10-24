#ifndef TURN_SIGNAL_H
#define TURN_SIGNAL_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
namespace Ui {
class turn_signal;
}

#define SIGNAL_DIR_LEFT 0
#define SIGNAL_DIR_RIGHT 1

class turn_signal : public QWidget
{
    Q_OBJECT

public:
    explicit turn_signal(QWidget *parent = 0);
    ~turn_signal();
    void load_signal_on_img(QString siganl_img_on_name);
    void load_signal_off_img(QString siganl_img_off_name);

    QPixmap signal_on_img;
    QPixmap signal_off_img;
    QPixmap signal_img;
    QTimer *timer;
    unsigned char flicker;

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void timout_update();

private:
    Ui::turn_signal *ui;
};

#endif // TURN_SIGNAL_H
