#ifndef CARDS_H
#define CARDS_H

#include <QWidget>
#include"card.h"
class Cards : public QWidget
{
    Q_OBJECT
public:
    explicit Cards(QWidget *parent = nullptr);
    void add(Card& card);//发一张牌时
    void add(Cards&cards);//发多张牌时
    //一次性插入多个数据（操作符重载 <<）
    Cards& operator<<( Card&card);
    Cards& operator<<( Cards&cards);

    void remove(Card& card);//出牌时
    void remove(Cards&cards);

private:
    QSet<Card>m_cards;//qt的set没有自动排序，要手动排序
signals:
};

#endif // CARDS_H
