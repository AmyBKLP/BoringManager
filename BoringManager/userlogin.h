#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>
#include <QPaintEvent>
#include <QPushButton>
#include "pnglineedit.h"
#include "USERStruct.h"
#include "staticbutton.h"

class userLogin : public QWidget
{
    Q_OBJECT
public:
    explicit userLogin(QWidget *parent = 0);

protected: //主界面移动
    //void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:

public slots:

private:
    //查找list表里面是否存在该用户名和密码
    bool MapCheckWidget(const QString &Key , const QString &key);
    staticButton *closebtn;
    staticButton *minbtn;
    bool mMoving;            //判断鼠标是否按下去
    QPoint mMovePosition;    //鼠标按下去的坐标

    pngLineedit *user;
    pngLineedit *passwd;

    QList <USERANDPASSWD> list; //自动保存账户和密码
};

#endif // USERLOGIN_H
