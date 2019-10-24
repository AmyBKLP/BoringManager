#include "pnglineedit.h"
#include <QPainter>
#include <QRect>

pngLineedit::pngLineedit(const QString &pngPath,QWidget *parent)
    : pixPath(pngPath),
      QWidget(parent)
{

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    this->setPalette(palette);                //设置背景为白色

    lineEdit = new QLineEdit(this);
    lineEdit->move(21,6);
    lineEdit->setFrame(false); //去边框
    lineEdit->setFixedWidth(180);
    connect(lineEdit,&QLineEdit::textChanged,
            [=](const QString text)
            {
                strText = text ;
            });
    this->setFixedWidth(210);
    this->setFixedHeight(50);
}

void pngLineedit::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawPixmap(3,4,QPixmap(pixPath));    //画图标
    //画输入框圆矩形外框
    painter.setRenderHint(QPainter::Antialiasing);//反锯齿
    painter.setPen(QPen(Qt::black));
    QRect rect = this->rect();
    rect.setWidth(rect.width()-1);
    rect.setHeight(rect.height()-16);
    painter.drawRoundedRect(rect,15,15);
}

void pngLineedit::Assigment(const QString &text) //给输入框设置值
{
    lineEdit->setText(text);
}
