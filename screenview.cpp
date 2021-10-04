#include "screenview.h"
#include "ui_screenview.h"

screenview::screenview(QWidget *parent,QList<QRect> *listRect,int screentype)
    :QWidget(parent),ui(new Ui::screenview)
{
    ui->setupUi(this);

    rubberBand=NULL;
    shottype=screentype;

    screen =QGuiApplication::primaryScreen();
    if(const QWindow *window=windowHandle())
        screen=window->screen();
    if(!screen)
        return ;
    originalPixmap=screen->grabWindow(0);
    //全屏窗口
    setWindowState(Qt::WindowActive|Qt::WindowFullScreen);
    //解决只有鼠标按下时才捕捉鼠标移动
    setMouseTracking(true);

    //获取系统设置的显示比例
    float swidth=this->width();
    float rwidth=originalPixmap.width();
    Scale=rwidth/swidth;
//    shotcommon::Scale=Scale;
    connect(parent, SIGNAL(senddata(QPixmap)),this,SLOT(receiveData(QPixmap)));


    ListRect=listRect;
}

screenview::~screenview()
{
    delete ui;
}

//截图
void screenview::paintEvent(QPaintEvent *event){
    painter.begin(this);
    painter.setPen(QPen(Qt::red,2));
    painter.drawPixmap(0,0,originalPixmap);

    if(shottype==1)
    {
        //固定窗口截图
        rw=300;
        rh=200;
        int fixx=(ex-rw/2)>0?(ex-rw/2):0;
        int fixy=(ey-rh/2)>0?(ey-rh/2):0;
        fixedRect=QRect(fixx,fixy,rw,rh);
        painter.drawRect(fixedRect);
        painter.setPen(QPen(Qt::black,2));
        painter.drawText(fixx,fixy+rh+10,"F2调整大小");
    }else if(shottype==0)
    {
        if(sx>=0&&sy>=0)
        {
            painter.drawRect(QRect(sx,sy,ex-sx,ey-sy));
        }
    }else if(shottype==2){


        setAttribute(Qt::WA_TransparentForMouseEvents,true);

        POINT point;
        point.x=ex;
        point.y=ey;
        QWindow *m_window;

//        m_window = QWindow::fromWinId((WId)ChildWindowFromPointEx(GetDesktopWindow(),point,CWP_SKIPINVISIBLE|CWP_SKIPTRANSPARENT||CWP_SKIPDISABLED));
//        painter.drawRect(QRect(m_window->x(),m_window->y(),m_window->width(),m_window->height()));

        int j=0;
        for(int i=0;i<ListRect->count();i++)
        {
            if(j>0) continue;
            QRect rect=ListRect->at(i);
            CurrentWindow=rect;
            if(ex>rect.x()&&ex<(rect.x()+rect.width())&&ey>rect.y()&&ey<(rect.y()+rect.height())){
                painter.drawRect(rect);
                j++;
            }
        }
    }

    painter.end();
}

void screenview::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        sx=event->x();
        sy=event->y();

        startpoint=event->pos();

        if(shottype==1){
            this->close();
            sourcePixmap=originalPixmap.copy(fixedRect.x()*Scale,fixedRect.y()*Scale,fixedRect.width()*Scale,fixedRect.height()*Scale);
            emit senddata(sourcePixmap);
        }
        else if(shottype==2){
            this->close();
            sourcePixmap=originalPixmap.copy(CurrentWindow.x()*Scale,CurrentWindow.y()*Scale,CurrentWindow.width()*Scale,CurrentWindow.height()*Scale);
            emit senddata(sourcePixmap);
        }
    }
    else if(event->button()==Qt::RightButton)
    {
        this->close();
        emit showWin();
    }
    update();
}

void screenview::mouseMoveEvent(QMouseEvent *event){
    ex=event->x();
    ey=event->y();

    endpoint=event->pos();
    update();
}

void screenview::mouseReleaseEvent(QMouseEvent *event){
    this->close();

    ex=event->x();
    ey=event->y();

    sourcePixmap=originalPixmap.copy(sx*Scale,sy*Scale,(ex-sx)*Scale,(ey-sy)*Scale);
    emit senddata(sourcePixmap);
}

void screenview::receiveData(QString str){
    qDebug()<<str;
    show();
}

