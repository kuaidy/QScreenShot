#include "../include/imageLabel.h"

ImageLabel::ImageLabel(QWidget* parent)
{
	//设置默认追踪鼠标
	this->setMouseTracking(true);
}
ImageLabel:: ~ImageLabel(){

}

//重写鼠标按下方法
void ImageLabel::mousePressEvent(QMouseEvent* e) {
    sx = e->position().x();
    sy = e->position().y();
    _startPoint = e->pos();
    _endPoint = e->pos();
    isOption = true;
    isMouseLeftBtnDown=true;

    switch (OptionFlag) {
        case OptionTypeEnum::PaintFreedom: {
            _freedomPoints.clear();
            _freedomPoints.push_back(_startPoint);
            break;
        }
        case OptionTypeEnum::ActionCrop:{
            if(!_isCutting){
                _cutsx=e->pos().x();
                _cutsy=e->pos().y();
            }
            break;
        }
        default: {

        }
    }

}
//重写鼠标双击事件
void ImageLabel::mouseDoubleClickEvent(QMouseEvent* e) {

}
//重写鼠标移动事件
void ImageLabel::mouseMoveEvent(QMouseEvent* e) {
    ex = e->position().x();
    ey = e->position().y();
    changeCursorStyle(e);
    if(isMouseLeftBtnDown){
        endX=e->position().x();
        endY=e->position().y();
    }
    switch (OptionFlag) {
        case OptionTypeEnum::PaintFreedom: {
            _freedomPoints.push_back(_endPoint);
            break;
        }
        case OptionTypeEnum::ActionCrop:{
            if(!_isCutting){
                _cutex=e->pos().x();
                _cutey=e->pos().y();
            }
            break;
        }
        default: {

        }
    }
    imageResizeX=e->position().x();
    imageResizeY=e->position().y();
	update();
}
//重写鼠标弹起事件
void ImageLabel::mouseReleaseEvent(QMouseEvent* e) {
	isOption = false;
    isMouseLeftBtnDown=false;
    isTopLeft=isTopCenter=isTopRight=isCenterLeft=isCenterRight=isBottomLeft=isBottomCenter=isBottomRight=false;
    ex=e->pos().x();
    ey=e->pos().y();
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
            //点击蚂蚁线范围之外，表示裁剪确认
            if(antLine!=nullptr){
                QRect cutRect(antLine->x(),antLine->y(),antLine->width(),antLine->height());
                if(!cutRect.contains(_startPoint))
                {
                    QPixmap pixmap = this->pixmap();
                    QPixmap tmpPixmap = pixmap.copy(cutRect);
                    this->resize(tmpPixmap.width(), tmpPixmap.height());
                    this->setPixmap(tmpPixmap);
                    _cutsx=_cutsy=_cutex=_cutey=-1;
                    _isCutting=false;
                    antLine->close();
                    delete antLine;
                    antLine=nullptr;
                }else{
                    if(!_isCutting){
                        _cutex=e->pos().x();
                        _cutey=e->pos().y();
                        _isCutting=true;
                    }
                }
            }
		}
        case OptionTypeEnum::PaintFreedom:{
            _listLine.push_back(_freedomPoints);
            break;
        }
        case OptionTypeEnum::Fuzzy:{
            if(antLine!=nullptr){
                //高斯模糊
                QRect fuzzyRect(antLine->x(),antLine->y(),antLine->width(),antLine->height());
                QImage partImage=this->pixmap().toImage().copy(fuzzyRect);
                GaussianBlur gassianBlur;
                QImage fuzzyImage = gassianBlur.ApplyGaussianBlur(partImage,10);
                BlurImage blurImage;
                blurImage.x=antLine->x();
                blurImage.y=antLine->y();
                blurImage.image=fuzzyImage;
                m_ListImages.push_back(blurImage);
                antLine->close();
                delete antLine;
                antLine=nullptr;
            }
            break;
        }
	}
}
//重写lable的绘制方法
void ImageLabel::paintEvent(QPaintEvent* event) {
    //先调用父类的paintEvent为了显示'背景'!!!
    QLabel::paintEvent(event);
    QPainter painter(this);
	float l = 10;
	float a = 0.5;
    QPen pen(penColor,2);
    //实时绘制，鼠标左键按下的时候绘制
    if(isMouseLeftBtnDown){
        switch (OptionFlag) {
            case OptionTypeEnum::PaintRect: {
                painter.setPen(pen);
                painter.drawRect(QRect(sx,sy,ex-sx,ey-sy));
                break;
            }
            case OptionTypeEnum::PaintArrow: {
                painter.setPen(pen);
                float x3 = ex - l * cos(atan2((ey - sy), (ex - sx)) - a);//计算箭头的终点（x3,y3）
                float y3 = ey - l * sin(atan2((ey - sy), (ex - sx)) - a);
                float x4 = ex - l * sin(atan2((ex - sx), (ey - sy)) - a);//计算箭头的终点（x4,y4）
                float y4 = ey - l * cos(atan2((ex - sx), (ey - sy)) - a);
                painter.drawLine(ex, ey, x3, y3);
                painter.drawLine(ex, ey, x4, y4);
                painter.drawLine(sx, sy, ex, ey);
                break;
            }
            case OptionTypeEnum::PaintFreedom:{
                for(int i=0;i<_freedomPoints.size()-1;i++)
                {
                    painter.setPen(pen);
                    painter.drawLine(_freedomPoints[i],_freedomPoints[i+1]);
                }
                break;
            }
            case OptionTypeEnum::ActionCrop:{
                if(_cutsx!=-1&&_cutsy!=-1&&_cutex!=-1&&_cutey!=-1)
                {
                    //剪切绘制蚂蚁线
                    if (antLine == nullptr) {
                        antLine = new AntLine(this);
                    }
                    antLine->resize(abs(_cutex - _cutsx), abs(_cutey - _cutsy));
                    if(_cutex>_cutsx&&_cutey>_cutsy)
                    {
                        antLine->move(_cutsx, _cutsy);
                    }
                    else if(_cutsx>_cutex&&_cutey>_cutsy){
                        antLine->move(_cutex, _cutsy);
                    }
                    else if(_cutex>_cutsx&&_cutsy>_cutey)
                    {
                        antLine->move(_cutsx,_cutey);
                    }
                    else if(_cutsx>_cutex&&_cutsy>_cutey){
                        antLine->move(_cutex,_cutey);
                    }
                    antLine->show();
                }
                break;
            }
            case OptionTypeEnum::Fuzzy:{
                if (antLine == nullptr) {
                    antLine = new AntLine(this);
                }
                antLine->resize(abs(ex - sx), abs(ey - sy));
                if(ex>sx&&ey>sy)
                {
                    antLine->move(sx, sy);
                }
                else if(sx>ex&&ey>sy){
                    antLine->move(ex, sy);
                }
                else if(ex>sx&&sy>ey)
                {
                    antLine->move(sx,ey);
                }
                else if(sx>ex&&sy>ey){
                    antLine->move(ex,ey);
                }
                antLine->show();
            }
        }
    }

	//绘制矩形
	for (int i = 0; i != _listRect.size(); i++) {
        painter.setPen(pen);
		painter.drawRect(QRect(_listRect.at(i).x(), _listRect.at(i).y(), _listRect.at(i).width(), _listRect.at(i).height()));
	}
	//绘制箭头
	for (int i = 0; i != _listSeat.size(); i++)
	{
        painter.setPen(pen);
		float x3 = _listSeat[i][2] - l * cos(atan2((_listSeat[i][3] - _listSeat[i][1]), (_listSeat[i][2] - _listSeat[i][0])) - a);//计算箭头的终点（x3,y3）
		float y3 = _listSeat[i][3] - l * sin(atan2((_listSeat[i][3] - _listSeat[i][1]), (_listSeat[i][2] - _listSeat[i][0])) - a);
		float x4 = _listSeat[i][2] - l * sin(atan2((_listSeat[i][2] - _listSeat[i][0]), (_listSeat[i][3] - _listSeat[i][1])) - a);//计算箭头的终点（x4,y4）
		float y4 = _listSeat[i][3] - l * cos(atan2((_listSeat[i][2] - _listSeat[i][0]), (_listSeat[i][3] - _listSeat[i][1])) - a);
		painter.drawLine(_listSeat[i][2], _listSeat[i][3], x3, y3);
		painter.drawLine(_listSeat[i][2], _listSeat[i][3], x4, y4);
		painter.drawLine(_listSeat[i][0], _listSeat[i][1], _listSeat[i][2], _listSeat[i][3]);
	}
	//自由绘制
    for (int i = 0; i < _listLine.size(); i++) {
        for(int j=0;j<_listLine[i].size()-1;j++){
            painter.setPen(pen);
            painter.drawLine(_listLine[i][j],_listLine[i][j+1]);
        }
	}
    //绘制模糊后的图片
    for(int i=0;i<m_ListImages.size();i++){
        painter.drawImage(m_ListImages[i].x,m_ListImages[i].y,m_ListImages[i].image);
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
//改变图片大小
void ImageLabel::resizePixmap(){
    QPixmap pixmap = this->pixmap();
    int width=pixmap.width()+ex-sx;
    int height=pixmap.height()+ey-ey;
    QPixmap newPixmap(width,height);
    newPixmap.fill(Qt::white);

    QPainter painter(&newPixmap);
    painter.drawPixmap(QRect(0,0, width,height), pixmap);
    this->setPixmap(newPixmap);
}
//改变鼠标样式
void ImageLabel::changeCursorStyle(QMouseEvent* e){
    QPoint cursorPoint=e->pos();
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
}

