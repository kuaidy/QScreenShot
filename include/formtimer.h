#ifndef FORMTIMER_H
#define FORMTIMER_H

#include <QWidget>

namespace Ui {
class FormTimer;
}

class FormTimer : public QWidget
{
    Q_OBJECT

public:
    explicit FormTimer(QWidget *parent = nullptr);
    ~FormTimer();

private:
    Ui::FormTimer *ui;
};

#endif // FORMTIMER_H
