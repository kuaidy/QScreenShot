#include "fixedsizeform.h"
#include "ui_fixedsizeform.h"

fixedsizeform::fixedsizeform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fixedsizeform)
{
    ui->setupUi(this);
}

fixedsizeform::~fixedsizeform()
{
    delete ui;
}
