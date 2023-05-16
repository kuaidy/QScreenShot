#include "../include/imageLabel.h"

QImage applyEffectToImage(QImage src, QGraphicsEffect* effect, int extent);

//图片模糊处理
QImage applyEffectToImage(QImage src, QGraphicsEffect* effect, int extent = 0)
{
    return QImage();
//	if (src.isNull()) return QImage();
//	if (!effect) return src;
//	QGraphicsScene scene;
//	QGraphicsPixmapItem item;
//	item.setPixmap(QPixmap::fromImage(src));
//	item.setGraphicsEffect(effect);
//	item.setOpacity(1);
//	scene.addItem(&item);
//	QImage res(src.size() + QSize(extent * 2, extent * 2), QImage::Format_ARGB32);
//	res.fill(Qt::transparent);
//	QPainter ptr(&res);
//	scene.render(&ptr, QRectF(), QRectF(-extent, -extent, src.width() + extent * 2, src.height() + extent * 2));
//	return res;
}


ImageLabel::ImageLabel(QWidget* parent)
{
	//设置默认追踪鼠标
	this->setMouseTracking(true);
}
ImageLabel::~ImageLabel() {

}

//重写鼠标按下方法
void ImageLabel::mousePressEvent(QMouseEvent* e) {
    sx = e->position().x();
    sy = e->position().y();
    _startPoint = e->pos();
    _endPoint = e->pos();
    isOption = true;
}
//重写鼠标双击事件
void ImageLabel::mouseDoubleClickEvent(QMouseEvent* e) {
	QPixmap pixmap = this->pixmap();
	QPixmap tmpPixmap = pixmap.copy(QRect(cutsx, cutsy, cutex - cutsx, cutey - cutsy));

    this->resize(tmpPixmap.width()+100, tmpPixmap.height());
    this->setPixmap(tmpPixmap);
	cutsx = cutsy = cutex = cutey = 0;
}
//重写鼠标移动事件
void ImageLabel::mouseMoveEvent(QMouseEvent* e) {
    if (isOption) {
        ex = e->position().x();
        ey = e->position().y();
		_endPoint = e->pos();
		switch (OptionFlag) {
			case OptionTypeEnum::PaintFreedom: {
				QVector<QPoint> tmpPoint;
				tmpPoint.append(_startPoint);
				tmpPoint.append(_endPoint);
				_listLine.append(tmpPoint);
				break;
			}
			default: {

			}
		}
	}
	//改变鼠标的样式
	QPoint cursorPoint = this->mapFromGlobal(QCursor::pos());
	if (this->geometry().contains(cursorPoint))
	{
		QPoint topLeftPoint(cutsx, cutsy);
		QPoint bottomRightPoint(cutex, cutey);
		QRect cutRect(topLeftPoint, bottomRightPoint);
		if (cutRect.contains(cursorPoint)) {
			setCursor(Qt::SizeAllCursor);
		}
		else {
			setCursor(Qt::ArrowCursor);
		}
	}
    //
    QPoint cursorPos(ex, ey);

    imageResizeX=e->position().x();
    imageResizeY=e->position().y();
	update();
}
//重写鼠标弹起事件
void ImageLabel::mouseReleaseEvent(QMouseEvent* e) {
	isOption = false;
	switch (OptionFlag) {
        case OptionTypeEnum::PaintRect: {
			_listRect.append(QRect(sx, sy, ex - sx, ey - sy));
			break;
		}
		case OptionTypeEnum::PaintArrow: {
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
			if (antLine == nullptr) {
				antLine = new AntLine(this);
			}
			antLine->resize(abs(ex - sx), abs(ey - sy));
			antLine->move(sx, sy);
			antLine->show();
		}
	}
    sx=sy=ex=ey=-1;
}
//重写lable的绘制方法
void ImageLabel::paintEvent(QPaintEvent* event) {
    //先调用父类的paintEvent为了显示'背景'!!!
    QLabel::paintEvent(event);
    QPainter painter(this);
	float l = 10;
	float a = 0.5;
    paintDragBtns();
	//绘制矩形
	for (int i = 0; i != _listRect.size(); i++) {
        painter.setPen(QPen(Qt::red, 2));
		painter.drawRect(QRect(_listRect.at(i).x(), _listRect.at(i).y(), _listRect.at(i).width(), _listRect.at(i).height()));
	}
	//绘制箭头
	for (int i = 0; i != _listSeat.size(); i++)
	{
        painter.setPen(QPen(Qt::red, 2));
		float x3 = _listSeat[i][2] - l * cos(atan2((_listSeat[i][3] - _listSeat[i][1]), (_listSeat[i][2] - _listSeat[i][0])) - a);//计算箭头的终点（x3,y3）
		float y3 = _listSeat[i][3] - l * sin(atan2((_listSeat[i][3] - _listSeat[i][1]), (_listSeat[i][2] - _listSeat[i][0])) - a);
		float x4 = _listSeat[i][2] - l * sin(atan2((_listSeat[i][2] - _listSeat[i][0]), (_listSeat[i][3] - _listSeat[i][1])) - a);//计算箭头的终点（x4,y4）
		float y4 = _listSeat[i][3] - l * cos(atan2((_listSeat[i][2] - _listSeat[i][0]), (_listSeat[i][3] - _listSeat[i][1])) - a);
		painter.drawLine(_listSeat[i][2], _listSeat[i][3], x3, y3);
		painter.drawLine(_listSeat[i][2], _listSeat[i][3], x4, y4);
		painter.drawLine(_listSeat[i][0], _listSeat[i][1], _listSeat[i][2], _listSeat[i][3]);
	}
	//自由绘制
	for (int i = 0; i != _listLine.size(); i++) {
        painter.setPen(QPen(Qt::red, 2));
		painter.drawLine(_listLine[i][0], _listLine[i][1]);
	}

    if(isPaintTopLeft){
        painter.setPen(QPen(Qt::red, 1));
        painter.drawRect(imageResizeX,imageResizeY,this->x()+this->width()-imageResizeX,this->y()+this->height()-imageResizeY);
    }
}
//绘制拖拽框
void ImageLabel::paintDragBtns(){
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    //为啥无法直接获取到图片的坐标呢
    int width=this->pixmap().rect().width()/Scale;
    int height=this->pixmap().rect().height()/Scale;
    QPoint center=this->rect().center();
    int x=center.x()-width/2;
    int y=center.y()-height/2;

    //左上
    topLeftRect=QRect(x-r,y-r,r,r);
    painter.drawEllipse(topLeftRect);
    //中上
    topCenterRect=QRect(x+width/2,y-r,r,r);
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
