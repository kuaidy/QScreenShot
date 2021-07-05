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

    //获取系统设置的显示比例
    float swidth=this->width();
    float rwidth=originalPixmap.width();
    Scale=rwidth/swidth;

    connect(parent, SIGNAL(senddata(QPixmap)),this,SLOT(receiveData(QPixmap)));
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
    }else if(shottype==2){

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

    ex=event->x();
    ey=event->y();

    sourcePixmap=originalPixmap.copy(sx*Scale,sy*Scale,(ex-sx)*Scale,(ey-sy)*Scale);
    emit senddata(sourcePixmap);
}

void screenview::receiveData(QString str){
    qDebug()<<str;
    show();
}

