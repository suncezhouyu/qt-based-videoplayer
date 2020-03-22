#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QtMultimedia>
#include <QVideoWidget>
#include "wdtpicprpty.h"

namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

    bool            m_bReLoad;

    WdtPicPrpty   * m_pWdtPicPrpty;

public slots:
    void            OnSetMediaFile(void);
    void            OnSlider(qint64);
    void            OnDurationChanged(qint64);
    void            OnStateChanged(QMediaPlayer::State);
    void            OnSavePic(void);
private:
    QVideoWidget    *       m_pPlayerWidget;
    QMediaPlayer    *       m_pPlayer;
    QMediaPlaylist  *       m_pPlayList;
    Ui::VideoPlayer *ui;
};

#endif // VIDEOPLAYER_H
