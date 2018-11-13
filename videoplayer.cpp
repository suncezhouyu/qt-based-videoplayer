#include "videoplayer.h"
#include "ui_videoplayer.h"
#include <QFileDialog>
#include <QDir>

VideoPlayer::VideoPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoPlayer)
{
    ui->setupUi(this);

    m_pPlayer = new QMediaPlayer;
    m_pPlayerWidget = ui->widget;//new QVideoWidget;
    m_pPlayer->setVideoOutput(m_pPlayerWidget);
    //ui->verticalLayout->addWidget(m_pPlayerWidget);

    m_pPlayList = new QMediaPlaylist;
    QString qstrPath = QDir::currentPath() + "/video";
    QDir dir(qstrPath);
    QStringList filters;
    filters<<"*.avi"<<"*.mp4";
    QStringList files = dir.entryList(filters, QDir::Files | QDir::Readable, QDir::Name);
    foreach(QString qstrName, files)
    {
        m_pPlayList->addMedia(QUrl::fromLocalFile(QString("%1/%2").arg(qstrPath).arg(qstrName)));
    }
    m_pPlayer->setPlaylist(m_pPlayList);

    m_pPlayerWidget->setAutoFillBackground(true);
    QPalette qplte;
    qplte.setColor(QPalette::Window, QColor(0,0,0));
    m_pPlayerWidget->setPalette(qplte);
    //载入
    connect(ui->BtnLoad, SIGNAL(clicked()), this, SLOT(OnSetMediaFile()));
    //播放
    connect(ui->BtnPlay, SIGNAL(clicked()), m_pPlayer, SLOT(play()));
    //停止
    connect(ui->BtnStop, SIGNAL(clicked()), m_pPlayer, SLOT(stop()));

    connect(m_pPlayer, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(OnStateChanged(QMediaPlayer::State)));

    ui->BtnStop->setEnabled(false);
    //设置滑块行为
    m_bReLoad = true;
    ui->slider->setEnabled(false);
    connect(m_pPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(OnSlider(qint64)));
    connect(m_pPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(OnDurationChanged(qint64)));
    connect(ui->slider, SIGNAL(sigProgress(qint64)), m_pPlayer, SLOT(setPosition(qint64)));
    m_pPlayer->setNotifyInterval(500);

    connect(ui->BtnSave, SIGNAL(clicked()), this, SLOT(OnSavePic()));

    m_pWdtPicPrpty = new WdtPicPrpty;
    m_pWdtPicPrpty->hide();
}

VideoPlayer::~VideoPlayer()
{
    delete m_pPlayer;
    delete m_pPlayerWidget;
    delete m_pPlayList;
    delete m_pWdtPicPrpty;
    delete ui;
}

void VideoPlayer::OnSetMediaFile(void)
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    if(!fileNames.empty())
    {
        m_pPlayer->setMedia(QUrl::fromLocalFile(fileNames[0]));
        m_bReLoad = true;
        ui->slider->setValue(0);
    }
}

void VideoPlayer::OnSlider(qint64 i64Pos)
{
    ui->slider->setProgress(i64Pos);
}

void VideoPlayer::OnDurationChanged(qint64 i64Duration)
{
    if(i64Duration > 0 && m_bReLoad)
    {
        ui->slider->setRange(0, i64Duration);
        m_bReLoad = false;
    }
}


void VideoPlayer::OnStateChanged(QMediaPlayer::State enumState)
{
    if(QMediaPlayer::StoppedState == enumState)
    {
        ui->BtnPlay->setEnabled(true);
        ui->BtnStop->setEnabled(false);
        ui->slider->setEnabled(false);
    }
    else if(QMediaPlayer::PlayingState == enumState)
    {
        ui->BtnPlay->setEnabled(false);
        ui->BtnStop->setEnabled(true);
        ui->slider->setEnabled(true);
    }
}

void VideoPlayer::OnSavePic(void)
{
    QScreen * srcn = QGuiApplication::primaryScreen();
    QPixmap pixmapTmp = srcn->grabWindow(0);

    QRect rctPlayer = m_pPlayerWidget->geometry();
    QPoint pnt = mapToGlobal(QPoint(rctPlayer.left(), rctPlayer.top()));
    //QRect rctMain = geometry();
    //QRect rctLayout = ui->verticalLayout->geometry();
    QRect rctVideo;
    //rctVideo.setX(rctMain.x() + rctPlayer.x() + rctLayout.x());
    //rctVideo.setY(rctMain.y() + rctPlayer.y() + rctLayout.y());
    rctVideo.setX(pnt.x());
    rctVideo.setY(pnt.y());
    rctVideo.setWidth(rctPlayer.width());
    rctVideo.setHeight(rctPlayer.height());

    m_pixmap = pixmapTmp.copy(rctVideo);
    m_pWdtPicPrpty->show();
    m_pWdtPicPrpty->vSetOverView(m_pixmap);
}
