#include "../include/plabel.h"
#include <include/AntLine.h>

QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent);

//图片模糊处理
QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent = 0)
{
    if(src.isNull()) return QImage();   
    if(!effect) return src;          
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(src));
    item.setGraphicsEffect(effect);
    item.setOpacity(1);
    scene.addItem(&item);
    QImage res(src.size()+QSize(extent*2, extent*2), QImage::Format_ARGB32);
    res.fill(Qt::transparent);
    QPainter ptr(&res);
    scene.render(&ptr, QRectF(), QRectF( -extent, -extent, src.width()+extent*2, src.height()+extent*2 ) );
    return res;
}


Plabel::Plabel(QWidget *parent)
{
    //设置默认追踪鼠标
    this->setMouseTracking(true);

    
}
Plabel::~Plabel(){

}

//重写鼠标按下方法
void Plabel::mousePressEvent(QMouseEvent *e){
    sx=e->x();
    sy=e->y();
    glsx=e->globalX();
    glsy=e->globalY();
    _startPoint=e->pos();
    _endPoint=e->pos();
    isOption=true;

}
//重写鼠标双击事件
void Plabel::mouseDoubleClickEvent(QMouseEvent *e){
    QPixmap pixmap= this->pixmap();
    QPixmap tmpPixmap=pixmap.copy(QRect(cutsx,cutsy,cutex-cutsx,cutey-cutsy));
    this->setPixmap(tmpPixmap);
    this->resize(tmpPixmap.width(),tmpPixmap.height());
    cutsx=cutsy=cutex=cutey=0;
}

void Plabel::mouseMoveEvent(QMouseEvent *e){
    if(isOption){
        ex=e->x();
        ey=e->y();
        glex=e->globalX();
        gley=e->globalY();
        _endPoint=e->pos();

        switch (OptionFlag) {
            case OptionTypeEnum::PaintFreedom:{
                QVector<QPoint> tmpPoint;
                tmpPoint.append(_startPoint);
                tmpPoint.append(_endPoint);
                _listLine.append(tmpPoint);
                break;
            }
            default:{

            }
        }
    }

    //改变鼠标的样式
    QPoint cursorPoint=this->mapFromGlobal(QCursor::pos());
    if (this->geometry().contains(cursorPoint))
    {
        QPoint topLeftPoint(cutsx,cutsy);
        QPoint bottomRightPoint(cutex,cutey);
        QRect cutRect(topLeftPoint,bottomRightPoint);
        if(cutRect.contains(cursorPoint)){
           setCursor(Qt::SizeAllCursor);
        }else{
           setCursor(Qt::ArrowCursor);
        }
    }
    update();
}

void Plabel::mouseReleaseEvent(QMouseEvent *e){
    isOption=false;
    switch (OptionFlag) {
        case OptionTypeEnum::PaintRec :{
            _listRect.append(QRect(sx,sy,ex-sx,ey-sy));
            break;
        }
        case OptionTypeEnum::PaintArrow:{
            QVector<int> tmpseat;
            tmpseat.append(sx);
            tmpseat.append(sy);
            tmpseat.append(ex);
            tmpseat.append(ey);
            _listSeat.append(tmpseat);
            break;
        }
        case OptionTypeEnum::ActionCrop: {
            /// <summary>
            /// 绘制蚂蚁线
            /// </summary>
            /// <param name="event"></param>
            AntLine* antLine = new AntLine(this);
            antLine->resize(ex-sx, ey-sy);
            antLine->move(sx,sy);
            antLine->show();
        }
    }
}

//重写lable的绘制方法
void Plabel::paintEvent(QPaintEvent *event){
    QLabel::paintEvent(event);//先调用父类的paintEvent为了显示'背景'!!!
    QPainter painter(this);

    float l=10;
    float a=0.5;

    //绘制小方块
    switch (OptionFlag) {
        case OptionTypeEnum::PaintRec:{
            painter.setPen(QPen(Qt::red,2));
            painter.drawRect(QRect(sx,sy,ex-sx,ey-sy));
            break;
        }
        case OptionTypeEnum::PaintArrow:{
            painter.setPen(QPen(Qt::red,2));
            float x3 = ex - l * cos(atan2((ey - sy) , (ex - sx)) - a);//计算箭头的终点（x3,y3）
            float y3 = ey - l * sin(atan2((ey - sy) , (ex - sx)) - a);
            float x4 = ex - l * sin(atan2((ex - sx) , (ey - sy)) - a);//计算箭头的终点（x4,y4）
            float y4 = ey - l * cos(atan2((ex - sx) , (ey - sy)) - a);
            painter.drawLine(ex,ey,x3,y3);
            painter.drawLine(ex,ey,x4,y4);
            painter.drawLine(sx,sy,ex,ey);
            break;
        }
        case OptionTypeEnum::Vague:{
            QImage copyImage=this->pixmap().copy(sx,sy,ex-sx,ey-sy).toImage();
            QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
            QGraphicsOpacityEffect *opac=new QGraphicsOpacityEffect;
            blur->setBlurRadius(5);
            opac->setOpacity(0.5);
            QImage result = applyEffectToImage(copyImage, blur,0);
            painter.drawImage(sx,sy,result);
            break;
        }
        case OptionTypeEnum::PaintFreedom:{
            painter.setPen(QPen(Qt::red,2));
            painter.drawLine(_startPoint,_endPoint);
            _startPoint=_endPoint;
            break;
        }
        case OptionTypeEnum::ActionCrop:{
                cutsx=sx;
                cutsy=sy;
                cutex=ex;
                cutey=ey;
                //裁剪
                painter.setPen(QPen(Qt::black,1));
                painter.drawRect(QRect(sx,sy,ex-sx,ey-sy));
                //绘制圆点
                QPainterPath path;
                path.setFillRule(Qt::WindingFill);
                painter.setPen(QPen(Qt::black,1));
                painter.setPen(Qt::SolidLine);
                painter.drawPath(path);

                
                break;
        }
    }

    //绘制矩形
    for(int i = 0; i != _listRect.size(); i++){
        painter.drawRect(QRect(_listRect.at(i).x(),_listRect.at(i).y(),_listRect.at(i).width(),_listRect.at(i).height()));
    }

    //绘制箭头
    for(int i = 0; i != _listSeat.size(); i++)
    {
        float x3 = _listSeat[i][2] - l * cos(atan2((_listSeat[i][3] - _listSeat[i][1]) , (_listSeat[i][2] - _listSeat[i][0])) - a);//计算箭头的终点（x3,y3）
        float y3 = _listSeat[i][3] - l * sin(atan2((_listSeat[i][3] - _listSeat[i][1]) , (_listSeat[i][2] - _listSeat[i][0])) - a);
        float x4 = _listSeat[i][2] - l * sin(atan2((_listSeat[i][2] - _listSeat[i][0]) , (_listSeat[i][3] - _listSeat[i][1])) - a);//计算箭头的终点（x4,y4）
        float y4 = _listSeat[i][3] - l * cos(atan2((_listSeat[i][2] - _listSeat[i][0]) , (_listSeat[i][3] - _listSeat[i][1])) - a);
        painter.drawLine(_listSeat[i][2],_listSeat[i][3],x3,y3);
        painter.drawLine(_listSeat[i][2],_listSeat[i][3],x4,y4);
        painter.drawLine(_listSeat[i][0],_listSeat[i][1],_listSeat[i][2],_listSeat[i][3]);
    }
    //自由绘制
    for(int i=0;i!=_listLine.size();i++){
        painter.drawLine(_listLine[i][0],_listLine[i][1]);
    }

}
