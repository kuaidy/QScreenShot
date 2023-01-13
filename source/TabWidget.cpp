#include "../include/TabWidget.h"


tabWidget::tabWidget(QWidget* parent){
    this->setMouseTracking(true);
}
tabWidget::~tabWidget(){

}

void tabWidget::paintEvent(QPaintEvent *paintEvent){
    QPainter painter(this);
    QLabel* label=this->findChild<QLabel*>();

    painter.setPen(QPen(Qt::red,2));
    painter.drawRect(label->x(),label->y(),10,10);


}

void tabWidget::mouseMoveEvent(QMouseEvent *mouseEvent){
    QPoint point= mouseEvent->pos();
    if(TopRect->contains(point)){
        setCursor(Qt::SizeVerCursor);
    }else{
        setCursor(Qt::ArrowCursor);
    }
    update();
}
