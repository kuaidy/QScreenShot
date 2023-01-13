#ifndef TABWIDGET_H
#define TABWIDGET_H

#endif // TABWIDGET_H
#include <QLabel>
#include <QPainter>
#include <QWidget>
#include <QRect>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QScrollArea>
#include <QTabWidget>

class tabWidget:public QTabWidget{
public :
    explicit tabWidget(QWidget *parent = nullptr);
    ~tabWidget();
    void paintEvent(QPaintEvent *paintEvent);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QRect *TopRect;
};
