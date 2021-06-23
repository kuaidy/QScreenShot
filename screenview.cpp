#include "screenview.h"
#include "ui_screenview.h"

screenview::screenview(QWidget *parent,int screentype) :
    QWidget(parent),
    ui(new Ui::screenview)
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
    }else if(shottype==0)
    {
        if(sx>=0&&sy>=0)
        {
            painter.drawRect(QRect(sx,sy,ex-sx,ey-sy));
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

        int x=this->mapFromGlobal(QCursor().pos()).x();
        int y=this->mapFromGlobal(QCursor().pos()).y();

        if(shottype==1){
            this->close();
            sourcePixmap=originalPixmap.copy(fixedRect);
            emit senddata(sourcePixmap);
        }
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
    sourcePixmap=originalPixmap.copy(sx,sy,ex-sx,ey-sy);
    emit senddata(sourcePixmap);
}

