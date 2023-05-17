#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainterPath>
#include <QRect>

#include "common/globalvariable.h"
#include "antline.h"

//自定义label类，用来显示图像和绘制标记
class ImageLabel:public QLabel
{
public:
    explicit ImageLabel(QWidget *parent = nullptr);
    ~ImageLabel();
public:
    //起始位置，终点位置
    int sx,sy,ex,ey;
    int cutsx,cutsy,cutex,cutey;
    bool isOption=false;
    int imageResizeX,imageResizeY;
    bool isPaintTopLeft=false;
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
    void paintDragBtns();
    void resizePixmap();
    void changeCursorStyle(QMouseEvent* e);

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
    bool isTopRight=false;
    bool isCenterLeft=false;
    bool isCenterRight=false;
    bool isBottomLeft=false;
    bool isBottomRight=false;
    bool isBottomCenter=false;
    int r=8;
    int startX=0;
    int startY=0;
    int startWidth=0;
    int startHeight=0;
    int endX=0;
    int endY=0;
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

signals:
    void mouseDoubleClickEvent(QMouseEvent *event);

};

#endif
