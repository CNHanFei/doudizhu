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

Card::CardPoint Card::Point()
{
    return m_point;
}

Card::CardSuit Card::Suit()
{
    return m_suit;
}



