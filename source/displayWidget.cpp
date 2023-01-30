#include "../include/displayWidget.h"

displayWidget::displayWidget()
{
    this->setMouseTracking(true);
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
    topLeftRect=QRect(x-r,y-r,r,r);
    painter.drawEllipse(topLeftRect);
    //中上
    topCenterRect=QRect(x+width/2-r,y-r,r,r);
    painter.drawEllipse(topCenterRect);
    //右上
    topRightRect=QRect(x+width,y-r,r,r);
    painter.drawEllipse(topRightRect);
    //左中
    centerLeftRect=QRect(x-r,y+height/2-r,r,r);
    painter.drawEllipse(centerLeftRect);
    //右中
    centerRightRect=QRect(x+width,y+height/2-r,r,r);
    painter.drawEllipse(centerRightRect);
    //左下
    bottomLeftRect=QRect(x-r,y+height,r,r);
    painter.drawEllipse(bottomLeftRect);
    //中下
    bottomCenterRect=QRect(x+width/2-r,y+height,r,r);
    painter.drawEllipse(bottomCenterRect);
    //右下
    bottomRightRect=QRect(x+width,y+height,r,r);
    painter.drawEllipse(bottomRightRect);
}

void displayWidget::mouseMoveEvent(QMouseEvent *mouseEvent){
    QPoint cursorPoint=mouseEvent->pos();
    if(topLeftRect.contains(cursorPoint)){
        setCursor(Qt::SizeFDiagCursor);
    }else if(topCenterRect.contains(cursorPoint)){
        setCursor(Qt::SizeVerCursor);
    }else if(topRightRect.contains(cursorPoint)){
        setCursor(Qt::SizeBDiagCursor);
    }else if(centerLeftRect.contains(cursorPoint)){
        setCursor(Qt::SizeHorCursor);
    }else if(centerRightRect.contains(cursorPoint)){
        setCursor(Qt::SizeHorCursor);
    }else if(bottomLeftRect.contains(cursorPoint)){
        setCursor(Qt::SizeBDiagCursor);
    }else if(bottomCenterRect.contains(cursorPoint)){
        setCursor(Qt::SizeVerCursor);
    }else if(bottomRightRect.contains(cursorPoint)){
        setCursor(Qt::SizeFDiagCursor);
    }else{
        setCursor(Qt::ArrowCursor);
    }
}
