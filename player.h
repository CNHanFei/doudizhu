#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "cards.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    explicit Player(QString name,QObject *parent = nullptr);
    //地主，农民
    enum Role{
        Lord,
        Farmer
    };
    enum Sex{
        Man,
        Woman
    };
    //头像朝向
    enum Direction{
        Left,
        right
    };
    enum Type{
        Robot,User,Unknow
    };


    void setName(QString name);
    QString getName();
    //角色
    void setRole(Role role);
    Role getRole();
    //性别
    void setSex(Sex sex);
    Sex getSex();
    //显示方位
    void setDirection(Direction direction);
    Direction getDirection();
    //玩家类型
    void setType(Type type);
    Type getType();
    //分数
    void setScore(int score);
    int getScore();
    //输还是赢
    void setIsWin(bool isWin);
    bool getIsWin();
    //提供对象是上下家
    void setPrevPlayer(Player* prePalyer);
    Player* getPrevPlayer();
    void setNextPlayer(Player* nextPalyer);
    Player* getNextPlayer();

    //叫地主抢地主
    void graLordBet(int point);

    //发牌的时候拿到的手牌
    void storeDispatchCard(Card& card);
    void storeDispatchCard(Cards& cards);
    //得到所有牌
    Cards getCards();
    //清空手牌
    void clearCards();
    //出牌
    void playHand(Cards&cards);

    void setPendingInfo(Player*player,Cards&cards);
    Player *getPendPlayer();
    Cards getPendCards();


    //虚函数
    virtual void prepareCallLord();
    virtual void preparePlayHand();

//子类要用，不能设为私有的
protected:
    QString m_name;
    Role m_role;
    Sex m_sex;
    Direction m_direction;
    Type m_type;
    int m_score;
    bool m_isWin;
    Player* m_prevPlayer; //上家
    Player* m_nextPlayer; //下家
    Cards m_cards;//手牌
    Player* m_pendPlayer;   // 刚出完牌的用户
    Cards m_pendCards;      // 用户刚打出的牌

signals:
};

#endif // PLAYER_H
