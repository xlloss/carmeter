#ifndef TURN_SIGNAL_H
#define TURN_SIGNAL_H

#include <QWidget>

namespace Ui {
class turn_signal;
}

class turn_signal : public QWidget
{
    Q_OBJECT

public:
    explicit turn_signal(QWidget *parent = 0);
    ~turn_signal();

private:
    Ui::turn_signal *ui;
};

#endif // TURN_SIGNAL_H
