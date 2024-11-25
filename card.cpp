#include "card.h"



Card::Card() {


}

Card::Card(CardPoint point, CardSuit suit)
{
    setPoint(point);
    setSuit(suit);
}

void Card::setPoint(CardPoint point)
{
    this->m_point =point;
}

void Card::setSuit(CardSuit suit)
{
    this->m_suit = suit;
}

Card::CardPoint Card::point()const
{
    return m_point;
}

Card::CardSuit Card::suit()const
{
    return m_suit;
}






bool greaterSort(Card c1, Card c2){
    if(c1.point()==c2.point()){
        return c1.suit()>c2.suit();
    }
    return c1.point()>c2.point();

}
