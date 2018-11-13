#include "wdtpicprpty.h"
#include "ui_wdtpicprpty.h"
#include "vGetImgPlacement.h"
#include <QPainter>
#include <QDebug>

WdtPicPrpty::WdtPicPrpty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdtPicPrpty)
{
    ui->setupUi(this);
    connect(ui->BtnCapture, SIGNAL(clicked()), this, SLOT(OnCapture()));
}

WdtPicPrpty::~WdtPicPrpty()
{
    delete ui;
}

void WdtPicPrpty::vSetOverView(QPixmap pixmap)
{
    //qDebug()<<ui->lbl_OverView->width()<<ui->lbl_OverView->height();
    int iLeftPos, iTopPos, iNewImgWidth, iNewImgHeight;
    vGetImgPlacement(ui->lbl_OverView->width(), ui->lbl_OverView->height(),
                     pixmap.width(), pixmap.height(), iLeftPos, iTopPos, iNewImgWidth, iNewImgHeight);
    QPixmap pixTmp(ui->lbl_OverView->width(), ui->lbl_OverView->height());
    QPainter qp;
    qp.begin(&pixTmp);
    qp.fillRect(pixTmp.rect(), QColor(0,0,0));
    qp.drawPixmap(QRect(iLeftPos, iTopPos, iNewImgWidth, iNewImgHeight), pixmap, pixmap.rect());
    qp.end();
    ui->lbl_OverView->setPixmap(pixTmp);
}

void WdtPicPrpty::OnCapture(void)
{

}
