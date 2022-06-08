#ifndef COLORVALUE_H
#define COLORVALUE_H

#include <QWidget>
#include <QMouseEvent>

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
public:
    void mouseMoveEvent(QMouseEvent *event);
private:
    Ui::ColorValue *ui;
};

#endif // COLORVALUE_H
