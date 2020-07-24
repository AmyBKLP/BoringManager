#include "staticbutton.h"
#include <QMouseEvent>
#include <QEvent>
#include <QPainter>

staticButton::staticButton(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground);// 设置窗口透明化
}

staticButton::staticButton(const QString &icon, int num,QWidget *parent)
    :QWidget(parent),m_num(num),m_isCursor(false)
{
    this->setAttribute(Qt::WA_TranslucentBackground); //设置窗口透明化
    QPixmap pixmap(icon);

    for(int i=0 ; i != m_num; i++ )
    {
        m_pixList.append(pixmap.copy(
                                     i*(pixmap.width()/m_num),
                                     0,
                                     pixmap.width()/m_num,
                                     pixmap.height())
                         ); //pixmap.copy(QRect)
    }
    m_currentPix = m_pixList.at(0);
    this->setFixedSize(m_currentPix.size());
}

staticButton::staticButton(const QString &icon, bool isDivision,int num,QWidget *parent)
                :QWidget(parent),m_num(num),m_isCursor(false)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    if(isDivision)
    {
        setDivisionButtonInfo(icon,num);
    }
    else
    {
        setOneButtonInfo(icon,num);
    }

}

void staticButton::setOneButtonInfo(const QString &icon, int num)
{
    m_num = num ;
    QPixmap pixmap(icon);
    if(m_pixList.size() != 0)
    {
        m_pixList.clear();
    }
    for(int i = 0 ; i != m_num ; i++)
    {
        m_pixList.append(pixmap.copy(i*(pixmap.width()/m_num),0,
                                     pixmap.width()/m_num,pixmap.height())
                         );
    }
    m_currentPix = m_pixList.at(0);
    this->setFixedSize(m_pixList.at(0).size());
}
void staticButton::setDivisionButtonInfo(const QString &icon, int num)
{
    m_pixList.append(QPixmap(icon + "_normal"));
    m_pixList.append(QPixmap(icon + "_hover"));
    m_pixList.append(QPixmap(icon + "_press"));
    if(num == 4)
        m_pixList.append(QPixmap(icon+"_disable"));
    m_num = num ;
    m_currentPix = m_pixList.at(0);
    this->setFixedSize(QPixmap(icon+"_normal").size());
}

void staticButton::setButtonStatus(BUTTONSTATUS status)
{
    if(this->isEnabled())
    {
        switch (status) {
            case BUTTON_ENTER:
                m_currentPix = m_pixList.at(1);
                break;
            case BUTTON_LEAVE:
                m_currentPix = m_pixList.at(0);
                break;
            case BUTTON_PRESSED:
                m_currentPix = m_pixList.at(2);
                break;
            default:
                break;
            }
    }else
    {
        if(m_num == 4)
            m_currentPix = m_pixList.at(3);
    }
    update();
}

void staticButton::enterEvent(QEvent *event)
{
    setButtonStatus(BUTTON_ENTER);
    if(m_isCursor)
    {
        m_preCursor = cursor();
        setCursor(Qt::OpenHandCursor);
    }
    emit enterSignal();
}

void staticButton::leaveEvent(QEvent *event)
{
    setButtonStatus(BUTTON_LEAVE);
    if(m_isCursor)
    {
        setCursor(m_preCursor);
    }
    emit leaveSignal();
}

void staticButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton )
    {
        event->ignore();
        return;
    }
    setButtonStatus(BUTTON_PRESSED);
}

void staticButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
    {
        event->ignore();
        return;
    }
    if(rect().contains(event->pos()))
    {
        if(this->isEnabled())
            emit buttonClicked();
        setButtonStatus(BUTTON_ENTER);
        event->accept();
    }
    else
    {
        setButtonStatus(BUTTON_LEAVE);
        event->ignore();
    }
}

void staticButton::changeEvent(QEvent *e)
{
    if(e->type() == QEvent::EnabledChange)
    {
        if(this->isEnabled() && (m_num == 4))
        {
            setButtonStatus(BUTTON_DISABLE);
        }
    }
}

void staticButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),m_currentPix);
}
