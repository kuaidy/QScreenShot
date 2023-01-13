#include "../include/displayWidget.h"

displayWidget::displayWidget()
{

}
void displayWidget::paintEvent(QPaintEvent *paintEvent){
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    int x=imageLabel->x();
    int y=imageLabel->y();
    int width=imageLabel->width();
    int height=imageLabel->height();
    //半径
    int r=8;
    //左上
    painter.drawEllipse(x-r,y-r,r,r);
    //中上
    painter.drawEllipse(x+width/2-r,y-r,r,r);
    //右上
    painter.drawEllipse(x+width,y-r,r,r);
    //左中
    painter.drawEllipse(x-r,y+height/2-r,r,r);
    //右中
    painter.drawEllipse(x+width,y+height/2-r,r,r);
    //左下
    painter.drawEllipse(x-r,y+height,r,r);
    //中下
    painter.drawEllipse(x+width/2-r,y+height,r,r);
    //右下
    painter.drawEllipse(x+width,y+height,r,r);
}

void displayWidget::mouseMoveEvent(QMouseEvent *mouseEvent){

}
