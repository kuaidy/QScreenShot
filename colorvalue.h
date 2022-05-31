#ifndef COLORVALUE_H
#define COLORVALUE_H

#include <QWidget>

namespace Ui {
class ColorValue;
}

class ColorValue : public QWidget
{
    Q_OBJECT

public:
    explicit ColorValue(QWidget *parent = nullptr);
    ~ColorValue();
    void SetColorValue(int r,int g,int b);
private:
    Ui::ColorValue *ui;
};

#endif // COLORVALUE_H
