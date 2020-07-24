#ifndef STATICBUTTON_H
#define STATICBUTTON_H

#include <QWidget>
#include "common.h"

class staticButton : public QWidget
{
    Q_OBJECT
public:
    explicit staticButton(QWidget *parent = 0);
    explicit staticButton(const QString &icon, int num = 4,QWidget *parent = 0); //默认为一张图片的icon
    explicit staticButton(const QString &icon, bool isDivision,int num = 3 ,QWidget *parent = 0);

    void setOneButtonInfo(const QString &icon,int num=4);
    void setDivisionButtonInfo(const QString &icon, int num =3);
    void setCursorEnabled(bool enabled);
    void setButtonStatus(BUTTONSTATUS status);


signals:
    void buttonClicked();
    void enterSignal();
    void leaveSignal();

protected:
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event) ;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event) ;
    void changeEvent(QEvent *e) ;

private:
    QPixmap m_currentPix;
    QList<QPixmap> m_pixList;
    int m_num;
    QCursor m_preCursor;
    bool m_isCursor;
};

#endif // STATICBUTTON_H
