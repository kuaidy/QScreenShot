#ifndef PLABEL_H
#define PLABEL_H

#include <QLabel>
#include <QMouseEvent>

#include "editwindow.h"
#include "Common/GlobalVariable.h"

//自定义label类，用来显示图像和绘制标记
class Plabel:public QLabel
{
public:
    explicit Plabel(QWidget *parent = nullptr);
    ~Plabel();
public:
    //重写绘制方法
    void paintEvent(QPaintEvent *event);
    //重写鼠标按下方法
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //绘制箭头
    void paintArrow(int sx,int sy,int ex,int ey);

    //起始位置，终点位置
    int sx,sy,ex,ey;
    int cutsx,cutsy,cutex,cutey;
    //对于桌面的坐标
    int glsx,glsy,glex,gley;
    QRect m_leftTopRect;

private:
    QList<QRect> _listRect;
    //绘制箭头存放坐标点
    QVector<QVector<int>> _listSeat;
    //自由绘制坐标点
    QVector<QVector<int>> _listPoint;
    QVector<QVector<QPoint>> _listLine;
    QPoint _startPoint;
    QPoint _endPoint;

    QPoint _cutStartPoint;
    QPoint _cutEndPoint;

signals:
    void mouseDoubleClickEvent(QMouseEvent *event);

};

#endif
