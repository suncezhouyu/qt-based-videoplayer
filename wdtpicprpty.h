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

private:
    Ui::WdtPicPrpty *ui;
};

#endif // WDTPICPRPTY_H
