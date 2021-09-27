#include "editwindow.h"
#include "ui_editwindow.h"

int editwindow::painttype=0;

QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent);

QPixmap *Plabel::PlabelPixmap=nullptr;

editwindow::editwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
    ui->tabWidget->layout();
}

editwindow::~editwindow()
{
    delete ui;
}

void editwindow::editview(QPixmap *qpix){
    ui->tabWidget->clear();

    //创建一个窗口，放到tab里头
    QWidget *widget = new QWidget();
//    widget->setStyleSheet("{background-color:gray;padding:0px}");

    QGridLayout *qgridlayout=new QGridLayout(widget);
    //创建滚动条
    QScrollArea *scrollarea=new QScrollArea();
    //scrollarea->setGeometry(400, 300, 300, 200);
    //scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //scrollarea->setWidgetResizable(true);
    //创建一个label用来显示图片
    imagelabel=new Plabel();

    //imagelabel->setScaledContents(true);
    imagelabel->setStyleSheet("{background-color:red;}");
    // 显示图像
//    imagelabel->setPixmap(*qpix);
    // 图像与imgLabel同大小
//    imagelabel->resize(qpix->width(), qpix->height());
//    qDebug()<<imagelabel->width();
//    qDebug()<<imagelabel->height();
    imagelabel->setAlignment(Qt::AlignCenter);

    scrollarea->setWidget(imagelabel);
//    scrollarea->setAlignment(Qt::AlignCenter);
    //setCentralWidget(scrollarea);
    // 初始图像
    //QImage image = QImage(500, 500, QImage::Format_RGB32);  // 新建图像
    //image.fill(qRgb(0, 255, 255));                         // 全白
    qgridlayout->addWidget(scrollarea);

    //插入页
    QString tabname="新建";
    QString tabnum=QString::number(ui->tabWidget->count(),10);
    tabname.append(tabnum);
    int tabindex=ui->tabWidget->count()-1<0?0:ui->tabWidget->count()-1;
    ui->tabWidget->insertTab(tabindex,widget,tabname);

    Plabel::PlabelPixmap=qpix;


}

//重写鼠标按下方法
void Plabel::mousePressEvent(QMouseEvent *e){
    sx=e->x();
    sy=e->y();
    glsx=e->globalX();
    glsy=e->globalY();
}

void Plabel::mouseMoveEvent(QMouseEvent *e){
    ex=e->x();
    ey=e->y();
    glex=e->globalX();
    gley=e->globalY();
    update();
}

void Plabel::mouseReleaseEvent(QMouseEvent *e){

    switch (editwindow::painttype) {
        case 1:{
            _listRect.append(QRect(sx,sy,ex-sx,ey-sy));
            break;
        }
        case 2:{
            QVector<int> tmpseat;
            tmpseat.append(sx);
            tmpseat.append(sy);
            tmpseat.append(ex);
            tmpseat.append(ey);
            _listseat.append(tmpseat);
            break;
        }
        case 3:{

        }
    }
}

//重写lable的绘制方法
void Plabel::paintEvent(QPaintEvent *event){
    QLabel::paintEvent(event);//先调用父类的paintEvent为了显示'背景'!!!
    QPainter painter(this);

    float l=10;
    float a=0.5;

    switch (editwindow::painttype) {
        case 1:{
            painter.setPen(QPen(Qt::red,2));
            painter.drawRect(QRect(sx,sy,ex-sx,ey-sy));
            break;
        }
        case 2:{
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
        case 3:{
            QImage copyImage=this->pixmap().copy(sx,sy,ex-sx,ey-sy).toImage();
            QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
            QGraphicsOpacityEffect *opac=new QGraphicsOpacityEffect;
            blur->setBlurRadius(5);
            opac->setOpacity(0.5);
    //        QImage source("C:\\Users\\kuai\\Desktop\\2021-07-28-203720.png");
            QImage result = applyEffectToImage(copyImage, blur,0);
            painter.drawImage(sx,sy,result);
            break;
        }
    }

    //绘制矩形
    for(int i = 0; i != _listRect.size(); i++){
        painter.drawRect(QRect(_listRect.at(i).x(),_listRect.at(i).y(),_listRect.at(i).width(),_listRect.at(i).height()));
    }

    //绘制箭头
    for(int i = 0; i != _listseat.size(); i++)
    {
        float x3 = _listseat[i][2] - l * cos(atan2((_listseat[i][3] - _listseat[i][1]) , (_listseat[i][2] - _listseat[i][0])) - a);//计算箭头的终点（x3,y3）
        float y3 = _listseat[i][3] - l * sin(atan2((_listseat[i][3] - _listseat[i][1]) , (_listseat[i][2] - _listseat[i][0])) - a);
        float x4 = _listseat[i][2] - l * sin(atan2((_listseat[i][2] - _listseat[i][0]) , (_listseat[i][3] - _listseat[i][1])) - a);//计算箭头的终点（x4,y4）
        float y4 = _listseat[i][3] - l * cos(atan2((_listseat[i][2] - _listseat[i][0]) , (_listseat[i][3] - _listseat[i][1])) - a);
        painter.drawLine(_listseat[i][2],_listseat[i][3],x3,y3);
        painter.drawLine(_listseat[i][2],_listseat[i][3],x4,y4);
        painter.drawLine(_listseat[i][0],_listseat[i][1],_listseat[i][2],_listseat[i][3]);
    }
}

//绘制箭头
void Plabel::paintArrow(int sx, int sy, int ex, int ey){

}


//选中矩形
void editwindow::on_paintrec_triggered()
{

}

//选中箭头
void editwindow::on_paintarrow_triggered()
{

}

//绘制矩形
void editwindow::on_paintrec_triggered(bool checked)
{
    if(checked){
        editwindow::painttype=1;
    }
}

//绘制箭头
void editwindow::on_paintarrow_triggered(bool checked)
{
       if(checked){
           editwindow::painttype=2;
       }
}

//另存为
void editwindow::on_filesaveother_triggered()
{
    QDateTime timenow=QDateTime::currentDateTime();
    QString filestr=timenow.toString("yyyy-MM-dd-hhmmss");
    QFileDialog *fileDialog=new QFileDialog();
    fileDialog->setWindowTitle(tr("另存为"));
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    fileDialog->setFileMode(QFileDialog::AnyFile);
    QString filename=fileDialog->getSaveFileName(this,tr("另存为"),filestr+".png");
    if(!filename.isNull()){
        QWidget *tmpwidget=ui->tabWidget->currentWidget();
        //适用于固定的布局
//        Plabel *tmplabel=(Plabel *)tmpwidget->children().at(1)->children().at(0)->children().at(0);
//        QPixmap pmap=tmplabel->pixmap();
//        QPixmap pmap(imagelabel->size());
//        imagelabel->render(&pmap);

        QPixmap pmap=imagelabel->grab(QRect(0,0,imagelabel->width(),imagelabel->height()));
        //针对系统进行缩放的情况
        QPixmap tmppmap =pmap.copy((pmap.width()-imagelabel->width())/2,(pmap.height()-imagelabel->height())/2,imagelabel->width(),imagelabel->height());
        tmppmap.save(filename,nullptr,100);
    }
}

//模糊
void editwindow::on_vague_triggered(bool checked)
{
    if(checked){
        editwindow::painttype=3;
    }
}

//图片模糊处理
QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent = 0)
{
    if(src.isNull()) return QImage();   //No need to do anything else!
    if(!effect) return src;             //No need to do anything else!
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

