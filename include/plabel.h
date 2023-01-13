#ifndef PLABEL_H
#define PLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainterPath>

#include "Common/GlobalVariable.h"
#include "AntLine.h"

//自定义label类，用来显示图像和绘制标记
class Plabel:public QLabel
{
public:
    explicit Plabel(QWidget *parent = nullptr);
    ~Plabel();
public:
    //起始位置，终点位置
    int sx,sy,ex,ey;
    int cutsx,cutsy,cutex,cutey;
    bool isOption=false;
    //对于桌面的坐标
    int glsx,glsy,glex,gley;
    QRect m_leftTopRect;
    AntLine* antLine=nullptr;

    //重写绘制方法
    void paintEvent(QPaintEvent *event);
    //重写鼠标按下方法
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //绘制箭头
    void paintArrow(int sx,int sy,int ex,int ey);
    //计算鼠标在截图的哪个区域
    void CalCursorPos(QPoint pt);
    //设置鼠标样式
    void SetCursorPattern(int CalPos);

private:
    //矩形
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

    //截图的位置，用来调整截图大小
    enum ImagePosition{
        TOPLEFT,
        TOP,
        TOPRIGHT,
        LEFT,
        CENTER,
        RIGHT,
        BUTTOMLEFT,
        BUTTOM,
        BUTTOMRIGHT
    };
    //扩展边框
    int ExtendedWidth=10;



signals:
    void mouseDoubleClickEvent(QMouseEvent *event);

};

#endif
