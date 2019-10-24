#include "userlogin.h"
#include <QApplication>
#include <QPaintEvent>
#include <QHBoxLayout>

userLogin::userLogin(QWidget *parent) : QWidget(parent)
{
    mMoving = false;
    list.clear();
    QHBoxLayout *hLayout = new QHBoxLayout();

    this->setWindowIcon(QIcon(":/image/logining.png"));
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);


   // QPixmap pix(":/image/loginback.png");
            //pix.scaled(350,500);
            //QSize wsize = this->size();image.scaled(wsize,Qt::IgnoreAspectRatio);//重新调整图像大小
            //  this->setMaximumSize(QSize(pix.width(),pix.height()));
            //  this->setMinimumSize(QSize(pix.width(),pix.height()));
    setWindowFlag(Qt::FramelessWindowHint);

    setAutoFillBackground(true);
 //   QPalette palette = this->palette();
  //  palette.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(palette);
    resize(350,500);


    //最小化按钮
  //  minbtn = new staticButton(":/image/min.png"); //最小化按钮
    minbtn = new staticButton(this);
    minbtn->setOneButtonInfo(":/main/min.png");

      minbtn->move(this->width()-60,0);
   // minbtn->setFixedSize(30,30);
   //minbtn->setFlat(true);//窗口透明不显示边框
    minbtn->setToolTip("最小化");
  //  minbtn->setStyleSheet("QPushButton{backgroud-image：:/image/min.png}"
                          //"QPushButton:hover{backgroud-image：:/image/min.png);}"
                          //"QPushButton:press{backgroud-image：:/image/min.png);}"
    //                      );
    connect(minbtn,&staticButton::buttonClicked,this,
                [=]()
                {
                    this->showMinimized();

                }
            );
minbtn->repaint();

    //关闭按钮
  //  closebtn = new staticButton(":/image/close.png"); //最小化按钮
    closebtn = new staticButton(this);
    closebtn->setOneButtonInfo(":/main/close.png");

    closebtn->move(this->width()-30,0);
    //closebtn->setFixedSize(30,30);
    //closebtn->setFlat(true);//窗口透明不显示边框
    closebtn->setToolTip("关闭窗口");

    connect(closebtn,&staticButton::buttonClicked,this,
                [=]()
                {
                    this->close();

                }
            );
   closebtn->repaint();
    hLayout->addWidget(minbtn);
    hLayout->addWidget(closebtn);
   // hLayout->setContentsMargins(5, 0, 5, 0);
   // hLayout->setSpacing(0);

    this->setLayout(hLayout);

}


void userLogin::mousePressEvent(QMouseEvent *event)
{
    mMoving = true ;
    mMovePosition = event->globalPos()-pos();
    return QWidget::mousePressEvent(event);

}
void userLogin::mouseReleaseEvent(QMouseEvent *event)
{
    mMoving = false ;
    return QWidget::mouseReleaseEvent(event);
}

void userLogin::mouseMoveEvent(QMouseEvent *event)
{

    if(mMoving && (event->buttons() && Qt::LeftButton)
           &&(event->globalPos()-mMovePosition).manhattanLength()
            > QApplication::startDragDistance())
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos()-pos();
    }
    return QWidget::mouseMoveEvent(event);
}

//void userLogin::paintEvent(QPaintEvent *event)
//{
//    return  QWidget::paintEvent(event);
//}

bool userLogin::MapCheckWidget(const QString &Key, const QString &key)
{
    foreach (USERANDPASSWD value, list) {
        if( (value.userName == Key) && ( value.Passwd == key) )
                return true ;
    }
    return false ;
}
