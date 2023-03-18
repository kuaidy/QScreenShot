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
    //左上
    topLeftRect=QRect(x-r,y-r,r,r);
    painter.drawEllipse(topLeftRect);
    //中上
    topCenterRect=QRect(x+width/2,y-r,r,r);
    painter.drawEllipse(topCenterRect);
    //右上
    topRightRect=QRect(x+width,y,r,r);
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

    if(isMouseLeftBtnDown){
        //绘制调整图片的预览虚线
        brush.setColor(Qt::transparent);
//        brush.setStyle(Qt::Dense1Pattern);
        painter.setBrush(brush);
        if(isTopLeft){
            painter.drawRect(endX,endY,x+width-endX,y+height-endY);
        }
        else if(isTopCenter){
            painter.drawRect(x,endY,width,y+height-endY);
        }
        else if(isTopRight){
            painter.drawRect(x,endY,endX-x,y+height-endY);
        }
        else if(isCenterLeft){
            painter.drawRect(endX,y,x+width-endX,height);
        }
        else if(isCenterRight){
            painter.drawRect(x,y,endX-x,height);
        }
        else if(isBottomLeft){
            painter.drawRect(endX,y,x+width-endX,endY-y);
        }
        else if(isBottomCenter){
            painter.drawRect(x,y,width,endY-y);
        }
        else if(isBottomRight){
            painter.drawRect(x,y,endX-x,endY-y);
        }
    }

}

void displayWidget::mousePressEvent(QMouseEvent *mouseEvent){
    startX=mouseEvent->position().x();
    startY=mouseEvent->position().y();
    isMouseLeftBtnDown=true;
}

void displayWidget::mouseMoveEvent(QMouseEvent *mouseEvent){
    QPoint cursorPoint=mouseEvent->pos();
    if(topLeftRect.contains(cursorPoint)){
        setCursor(Qt::SizeFDiagCursor);
        isTopLeft=true;
    }else if(topCenterRect.contains(cursorPoint)){
        setCursor(Qt::SizeVerCursor);
        isTopCenter=true;
    }else if(topRightRect.contains(cursorPoint)){
        setCursor(Qt::SizeBDiagCursor);
        isTopRight=true;
    }else if(centerLeftRect.contains(cursorPoint)){
        setCursor(Qt::SizeHorCursor);
        isCenterLeft=true;
    }else if(centerRightRect.contains(cursorPoint)){
        setCursor(Qt::SizeHorCursor);
        isCenterRight=true;
    }else if(bottomLeftRect.contains(cursorPoint)){
        setCursor(Qt::SizeBDiagCursor);
        isBottomLeft=true;
    }else if(bottomCenterRect.contains(cursorPoint)){
        setCursor(Qt::SizeVerCursor);
        isBottomCenter=true;
    }else if(bottomRightRect.contains(cursorPoint)){
        setCursor(Qt::SizeFDiagCursor);
        isBottomRight=true;
    }else{
        setCursor(Qt::ArrowCursor);
    }
    if(isMouseLeftBtnDown){
        endX=mouseEvent->position().x();
        endY=mouseEvent->position().y();
    }
    update();
}

void displayWidget::mouseReleaseEvent(QMouseEvent *mouseEvent){

    int x=imageLabel->x();
    int y=imageLabel->y();
    int width=imageLabel->width();
    int height=imageLabel->height();
    if(isTopLeft){
        imageLabel->resize(x+width-endX,y+height-endY);
    }else if(isTopCenter){
        imageLabel->resize(width,y+height-endY);
    }
    else if(isTopRight){
        imageLabel->resize(endX-x,y+height-endY);
    }
    else if(isCenterLeft){
        imageLabel->resize(x+width-endX,height);
    }
    else if(isCenterRight){
        imageLabel->resize(endX-x,height);
    }
    else if(isBottomLeft){
        imageLabel->resize(x+width-endX,endY-y);
    }
    else if(isBottomCenter){
        imageLabel->resize(width,endY-y);
    }
    else if(isBottomRight){
        imageLabel->resize(endX-x,endY-y);
    }

    isMouseLeftBtnDown=false;
    isTopLeft=isTopCenter=isTopRight=isCenterLeft=isCenterRight=isBottomLeft=isBottomCenter=isBottomRight=false;
    imageLabel->isPaintTopLeft=false;
    update();
}
