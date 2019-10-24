#ifndef PNGLINEEDIT_H
#define PNGLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPaintEvent>

class pngLineedit : public QWidget
{
    Q_OBJECT

public:
    explicit pngLineedit(const QString &pngPath , QWidget *parent = 0);
  //  ~pngLineedit();

    void setText(const QString& text)
    {
        strText = text;
    }
    QString text()
    {
        return strText;
    }

    void Assigment(const QString& text); //给输入框设置数值
    void setEchoMode(QLineEdit::EchoMode flag); //设置是否为密码输入

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:


private:
    QLineEdit *lineEdit;    // 行编辑器
    QString pixPath;        // 设置图形行编辑器前的图标
    QString strText;        // 输入得到的字符串
};

#endif // PNGLINEEDIT_H
