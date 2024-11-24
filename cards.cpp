#include "cards.h"
#include<QRandomGenerator>
Cards::Cards()
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
    return *this;
}
Cards& Cards::operator<<( Card &card)
{
    this->add(card);
    return *this;
}



void Cards::remove(Card &card)
{
    m_cards.remove(card);

}

void Cards::remove(Cards &cards)
{
    //subtract函数，做差集
    this->m_cards.subtract(cards.m_cards);
}

int Cards::cardCount()
{
    return m_cards.size();
}

bool Cards::isEmpty()
{
    return m_cards.isEmpty();
}

void Cards::clear()
{
    m_cards.clear();
}

Card::CardPoint Cards::maxPoint()
{
    Card::CardPoint max = Card::Card_Begin;
    if(m_cards.isEmpty())return max;
    for(auto&it:m_cards){
        if(it.point()>max){
            max = it.point();
        }
    }
    return max;
}

Card::CardPoint Cards::minPoint()
{
    Card::CardPoint min = Card::Card_End;
    if(m_cards.isEmpty())return min;
    for(auto&it:m_cards){
        if(it.point()<min){
            min = it.point();
        }
    }
    return min;

}

int Cards::pointCount(Card::CardPoint point)
{
    int count=0;
    for(auto&it:m_cards){
        if(it.point()==point){
            count++;
        }
    }
    return count;
}

bool Cards::contains(const Card &card)
{
    return m_cards.contains(card);
}

bool Cards::contains(const Cards &cards)
{
    return m_cards.contains(cards.m_cards);
}

Card Cards::takeRandomCard()
{
    int num = QRandomGenerator::global()->bounded(m_cards.size());//随机生成一个数 范围在牌的总数之间
    auto it = m_cards.constBegin();
    while(num--){
        it++;
    }
    Card ret = *it;
    m_cards.erase(it);
    return ret;
}

QVector<Card> Cards::toCardList()
{
    QVector<Card>list;
    for(auto it=m_cards.begin();it!=m_cards.end();it++){
        list.push_back(*it);
    }

    std::sort(list.begin(),list.end(),greaterSort);

    return list;

}


