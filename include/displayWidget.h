#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include <QWidget>
#include <QPainter>

#include "plabel.h"

class displayWidget:public QWidget
{
public:
    displayWidget();

public:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public:
    Plabel *imageLabel;
};

#endif // DISPLAYWIDGET_H
