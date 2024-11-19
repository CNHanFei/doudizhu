#include "cardpanel.h"

#include <QPainter>

CardPanel::CardPanel(QWidget *parent)
    : QWidget{parent}
{
    m_isfront=true;
}

void CardPanel::setImage(QPixmap &front, QPixmap &back)
{
    this->m_front = front;
    this->m_back = back;

    this->setFixedSize(m_front.size()); //根据传入的图片大小来设置窗口的大小

    update();//每次setImage时候更新paintEvent
}

QPixmap CardPanel::getImage()
{
    return m_front;
}

void CardPanel::setFrontSide(bool m_isfront)
{
    this->m_isfront = m_isfront;
}

bool CardPanel::isFrontSide()
{
    return this->m_isfront;
}

void CardPanel::setSelected(bool flag)
{
    this->m_isSelect = flag;
}

bool CardPanel::isSelected()
{
    return m_isSelect;
}

void CardPanel::setCard(Card &card)
{
    this->m_card = card;
}

Card CardPanel::getCard()
{
    return m_card;
}

void CardPanel::setOwner(Player *player)
{
    this->m_owner = player;
}

Player *CardPanel::getOwner()
{
    return this->m_owner;
}

void CardPanel::paintEvent(QPaintEvent *ev)
{
    QPainter p;
    if(m_isfront){
        p.drawPixmap(rect(),m_front);
    }
    else{
         p.drawPixmap(rect(),m_back);
    }


}
