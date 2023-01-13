#ifndef SCREENVIEW_H
#define SCREENVIEW_H

#include <QWidget>
#include <QPainter>
#include <QScreen>
#include <QWindow>
#include <QPixmap>
#include <QMouseEvent>
#include <QRubberBand>
#include <QDateTime>
#include <QLabel>

#include "editwindow.h"
#include "mainwindow.h"
#include "shotcommon.h"
#include "colorvalue.h"

//添加
class QRubberBand;

namespace Ui {
class screenview;
}

class screenview : public QWidget
{
    Q_OBJECT

public:
    screenview(QWidget *parent = nullptr,QList<QRect> *ListRect=nullptr,int screentype=0);
    ~screenview();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
protected slots:
    void mouseReleaseEvent(QMouseEvent *event);
    void receiveData(QString str);   //接收传递过来的数据的槽

private:
    Ui::screenview *ui;
    QPainter painter;
    QPixmap originalPixmap;
    QPixmap sourcePixmap;

    QScreen *screen;
    QRubberBand *rubberBand;
    QPoint startpoint;
    QPoint endpoint;

    //记录鼠标位置
    int sx,sy,ex,ey;
    //记录矩形的大小
    int rw,rh;
    //截图类型
    int shottype;
    //鼠标按下
    bool MousePressed=false;
    //固定截图的坐标
    int fixedx,fixedy;
    //固定大小的矩形
    QRect fixedRect;

    //保存所有的矩形
    QList<QRect> *ListRect;

    //当前选中的窗口
    QRect CurrentWindow;

signals:
    void senddata(QPixmap sourcePixmap);
    void showWin();

public:
    void getColorValue();
    ColorValue *_colorValue=NULL;
};

#endif // SCREENVIEW_H
