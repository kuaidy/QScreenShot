#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDockWidget>
#include <QGridLayout>
#include <QImage>
#include <QScrollArea>
#include <Qpainter>
#include <QMouseEvent>
#include <QList>
#include <cmath>
#include <QFileDialog>
#include <QDateTime>
#include <QPixmap>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QRect>
#include <QCursor>

#include "shotcommon.h"

namespace Ui {
class editwindow;
}

//自定义label类，用来显示图像和绘制标记
class Plabel:public QLabel
{
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
    //对于桌面的坐标
    int glsx,glsy,glex,gley;
    static QPixmap *PlabelPixmap;
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

};

class editwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr);
    ~editwindow();
    //绘制类型
    static int painttype;
//    static QPixmap *PlabelPixmap;
    //缩放比例
    int Scale=100;

private:
    Ui::editwindow *ui;

    QDockWidget *DockImage;
    Plabel *imagelabel;

    //状态栏大小
    QLabel *sizeStatus;
    //状态栏缩放比例
    QLabel *scaleStatus;

public:
    void editview(QPixmap *qpix);

private slots:
    void on_paintrec_triggered();
    void on_paintarrow_triggered();
    void on_paintrec_triggered(bool checked);
    void on_paintarrow_triggered(bool checked);
    void on_filesaveother_triggered();
    void on_vague_triggered(bool checked);
    void on_actionpaintfreedom_triggered(bool checked);
    void on_enlarge_triggered();
    void on_narrow_triggered();
};

#endif // EDITWINDOW_H



