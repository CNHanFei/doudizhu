#include "cards.h"

Cards::Cards(QWidget *parent)
    : QWidget{parent}
{}

void Cards::add(Card &card)
{
    this->m_cards.insert(card);
}

void Cards::add(Cards &cards)
{
    // for(auto& card:m_cards){
    //     this->m_cards.insert(card);
    // }
    //直接调用QSet里的unite 取并集
    this->m_cards.unite(cards.m_cards);

}

Cards& Cards::operator<<( Cards &cards)
{
    this->add(cards);
}
Cards& Cards::operator<<( Card &card)
{
    this->add(card);
}



void Cards::remove(Card &card)
{
    this->m_cards.remove(card);
}

void Cards::remove(Cards &cards)
{
    //subtract函数，做差集
    this->m_cards.subtract(cards.m_cards);
}

