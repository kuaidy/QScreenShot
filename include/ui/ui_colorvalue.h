/********************************************************************************
** Form generated from reading UI file 'colorvalue.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORVALUE_H
#define UI_COLORVALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorValue
{
public:
    QGridLayout *gridLayout;
    QLabel *colorRGB;
    QLabel *colorHex;
    QFrame *colorPre;

    void setupUi(QWidget *ColorValue)
    {
        if (ColorValue->objectName().isEmpty())
            ColorValue->setObjectName(QString::fromUtf8("ColorValue"));
        ColorValue->resize(142, 74);
        gridLayout = new QGridLayout(ColorValue);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        colorRGB = new QLabel(ColorValue);
        colorRGB->setObjectName(QString::fromUtf8("colorRGB"));

        gridLayout->addWidget(colorRGB, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        colorHex = new QLabel(ColorValue);
        colorHex->setObjectName(QString::fromUtf8("colorHex"));

        gridLayout->addWidget(colorHex, 4, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        colorPre = new QFrame(ColorValue);
        colorPre->setObjectName(QString::fromUtf8("colorPre"));
        colorPre->setStyleSheet(QString::fromUtf8(""));
        colorPre->setFrameShape(QFrame::StyledPanel);
        colorPre->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(colorPre, 0, 0, 1, 1);


        retranslateUi(ColorValue);

        QMetaObject::connectSlotsByName(ColorValue);
    } // setupUi

    void retranslateUi(QWidget *ColorValue)
    {
        ColorValue->setWindowTitle(QCoreApplication::translate("ColorValue", "Form", nullptr));
        colorRGB->setText(QCoreApplication::translate("ColorValue", "R:255 G:255 B:255", nullptr));
        colorHex->setText(QCoreApplication::translate("ColorValue", "#FFFFFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorValue: public Ui_ColorValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORVALUE_H
