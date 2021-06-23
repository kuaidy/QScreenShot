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



private:
    QList<QRect> _listRect;
    //二位数组存放坐标
    QVector<QVector<int>> _listseat;
};

class editwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr);
    ~editwindow();
    //绘制类型
    static int painttype;

private:
    Ui::editwindow *ui;

    QDockWidget *DockImage;
    Plabel *imagelabel;

public:
    void editview(QPixmap *qpix);

private slots:
    void on_paintrec_triggered();
    void on_paintarrow_triggered();
    void on_paintrec_triggered(bool checked);
    void on_paintarrow_triggered(bool checked);
    void on_filesaveother_triggered();
};

#endif // EDITWINDOW_H



