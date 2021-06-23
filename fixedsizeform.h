#ifndef FIXEDSIZEFORM_H
#define FIXEDSIZEFORM_H

#include <QWidget>

namespace Ui {
class fixedsizeform;
}

class fixedsizeform : public QWidget
{
    Q_OBJECT

public:
    explicit fixedsizeform(QWidget *parent = nullptr);
    ~fixedsizeform();

private:
    Ui::fixedsizeform *ui;
};

#endif // FIXEDSIZEFORM_H
