#include "editwindow.h"
#include "ui_editwindow.h"

#define STRETCH_RECT_HEIGHT 4
#define STRETCH_RECT_WIDTH 4

int editwindow::painttype=0;

QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent);

QPixmap *PlabelPixmap=nullptr;
QImage PlabelImage;

editwindow::editwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
    ui->tabWidget->layout();
    //这样每页都会有关闭按钮
    ui->tabWidget->setTabsClosable(true);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));
}

editwindow::~editwindow()
{
    delete ui;
}

void editwindow::editview(QPixmap *qpix){
    ui->tabWidget->clear();
    PlabelImage = qpix->toImage();
    //插入页
    QString tabname="新建";
    QString tabnum=QString::number(ui->tabWidget->count(),10);
    tabname.append(tabnum);
    int tabindex=ui->tabWidget->count()-1<0?0:ui->tabWidget->count()-1;
    CreateTab(*qpix,tabname);
    //状态栏显示
    sizeStatus=new QLabel("大小："+QString::number(qpix->width())+'x'+QString::number(qpix->height()));
    scaleStatus=new QLabel("缩放："+QString::number(Scale)+"%");
    ui->statusbar->addWidget(sizeStatus);
    ui->statusbar->addWidget(scaleStatus);
}

//重写鼠标按下方法
void Plabel::mousePressEvent(QMouseEvent *e){
    sx=e->x();
    sy=e->y();
    glsx=e->globalX();
    glsy=e->globalY();
    _startPoint=e->pos();
    _endPoint=e->pos();
}

void Plabel::mouseMoveEvent(QMouseEvent *e){
    ex=e->x();
    ey=e->y();
    glex=e->globalX();
    gley=e->globalY();
    _endPoint=e->pos();
    switch (editwindow::painttype) {
        case 4:{
            QVector<QPoint> tmpPoint;
            tmpPoint.append(_startPoint);
            tmpPoint.append(_endPoint);
            _listLine.append(tmpPoint);
            break;
        }
    }
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
            _listSeat.append(tmpseat);
            break;
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
            QImage result = applyEffectToImage(copyImage, blur,0);
            painter.drawImage(sx,sy,result);
            break;
        }
        case 4:{
            painter.setPen(QPen(Qt::red,2));
            painter.drawLine(_startPoint,_endPoint);
            _startPoint=_endPoint;
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
    int tabIndex=ui->tabWidget->currentIndex();
    QDateTime timenow=QDateTime::currentDateTime();
    QString filestr=timenow.toString("yyyy-MM-dd-hhmmss");
    QFileDialog *fileDialog=new QFileDialog();
    fileDialog->setWindowTitle(tr("另存为"));
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    fileDialog->setFileMode(QFileDialog::AnyFile);
    QString filename=fileDialog->getSaveFileName(this,tr("另存为"),filestr+".png");
    if(!filename.isNull()){
        int tabIndex= ui->tabWidget->currentIndex();
        QString tabName=ui->tabWidget->tabText(tabIndex);
        ui->tabWidget->currentWidget();

//        //针对系统进行缩放的情况
//        QPixmap tmppmap =pmap.copy((pmap.width()-imagelabel->width())/2,(pmap.height()-imagelabel->height())/2,imagelabel->width(),imagelabel->height());
//        pmap.save(filename,nullptr,100);
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

//自由绘制
void editwindow::on_actionpaintfreedom_triggered(bool checked)
{
    if(checked){
        editwindow::painttype=4;
    }
}
//放大
void editwindow::on_enlarge_triggered()
{
    const int num=2;
    //获取原图片
    int pixWidth=imagelabel->pixmap().width();
    int pixHeigth=imagelabel->pixmap().height();
    QPixmap pixMap=QPixmap::fromImage(PlabelImage.scaled(pixWidth*num,pixHeigth*num,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    imagelabel->setPixmap(pixMap);
    imagelabel->resize(pixMap.width(),pixMap.height());
    sizeStatus->setText("大小："+QString::number(pixMap.width())+"x"+QString::number(pixMap.height()));
    Scale=Scale*num;
    scaleStatus->setText("缩放："+QString::number(Scale)+"%");
}

//缩小
void editwindow::on_narrow_triggered()
{
    const int num=2;
    int pixWidth=imagelabel->pixmap().width();
    int pixHeigth=imagelabel->pixmap().height();
    QPixmap pixMap=QPixmap::fromImage(PlabelImage.scaled(pixWidth/num,pixHeigth/num,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    imagelabel->setPixmap(pixMap);
    imagelabel->resize(pixMap.width(),pixMap.height());
    sizeStatus->setText("大小："+QString::number(pixMap.width())+"x"+QString::number(pixMap.height()));
    Scale=Scale/num;
    scaleStatus->setText("缩放："+QString::number(Scale)+"%");
}

//打开文件
void editwindow::on_fileopen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"),"./", tr("Image files(*.bmp *.jpg *.png);All files (*.*)"));
    if(!fileName.isEmpty())
    {
        QFileInfo fileInfo=QFileInfo(fileName);
        QImage img;
        if(img.load(fileName)){
            CreateTab(QPixmap::fromImage(img),fileInfo.fileName());
        }
    }
}
//创建tab页
void editwindow::CreateTab(QPixmap pixMap,QString fileName){
    //保存原始图片
    //创建一个窗口，放到tab里头
    QWidget *widget = new QWidget();
    QGridLayout *qgridlayout=new QGridLayout(widget);
    //创建滚动条
    QScrollArea *scrollarea=new QScrollArea(widget);
    scrollarea->setWidgetResizable(false);
    //创建一个label用来显示图片
    Plabel *imagelabel=new Plabel();
    imagelabel->setObjectName(fileName);
    imagelabel->setScaledContents(true);
    imagelabel->setStyleSheet("background:red");
    // 显示图像
    imagelabel->setPixmap(pixMap);
    // 图像与imgLabel同大小
    imagelabel->resize(pixMap.width(), pixMap.height());
    imagelabel->setAlignment(Qt::AlignCenter);
    scrollarea->setAlignment(Qt::AlignCenter);
    scrollarea->setWidget(imagelabel);
    qgridlayout->addWidget(scrollarea);
    //插入页
    ui->tabWidget->addTab(widget,fileName);
}

void editwindow::removeSubTab(int index)
{
    ui->tabWidget->removeTab(index);
}

void editwindow::on_setting_triggered()
{
    Setting *setting=new Setting();
    setting->show();
}


void editwindow::on_actionupload_triggered()
{
    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "提示", "确定要上传图片吗?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;
    QPixmap pixMap=QPixmap::fromImage(PlabelImage);
    QByteArray bytearray;
    QBuffer buffer(&bytearray);
    buffer.open(QIODevice::WriteOnly);
    bool bOk = pixMap.save(&buffer,"PNG",20);
    QDateTime timenow=QDateTime::currentDateTime();
    QString fileName=timenow.toString("yyyy-MM-dd-hhmmss")+".png";
    WordpressApi *wordpressApi=new WordpressApi();
    wordpressApi->GetToken();
    bool res=wordpressApi->UploadFile(bytearray,fileName);
    QMessageBox::information(this,"提示","上传成功！",QMessageBox::Ok);

}

