#include "player.h"

Player::Player( QObject *parent)
    : QObject{parent}
{}

Player::Player(QString name, QObject *parent)
    : QObject{parent}
{
    m_name = name;
}


void Player::setName(QString name)
{
     m_name = name;
}

QString Player::getName()
{
    return m_name;
}

void Player::setRole(Role role)
{
    m_role = role;
}

Player::Role Player::getRole()
{
    return m_role;
}

void Player::setSex(Sex sex)
{
    m_sex = sex;
}

Player::Sex Player::getSex()
{
    return m_sex;
}

void Player::setDirection(Direction direction)
{
    m_direction = direction;
}

Player::Direction Player::getDirection()
{
    return m_direction;
}

void Player::setType(Type type)
{
    m_type = type;
}

Player::Type Player::getType()
{
    return m_type;
}

void Player::setScore(int score)
{
    m_score = score;
}

int Player::getScore()
{
    return m_score;
}

void Player::setIsWin(bool isWin)
{
    m_isWin = isWin;
}

bool Player::getIsWin()
{
    return m_isWin;
}

void Player::setPrevPlayer(Player *prePalyer)
{
    m_prevPlayer = prePalyer;
}

Player *Player::getPrevPlayer()
{
    return m_prevPlayer;
}

void Player::setNextPlayer(Player *nextPalyer)
{
    m_nextPlayer = nextPalyer;
}

Player *Player::getNextPlayer()
{
    return m_nextPlayer;
}

void Player::storeDispatchCard(Card &card)
{
    m_cards.add(card);
}

void Player::storeDispatchCard(Cards &cards)
{
    m_cards.add(cards);
}

Cards Player::getCards()
{
    return m_cards;
}

void Player::clearCards()
{
    m_cards.clear();
}

void Player::playHand(Cards &cards)
{
    m_cards.remove(cards);
}

void Player::setPendingInfo(Player *player, Cards &cards)
{
    m_pendPlayer = player;
    m_pendCards = cards;
}

Player *Player::getPendPlayer()
{
    return m_pendPlayer;
}

Cards Player::getPendCards()
{
    return m_pendCards;
}

void Player::prepareCallLord()
{

}

void Player::preparePlayHand()
{

}




