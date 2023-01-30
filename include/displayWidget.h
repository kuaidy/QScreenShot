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
    QRect topLeftRect;
    QRect topCenterRect;
    QRect topRightRect;
    QRect centerLeftRect;
    QRect centerRightRect;
    QRect bottomLeftRect;
    QRect bottomCenterRect;
    QRect bottomRightRect;
};

#endif // DISPLAYWIDGET_H
