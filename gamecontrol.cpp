#include "gamecontrol.h"

GameControl::GameControl(QObject *parent)
    : QObject{parent}
{}

void GameControl::playerInit()
{
    m_robotLeft = new Robot("机器人A",this);
    m_robotRight = new Robot("机器人B",this);
    m_user = new UserPlayer("自己",this);

    //头像显示方位
    m_robotLeft->setDirection(Player::Left);
    m_robotRight->setDirection(Player::right);
    m_user->setDirection(Player::right);

    //性别
    m_robotLeft->setSex(Player::Woman);
    m_robotRight->setSex(Player::Woman);
    m_user->setSex(Player::Man);

    //出牌顺序
    //user1
    m_user->setPrevPlayer(m_robotLeft);
    m_user->setNextPlayer(m_robotRight);
    //left robot
    m_robotLeft->setPrevPlayer(m_robotRight);
    m_robotLeft->setNextPlayer(m_user);
    //right robot
    m_robotRight->setPrevPlayer(m_user);
    m_robotRight->setNextPlayer(m_robotLeft);

    //当前玩家(开局谁先叫地主)
    m_currPlayer = m_user;

}

Robot *GameControl::getLeftRobot()
{
    return m_robotLeft;
}

Robot *GameControl::getRightRobot()
{
    return m_robotRight;
}

UserPlayer *GameControl::getUserPlayer()
{
    return m_user;
}

void GameControl::setCurrentPlayer(Player *player)
{
    m_currPlayer = player;
}

Player *GameControl::getCurrentPlayer()
{
    return m_currPlayer;
}

Player *GameControl::getPendPlayer()
{
    return m_pendPlayer;
}

Cards GameControl::getPendCards()
{
    return m_pendCards;
}

void GameControl::initAllCards()
{
    m_allCards.clear();
    for (int p = Card::Card_Begin+1; p < Card::card_smallJoker; ++p) {
        for (int s = Card::Suit_Begin+1; s < Card::Suit_End; ++s) {
            Card c(static_cast<Card::CardPoint>(p),static_cast<Card::CardSuit>(s));
            m_allCards.add(c);
        }
    }
    //大小王
    Card sj(Card::card_smallJoker,Card::Suit_Begin);
    m_allCards.add(sj);
    Card bj(Card::card_bigJoker,Card::Suit_End);
    m_allCards.add(bj);


}

Card GameControl::takeOneCard()
{
    return m_allCards.takeRandomCard();
}

Cards GameControl::getSurplusCards()
{
    //因为发到最后只剩三张牌了，三张存在m_allCards，直接返回它就好了
    return m_allCards;
}

void GameControl::resetCardData()
{
    initAllCards();
    //清空玩家的牌
    m_robotLeft->clearCards();
    m_robotRight->clearCards();
    m_user->clearCards();
    //初始化出牌玩家和牌
    m_pendCards.clear();
    m_pendPlayer=nullptr;

}

void GameControl::startLordCard()
{
    m_currPlayer->prepareCallLord();//当前玩家准备叫地主
}

void GameControl::becomeLord(Player*Lord)
{
    Lord->setRole(Player::Lord);
    Lord->getPrevPlayer()->setRole(Player::Farmer);
    Lord->getNextPlayer()->setRole(Player::Farmer);

    m_currPlayer = Lord;
    Lord->storeDispatchCard(m_allCards);

    m_currPlayer->preparePlayHand();//准备出牌
}

void GameControl::clearPlayerscore()
{
    m_user->setScore(0);
    m_robotLeft->setScore(0);
    m_robotRight->setScore(0);
}


