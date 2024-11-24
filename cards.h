#ifndef CARDS_H
#define CARDS_H

#include <QWidget>
#include"card.h"
class Cards
{
public:
    explicit Cards();
    void add(Card& card);//发一张牌时
    void add(Cards&cards);//发多张牌时
    //一次性插入多个数据（操作符重载 <<）
    Cards& operator<<( Card&card);
    Cards& operator<<( Cards&cards);

    void remove(Card& card);//出牌时
    void remove(Cards&cards);

    //扑克牌数量
    int cardCount();
    //手里有没有牌
    bool isEmpty();
    //清空手牌
    void clear();

    //手牌最大最小点数
    Card::CardPoint maxPoint();
    Card::CardPoint minPoint();

    //指定点数牌的数量
    int pointCount(Card::CardPoint point);

    //某张牌是否在集合中
    bool contains(const Card&card);
    bool contains(const Cards&cards);

    //随机发一张牌
    Card takeRandomCard();

    //vector<Card> 来存储手牌，用sort来排序
    QVector<Card>toCardList();

private:
    QSet<Card>m_cards;//qt的set没有自动排序，要手动排序

signals:
};

#endif // CARDS_H
