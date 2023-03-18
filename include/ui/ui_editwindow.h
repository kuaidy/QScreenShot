/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editwindow
{
public:
    QAction *filenew;
    QAction *fileopen;
    QAction *filesaveother;
    QAction *enlarge;
    QAction *narrow;
    QAction *paintrec;
    QAction *paintarrow;
    QAction *actionpaintfreedom;
    QAction *actionupload;
    QAction *setting;
    QAction *actionCrop;
    QAction *about;
    QAction *copy;
    QAction *shear;
    QAction *parse;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_help;
    QMenu *menu_set;
    QStatusBar *statusbar;
    QToolBar *toolBarfile;
    QToolBar *toolBarSize;
    QToolBar *toolBarPaint;
    QToolBar *toolBarOption;
    QToolBar *toolBarClound;
    QToolBar *toolBarSet;

    void setupUi(QMainWindow *editwindow)
    {
        if (editwindow->objectName().isEmpty())
            editwindow->setObjectName(QString::fromUtf8("editwindow"));
        editwindow->resize(931, 460);
        filenew = new QAction(editwindow);
        filenew->setObjectName(QString::fromUtf8("filenew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        filenew->setIcon(icon);
        fileopen = new QAction(editwindow);
        fileopen->setObjectName(QString::fromUtf8("fileopen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        fileopen->setIcon(icon1);
        filesaveother = new QAction(editwindow);
        filesaveother->setObjectName(QString::fromUtf8("filesaveother"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/saveother.png"), QSize(), QIcon::Normal, QIcon::Off);
        filesaveother->setIcon(icon2);
        enlarge = new QAction(editwindow);
        enlarge->setObjectName(QString::fromUtf8("enlarge"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/enlarge.png"), QSize(), QIcon::Normal, QIcon::Off);
        enlarge->setIcon(icon3);
        narrow = new QAction(editwindow);
        narrow->setObjectName(QString::fromUtf8("narrow"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/narrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        narrow->setIcon(icon4);
        paintrec = new QAction(editwindow);
        paintrec->setObjectName(QString::fromUtf8("paintrec"));
        paintrec->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/paintrectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        paintrec->setIcon(icon5);
        paintarrow = new QAction(editwindow);
        paintarrow->setObjectName(QString::fromUtf8("paintarrow"));
        paintarrow->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/paintarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        paintarrow->setIcon(icon6);
        actionpaintfreedom = new QAction(editwindow);
        actionpaintfreedom->setObjectName(QString::fromUtf8("actionpaintfreedom"));
        actionpaintfreedom->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/drawfreedom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpaintfreedom->setIcon(icon7);
        actionupload = new QAction(editwindow);
        actionupload->setObjectName(QString::fromUtf8("actionupload"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionupload->setIcon(icon8);
        setting = new QAction(editwindow);
        setting->setObjectName(QString::fromUtf8("setting"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting->setIcon(icon9);
        actionCrop = new QAction(editwindow);
        actionCrop->setObjectName(QString::fromUtf8("actionCrop"));
        actionCrop->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCrop->setIcon(icon10);
        about = new QAction(editwindow);
        about->setObjectName(QString::fromUtf8("about"));
        copy = new QAction(editwindow);
        copy->setObjectName(QString::fromUtf8("copy"));
        QIcon icon11;
        QString iconThemeName = QString::fromUtf8("applications-office");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        copy->setIcon(icon11);
        shear = new QAction(editwindow);
        shear->setObjectName(QString::fromUtf8("shear"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/shear.png"), QSize(), QIcon::Normal, QIcon::Off);
        shear->setIcon(icon12);
        parse = new QAction(editwindow);
        parse->setObjectName(QString::fromUtf8("parse"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/parse.png"), QSize(), QIcon::Normal, QIcon::Off);
        parse->setIcon(icon13);
        centralwidget = new QWidget(editwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        editwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(editwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 931, 30));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        menu_set = new QMenu(menubar);
        menu_set->setObjectName(QString::fromUtf8("menu_set"));
        editwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(editwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        editwindow->setStatusBar(statusbar);
        toolBarfile = new QToolBar(editwindow);
        toolBarfile->setObjectName(QString::fromUtf8("toolBarfile"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarfile);
        toolBarSize = new QToolBar(editwindow);
        toolBarSize->setObjectName(QString::fromUtf8("toolBarSize"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarSize);
        toolBarPaint = new QToolBar(editwindow);
        toolBarPaint->setObjectName(QString::fromUtf8("toolBarPaint"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarPaint);
        toolBarOption = new QToolBar(editwindow);
        toolBarOption->setObjectName(QString::fromUtf8("toolBarOption"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarOption);
        toolBarClound = new QToolBar(editwindow);
        toolBarClound->setObjectName(QString::fromUtf8("toolBarClound"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarClound);
        toolBarSet = new QToolBar(editwindow);
        toolBarSet->setObjectName(QString::fromUtf8("toolBarSet"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarSet);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_set->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(filenew);
        menu_file->addAction(fileopen);
        menu_file->addAction(filesaveother);
        menu_help->addAction(about);
        toolBarfile->addAction(fileopen);
        toolBarfile->addAction(filesaveother);
        toolBarSize->addAction(enlarge);
        toolBarSize->addAction(narrow);
        toolBarPaint->addAction(actionpaintfreedom);
        toolBarPaint->addAction(paintarrow);
        toolBarPaint->addAction(paintrec);
        toolBarOption->addAction(actionCrop);
        toolBarOption->addAction(shear);
        toolBarOption->addAction(copy);
        toolBarOption->addAction(parse);
        toolBarClound->addAction(actionupload);
        toolBarSet->addAction(setting);

        retranslateUi(editwindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(editwindow);
    } // setupUi

    void retranslateUi(QMainWindow *editwindow)
    {
        editwindow->setWindowTitle(QCoreApplication::translate("editwindow", "\347\274\226\350\276\221\345\231\250-QScreenShot", nullptr));
        filenew->setText(QCoreApplication::translate("editwindow", "\346\226\260\345\273\272", nullptr));
        fileopen->setText(QCoreApplication::translate("editwindow", "\346\211\223\345\274\200", nullptr));
        filesaveother->setText(QCoreApplication::translate("editwindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        enlarge->setText(QCoreApplication::translate("editwindow", "\346\224\276\345\244\247", nullptr));
        narrow->setText(QCoreApplication::translate("editwindow", "\347\274\251\345\260\217", nullptr));
        paintrec->setText(QCoreApplication::translate("editwindow", "\347\273\230\345\210\266\347\237\251\345\275\242", nullptr));
#if QT_CONFIG(tooltip)
        paintrec->setToolTip(QCoreApplication::translate("editwindow", "\347\273\230\345\210\266\347\237\251\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        paintarrow->setText(QCoreApplication::translate("editwindow", "\347\273\230\345\210\266\347\256\255\345\244\264", nullptr));
#if QT_CONFIG(tooltip)
        paintarrow->setToolTip(QCoreApplication::translate("editwindow", "\347\273\230\345\210\266\347\256\255\345\244\264", nullptr));
#endif // QT_CONFIG(tooltip)
        actionpaintfreedom->setText(QCoreApplication::translate("editwindow", "\350\207\252\347\224\261\347\273\230\345\210\266", nullptr));
        actionupload->setText(QCoreApplication::translate("editwindow", "upload", nullptr));
#if QT_CONFIG(tooltip)
        actionupload->setToolTip(QCoreApplication::translate("editwindow", "\345\260\206\345\275\223\345\211\215\345\233\276\347\211\207\344\270\212\344\274\240", nullptr));
#endif // QT_CONFIG(tooltip)
        setting->setText(QCoreApplication::translate("editwindow", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        setting->setToolTip(QCoreApplication::translate("editwindow", "\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCrop->setText(QCoreApplication::translate("editwindow", "Crop", nullptr));
#if QT_CONFIG(tooltip)
        actionCrop->setToolTip(QCoreApplication::translate("editwindow", "\350\243\201\345\211\252", nullptr));
#endif // QT_CONFIG(tooltip)
        about->setText(QCoreApplication::translate("editwindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(tooltip)
        about->setToolTip(QCoreApplication::translate("editwindow", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        copy->setText(QCoreApplication::translate("editwindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        copy->setToolTip(QCoreApplication::translate("editwindow", "\345\244\215\345\210\266\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        shear->setText(QCoreApplication::translate("editwindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        shear->setToolTip(QCoreApplication::translate("editwindow", "\345\211\252\345\210\207\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        parse->setText(QCoreApplication::translate("editwindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        parse->setToolTip(QCoreApplication::translate("editwindow", "\347\262\230\350\264\264\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        menu_file->setTitle(QCoreApplication::translate("editwindow", "\346\226\207\344\273\266", nullptr));
        menu_help->setTitle(QCoreApplication::translate("editwindow", "\345\270\256\345\212\251", nullptr));
        menu_set->setTitle(QCoreApplication::translate("editwindow", "\350\256\276\347\275\256", nullptr));
        toolBarfile->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar", nullptr));
        toolBarSize->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar_2", nullptr));
        toolBarPaint->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar", nullptr));
        toolBarOption->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar", nullptr));
        toolBarClound->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar_2", nullptr));
        toolBarSet->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editwindow: public Ui_editwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
