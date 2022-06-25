#include "../include/fixedsizeform.h"
#include "../include/ui/ui_fixedsizeform.h"

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
