#include "mybutton.h"

#include <QMouseEvent>
#include <qpainter.h>

MyButton::MyButton(QWidget *parent)
    : QPushButton{parent}
{}

void MyButton::setImage(QString normal, QString hover, QString pressed)
{
    m_normal = normal;
    m_hover = hover;
    m_pressed = pressed;
    m_pixmap.load(normal);
    update();
}

void MyButton::enterEvent(QEvent *ev)
{
    m_pixmap.load(m_hover);
    update();
}

void MyButton::leaveEvent(QEvent *ev)
{
    m_pixmap.load(m_normal);
    update();
}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton){
        m_pixmap.load(m_pressed);
        update();
    }
    QPushButton::mousePressEvent(ev);//再次调用父类虚函数，发射原本的clicked信号
}

void MyButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton){
        m_pixmap.load(m_normal);
        update();
    }
}

void MyButton::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawPixmap(rect(),m_pixmap);//当前按钮的矩形区域

}
