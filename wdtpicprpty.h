#ifndef WDTPICPRPTY_H
#define WDTPICPRPTY_H

#include <QWidget>

namespace Ui {
class WdtPicPrpty;
}

class WdtPicPrpty : public QWidget
{
    Q_OBJECT

public:
    explicit WdtPicPrpty(QWidget *parent = 0);
    ~WdtPicPrpty();
    void            vSetOverView(void);
    void            vSetCapture(QPixmap &, QRect);

public slots:
    void            OnCapture(void);
private:
    QPixmap         m_pixmap;
    Ui::WdtPicPrpty *ui;
};

#endif // WDTPICPRPTY_H
