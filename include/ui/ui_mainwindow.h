/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_fullscreenshot;
    QPushButton *pb_regscreenshot;
    QPushButton *pb_windowsshot;
    QPushButton *pb_fixedsize;
    QPushButton *pb_colorpicker;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(230, 54);
        MainWindow->setMinimumSize(QSize(230, 54));
        MainWindow->setMaximumSize(QSize(230, 54));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("padding:0px;"));
        MainWindow->setAnimated(true);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_fullscreenshot = new QPushButton(centralwidget);
        pb_fullscreenshot->setObjectName(QString::fromUtf8("pb_fullscreenshot"));
        pb_fullscreenshot->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_fullscreenshot->sizePolicy().hasHeightForWidth());
        pb_fullscreenshot->setSizePolicy(sizePolicy);
        pb_fullscreenshot->setStyleSheet(QString::fromUtf8("margin:0px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_fullscreenshot->setIcon(icon1);
        pb_fullscreenshot->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pb_fullscreenshot);

        pb_regscreenshot = new QPushButton(centralwidget);
        pb_regscreenshot->setObjectName(QString::fromUtf8("pb_regscreenshot"));
        pb_regscreenshot->setEnabled(true);
        sizePolicy.setHeightForWidth(pb_regscreenshot->sizePolicy().hasHeightForWidth());
        pb_regscreenshot->setSizePolicy(sizePolicy);
        pb_regscreenshot->setStyleSheet(QString::fromUtf8("margin:0px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_regscreenshot->setIcon(icon2);
        pb_regscreenshot->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pb_regscreenshot);

        pb_windowsshot = new QPushButton(centralwidget);
        pb_windowsshot->setObjectName(QString::fromUtf8("pb_windowsshot"));
        pb_windowsshot->setEnabled(true);
        sizePolicy.setHeightForWidth(pb_windowsshot->sizePolicy().hasHeightForWidth());
        pb_windowsshot->setSizePolicy(sizePolicy);
        pb_windowsshot->setStyleSheet(QString::fromUtf8("margin:0px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/activewindow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_windowsshot->setIcon(icon3);
        pb_windowsshot->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pb_windowsshot);

        pb_fixedsize = new QPushButton(centralwidget);
        pb_fixedsize->setObjectName(QString::fromUtf8("pb_fixedsize"));
        pb_fixedsize->setEnabled(true);
        sizePolicy.setHeightForWidth(pb_fixedsize->sizePolicy().hasHeightForWidth());
        pb_fixedsize->setSizePolicy(sizePolicy);
        pb_fixedsize->setStyleSheet(QString::fromUtf8("margin:0px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/paintrectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_fixedsize->setIcon(icon4);
        pb_fixedsize->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pb_fixedsize);

        pb_colorpicker = new QPushButton(centralwidget);
        pb_colorpicker->setObjectName(QString::fromUtf8("pb_colorpicker"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/ColorPicker.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_colorpicker->setIcon(icon5);
        pb_colorpicker->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pb_colorpicker, 0, Qt::AlignHCenter);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\210\252\345\233\276", nullptr));
#if QT_CONFIG(tooltip)
        pb_fullscreenshot->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\217\346\210\252\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_fullscreenshot->setText(QString());
#if QT_CONFIG(tooltip)
        pb_regscreenshot->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\210\252\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_regscreenshot->setText(QString());
#if QT_CONFIG(tooltip)
        pb_windowsshot->setToolTip(QCoreApplication::translate("MainWindow", "\346\215\225\346\215\211\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_windowsshot->setText(QString());
#if QT_CONFIG(tooltip)
        pb_fixedsize->setToolTip(QCoreApplication::translate("MainWindow", "\346\210\252\345\217\226\345\233\272\345\256\232\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_fixedsize->setText(QString());
        pb_colorpicker->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
