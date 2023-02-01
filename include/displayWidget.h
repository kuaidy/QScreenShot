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
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
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
    bool isMouseLeftBtnDown=false;
    bool isTopLeft=false;
    bool isTopCenter=false;
    int r=8;
    int startX=0;
    int startY=0;
    int startWidth=0;
    int startHeight=0;
    int endX=0;
    int endY=0;
};

#endif // DISPLAYWIDGET_H
