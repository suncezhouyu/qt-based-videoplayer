#include "wdtpicprpty.h"
#include "ui_wdtpicprpty.h"

WdtPicPrpty::WdtPicPrpty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdtPicPrpty)
{
    ui->setupUi(this);
}

WdtPicPrpty::~WdtPicPrpty()
{
    delete ui;
}
