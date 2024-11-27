#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QLabel>
#include <QMainWindow>
#include"gamecontrol.h"
#include"cardpanel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GamePanel;
}
QT_END_NAMESPACE

class GamePanel : public QMainWindow
{
    Q_OBJECT

public:
    GamePanel(QWidget *parent = nullptr);
    ~GamePanel();
    //初始化游戏控制类信息
    void GameControlInit();
    //更新分数面板
    void updatePlayScore();
    //切割并存储图片
    void initCardMap();
    //裁剪图片
    void cropImage(QPixmap&pix,int x,int y,Card& c);
    //初始化游戏按钮组
    void initButtonsGroup();
    //放牌位置初始化
    void initPlayerContext();

protected:
    void paintEvent(QPaintEvent *ev);

private:
    Ui::GamePanel *ui;

    QPixmap m_bkImage;
    GameControl*m_gameControl;
    QVector<Player*>m_playList;

    QMap<Card,CardPanel*>m_cardMap;
    QSize m_cardSize;
    QPixmap m_cardBackimage;
    enum CardAlign{Horizontal,Vertical};
    //结构体，存每个玩家的一些信息
    struct PlayerContext{
        //扑克牌显示区域
        QRect cardRect;
        //出牌的区域
        QRect playHandRect;
        //扑克牌对齐的方式（水平或垂直）
        CardAlign align;
        //牌显示正面还是背面
        bool isFrontSide;
        //提示信息，例如：不出。。。
        QLabel* info;
        //玩家头像
        QLabel* roleImg;
        //玩家刚打出的牌
        Cards lastCards;
    };
    QMap<Player*,PlayerContext>m_contextMap;

};
#endif // GAMEPANEL_H
