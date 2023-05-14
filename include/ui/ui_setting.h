/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QWidget *tab_convention;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QSpinBox *imageCompressLevel;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidgetResource;
    QWidget *Wordpress;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label_1;
    QLineEdit *password;
    QLineEdit *userName;
    QLabel *label_2;
    QLineEdit *tokenUrl;
    QLabel *label;
    QLineEdit *mediaUrl;

    void setupUi(QWidget *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QString::fromUtf8("Setting"));
        Setting->resize(547, 422);
        gridLayout = new QGridLayout(Setting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Setting);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(Setting);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 3, 1, 1);

        tabWidget = new QTabWidget(Setting);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        tabWidget->setFont(font);
        tabWidget->setTabletTracking(false);
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget->setAcceptDrops(false);
        tabWidget->setToolTipDuration(-1);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab_convention = new QWidget();
        tab_convention->setObjectName(QString::fromUtf8("tab_convention"));
        layoutWidget = new QWidget(tab_convention);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 149, 31));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 0, 1, 1, 1);

        imageCompressLevel = new QSpinBox(layoutWidget);
        imageCompressLevel->setObjectName(QString::fromUtf8("imageCompressLevel"));
        imageCompressLevel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        imageCompressLevel->setMaximum(10);

        gridLayout_4->addWidget(imageCompressLevel, 0, 2, 1, 1);

        tabWidget->addTab(tab_convention, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidgetResource = new QTabWidget(tab);
        tabWidgetResource->setObjectName(QString::fromUtf8("tabWidgetResource"));
        Wordpress = new QWidget();
        Wordpress->setObjectName(QString::fromUtf8("Wordpress"));
        gridLayout_3 = new QGridLayout(Wordpress);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(Wordpress);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        label_1 = new QLabel(Wordpress);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_1, 0, 0, 1, 1);

        password = new QLineEdit(Wordpress);
        password->setObjectName(QString::fromUtf8("password"));

        gridLayout_3->addWidget(password, 1, 2, 1, 1);

        userName = new QLineEdit(Wordpress);
        userName->setObjectName(QString::fromUtf8("userName"));

        gridLayout_3->addWidget(userName, 0, 2, 1, 1);

        label_2 = new QLabel(Wordpress);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        tokenUrl = new QLineEdit(Wordpress);
        tokenUrl->setObjectName(QString::fromUtf8("tokenUrl"));

        gridLayout_3->addWidget(tokenUrl, 2, 2, 1, 1);

        label = new QLabel(Wordpress);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 3, 0, 1, 1);

        mediaUrl = new QLineEdit(Wordpress);
        mediaUrl->setObjectName(QString::fromUtf8("mediaUrl"));

        gridLayout_3->addWidget(mediaUrl, 3, 2, 1, 1);

        tabWidgetResource->addTab(Wordpress, QString());

        gridLayout_2->addWidget(tabWidgetResource, 0, 0, 1, 1, Qt::AlignTop);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 4);


        retranslateUi(Setting);

        tabWidget->setCurrentIndex(0);
        tabWidgetResource->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QWidget *Setting)
    {
        Setting->setWindowTitle(QCoreApplication::translate("Setting", "\350\256\276\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("Setting", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Setting", "\345\217\226\346\266\210", nullptr));
        label_4->setText(QCoreApplication::translate("Setting", "\345\233\276\347\211\207\350\264\250\351\207\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_convention), QCoreApplication::translate("Setting", "\345\270\270\350\247\204", nullptr));
        label_3->setText(QCoreApplication::translate("Setting", "token\345\234\260\345\235\200\357\274\232", nullptr));
        label_1->setText(QCoreApplication::translate("Setting", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Setting", "\345\257\206\347\240\201\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("Setting", "media\345\234\260\345\235\200\357\274\232", nullptr));
        tabWidgetResource->setTabText(tabWidgetResource->indexOf(Wordpress), QCoreApplication::translate("Setting", "WordPress", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Setting", "\344\270\212\344\274\240\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
