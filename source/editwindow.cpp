#include "../include/editwindow.h"
#include "../include/ui/ui_editwindow.h"

#define STRETCH_RECT_HEIGHT 4
#define STRETCH_RECT_WIDTH 4

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
    //状态栏显示
    sizeStatus=new QLabel("大小：");
    scaleStatus=new QLabel("缩放：");
    ui->statusbar->addWidget(sizeStatus);
    ui->statusbar->addWidget(scaleStatus);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));
}

editwindow::~editwindow()
{
    delete ui;
}

void editwindow::editview(QPixmap *qpix){
    showMaximized();
//    ui->tabWidget->clear();
    PlabelImage = qpix->toImage();
    //插入页
    QString tabname="新建";
    QString tabnum=QString::number(ui->tabWidget->count(),10);
    tabname.append(tabnum);
    int tabindex=ui->tabWidget->count()-1<0?0:ui->tabWidget->count()-1;
    CreateTab(*qpix,tabname);
    //状态栏显示
//    sizeStatus=new QLabel("大小："+QString::number(qpix->width())+'x'+QString::number(qpix->height()));
//    scaleStatus=new QLabel("缩放："+QString::number(Scale)+"%");
//    ui->statusbar->addWidget(sizeStatus);
//    ui->statusbar->addWidget(scaleStatus);
    sizeStatus->setText("大小："+QString::number(qpix->width())+'x'+QString::number(qpix->height()));
    scaleStatus->setText("缩放："+QString::number(Scale)+"%");
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
        OptionFlag=OptionTypeEnum::PaintRec;
    }else{
        OptionFlag=OptionTypeEnum::None;
    }
}

//绘制箭头
void editwindow::on_paintarrow_triggered(bool checked)
{
   if(checked){
       OptionFlag=OptionTypeEnum::PaintArrow;
   }else{
       OptionFlag=OptionTypeEnum::None;
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
    QString fileName=fileDialog->getSaveFileName(this,tr("另存为"),filestr+".png");
    if(!fileName.isNull()){
        QWidget* qWidget= ui->tabWidget->currentWidget();
        //根据子控件的名称查找子控件
        QLabel* label = qWidget->findChild<QLabel*>();
        QPixmap pixmap=label->pixmap();
        pixmap.save(fileName);
    }
}

//模糊
void editwindow::on_vague_triggered(bool checked)
{
    if(checked){
       OptionFlag=OptionTypeEnum::Vague;
    }else{
       OptionFlag=OptionTypeEnum::None;
    }
}
//自由绘制
void editwindow::on_actionpaintfreedom_triggered(bool checked)
{
    if(checked){
        OptionFlag=OptionTypeEnum::PaintFreedom;
    }else{
        OptionFlag=OptionTypeEnum::None;
    }
}
//放大
void editwindow::on_enlarge_triggered()
{
    const int num=2;
    QWidget* qWidget= ui->tabWidget->currentWidget();
    //根据子控件的名称查找子控件
    QLabel* label = qWidget->findChild<QLabel*>();
    //获取原图片
    int pixWidth=PlabelImage.width();
    int pixHeigth=PlabelImage.height();
    Scale=Scale*num;
    QPixmap pixMap=QPixmap::fromImage(PlabelImage.scaled(pixWidth*Scale,pixHeigth*Scale,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    label->setPixmap(pixMap);
    label->resize(pixMap.width(),pixMap.height());
    sizeStatus->setText("大小："+QString::number(pixMap.width())+"x"+QString::number(pixMap.height()));
    scaleStatus->setText("缩放："+QString::number(Scale*100)+"%");
}

//缩小
void editwindow::on_narrow_triggered()
{
    const int num=2;
    QWidget* qWidget= ui->tabWidget->currentWidget();
    //根据子控件的名称查找子控件
    QLabel* label = qWidget->findChild<QLabel*>();
    //获取原图片
    int pixWidth=PlabelImage.width();
    int pixHeigth=PlabelImage.height();
    Scale=Scale/num;
    QPixmap pixMap=QPixmap::fromImage(PlabelImage.scaled(pixWidth*Scale,pixHeigth*Scale,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    label->setPixmap(pixMap);
    label->resize(pixMap.width(),pixMap.height());
    sizeStatus->setText("大小："+QString::number(pixMap.width())+"x"+QString::number(pixMap.height()));
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
//    connect(imagelabel,SIGNAL(mouseDoubleClickEvent(QMouseEvent*)),this,SLOT(removeSubTab(int)));
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
    ui->tabWidget->setCurrentWidget(widget);
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

//上传图片
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

//裁剪
void editwindow::on_actionCrop_triggered(bool checked)
{
    if(checked){
        OptionFlag=OptionTypeEnum::ActionCrop;
    }else{
        OptionFlag=OptionTypeEnum::None;
    }
}

