#ifndef CARD_H
#define CARD_H

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

    void setPoint(CardPoint point);
    void setSuit(CardSuit suit);
    CardPoint Point();
    CardSuit Suit();
private:
    CardSuit m_suit;  //花色变量，枚举类型
    CardPoint m_point;    //点数变量，枚举类型
};

#endif // CARD_H
