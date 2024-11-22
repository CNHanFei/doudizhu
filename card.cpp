#include "card.h"



Card::Card() {


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



