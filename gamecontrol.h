#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include"Userplayer.h"
#include"robot.h"
#include"cards.h"
class GameControl : public QObject
{
    Q_OBJECT
public:
    //游戏状态
    enum GameStatus{
        DispatchCard,
        CallingLord,
        PlayingHand
    };
    //玩家状态
    enum PlayerStatus{
        ThinkingForCallLord,
        ThinkingForPlayHand,
        Winning
    };


    explicit GameControl(QObject *parent = nullptr);

    //初始化玩家
    void playerInit();
    //得到玩家的实例对象
    Robot* getLeftRobot();
    Robot* getRightRobot();
    UserPlayer* getUserPlayer();
    //当前玩家
    void setCurrentPlayer(Player*player);
    Player*getCurrentPlayer();
    //出牌玩家和打出的牌
    Player*getPendPlayer();
    Cards getPendCards();

    //初始化扑克牌
    void initAllCards();
    //发一张牌
    Card takeOneCard();
    //得到最后三张牌
    Cards getSurplusCards();
    //重置卡牌数据
    void resetCardData();

    //准备叫地主
    void startLordCard();
    //成为地主
    void becomeLord(Player*Lord);
    //清空所有玩家得分
    void clearPlayerscore();


private:
    Robot*m_robotLeft;
    Robot*m_robotRight;
    UserPlayer*m_user;
    Player*m_currPlayer;
    Cards m_pendCards;  //出牌的玩家 ！=当前玩家，上家出的牌或者上上家出的牌
    Player*m_pendPlayer;//打出的牌
    Cards m_allCards;//一副牌

signals:
};

#endif // GAMECONTROL_H
