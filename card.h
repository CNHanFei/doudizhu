#ifndef CARD_H
#define CARD_H
#include <QHash>
class Card
{
public:
    Card();

    //花色
    enum CardSuit{
        Suit_Begin,
        FangKuai,
        MeiHua,
        HongTao,
        HeiTao,
        Suit_End
    };

    //点数
    enum CardPoint{
        Card_Begin,
        card_3,
        card_4,
        card_5,
        card_6,
        card_7,
        card_8,
        card_9,
        card_10,
        card_J,
        card_Q,
        card_K,
        card_A,
        card_2,
        card_smallJoker,
        card_bigJoker,
        Card_End
    };

    bool operator==(const Card&other)const{
        return m_suit==other.m_suit&&m_point==other.m_point;
    }

    void setPoint(CardPoint point);
    void setSuit(CardSuit suit);
    CardPoint point()const;
    CardSuit suit()const;
private:
    CardSuit m_suit;  //花色变量，枚举类型
    CardPoint m_point;    //点数变量，枚举类型
};
inline uint qHash(const Card &card, uint seed = 0) {
    return qHash(card.suit(), seed) ^ qHash(card.point(), seed); // 使用现有的qHash来生成哈希值
}

#endif // CARD_H
