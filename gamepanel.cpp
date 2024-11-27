#include "gamepanel.h"
#include "./ui_gamepanel.h"

#include <QPainter>
#include<QRandomGenerator>

GamePanel::GamePanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GamePanel)
{
    ui->setupUi(this);



    //背景图
    int num = QRandomGenerator::global()->bounded(10);
    QString path = QString(":/images/background-%1.png").arg(num);
    m_bkImage.load(path);
    //标题和大小（固定的）
    this->setWindowTitle("斗地主");
    this->setFixedSize(1560,980);
    //游戏控制类实例化
    GameControlInit();

    //初始化玩家的得分(更新)
    updatePlayScore();

    //扑克牌初始化，图片切割
    initCardMap();
    //初始化按钮
    initButtonsGroup();
    //初始化玩家在窗口的上下文环境
    initPlayerContext();



}

GamePanel::~GamePanel()
{
    delete ui;
}

void GamePanel::GameControlInit()
{
    m_gameControl = new GameControl(this);  //指定父对象，利用对象树自动析构
    m_gameControl->playerInit();
    //三个玩家实例
    Robot *leftRobot = m_gameControl->getLeftRobot();
    Robot *rightRobot = m_gameControl->getRightRobot();
    UserPlayer*user=m_gameControl->getUserPlayer();
    //顺序固定好，左 右 玩家
    m_playList<<leftRobot<<rightRobot<<user;
}

void GamePanel::updatePlayScore()
{
    ui->scorePanel->setScore(m_playList[0]->getScore(),m_playList[1]->getScore(),m_playList[2]->getScore());
}

void GamePanel::initCardMap()
{
    //加载大图
    QPixmap pixmap(":/images/card.png");
    //计算每张图片大小
    m_cardSize.setWidth(pixmap.width()/13);
    m_cardSize.setHeight(pixmap.height()/5);

    //背景图
    m_cardBackimage = pixmap.copy(2*m_cardSize.width(),4*m_cardSize.height(),m_cardSize.width(),m_cardSize.height());

    //花色
    for(int i=0, suit=Card::Suit_Begin+1; suit<Card::Suit_End; ++suit, ++i)
    {
        for(int j=0, pt=Card::Card_Begin+1; pt<Card::card_smallJoker; ++pt, ++j)
        {
            Card card((Card::CardPoint)pt, (Card::CardSuit)suit);
            // 裁剪图片
            cropImage(pixmap, j*m_cardSize.width(), i*m_cardSize.height(), card);
        }
    }
    //大小王
    Card c;
    c.setPoint(Card::card_smallJoker);
    c.setSuit(Card::Suit_Begin);
    cropImage(pixmap, 0, 4*m_cardSize.height(), c);

    c.setPoint(Card::card_bigJoker);
    cropImage(pixmap, m_cardSize.width(), 4*m_cardSize.height(), c);

}

void GamePanel::cropImage(QPixmap &pix, int x, int y, Card &c)
{
    QPixmap sub = pix.copy(x, y, m_cardSize.width(), m_cardSize.height());
    CardPanel* panel = new CardPanel(this);
    panel->setImage(sub, m_cardBackimage);
    panel->setCard(c);
    panel->hide();
    m_cardMap.insert(c, panel);

}

void GamePanel::initButtonsGroup()
{
    ui->btnGroup->initButtons();
    ui->btnGroup->selectPanel(ButtonGroup::Start);
    connect(ui->btnGroup,&ButtonGroup::startGame,this,[](){});
    connect(ui->btnGroup,&ButtonGroup::playHand,this,[](){});
    connect(ui->btnGroup,&ButtonGroup::pass,this,[](){});
    connect(ui->btnGroup,&ButtonGroup::betPoint,this,[](){});

}

void GamePanel::initPlayerContext()
{
    //每个玩家放置扑克牌的区域
    QRect cardsRect[]={
        QRect(90,130,100,height()-200),//左侧机器人
        QRect(rect().right()-190,130,100,height()-200),//右侧机器人
        QRect(250,rect().bottom()-120,width()-500,100)//user

    };
    //玩家出牌区域
    QRect playHandRect[]={
        QRect(260,150,100,100),//左侧机器人
        QRect(rect().right()-360,150,100,100),//右侧机器人
        QRect(150,rect().bottom()-290,width()-300,100)//user
    };

    //头像显示位置
    QPoint roleImgPos[]={
        QPoint(cardsRect[0].left()-80,cardsRect[0].height()/2+20),//左侧机器人
        QPoint(cardsRect[1].right()+10,cardsRect[1].height()/2+20),//右侧机器人
        QPoint(cardsRect[2].right()-10,cardsRect[2].top()-10)//user
    };

    int index = m_playList.indexOf(m_gameControl->getUserPlayer());
    for (int i = 0; i <m_playList.size() ; ++i) {
        PlayerContext context;
        //非机器人玩家垂直排列，机器人玩家水平排列
        context.align = i==index?Horizontal:Vertical;
        context.isFrontSide = i==index?true:false;
        context.cardRect = cardsRect[i];
        context.playHandRect = playHandRect[i];
        //提示信息
        context.info = new QLabel(this);
        context.info->resize(160,98);
        context.info->hide();
        //显示到出牌区域中中心位置
        QRect rect = playHandRect[i];
        QPoint pt(rect.left()+(rect.width()-context.info->width())/2,
                  rect.top()+(rect.height()-context.info->height())/2);
        context.info->move(pt);
        //玩家头像
        context.roleImg = new QLabel(this);
        context.roleImg->resize(84,120);
        context.roleImg->hide();
        context.roleImg->move(roleImgPos[i]);
        m_contextMap.insert(m_playList.at(i),context);
    }
}


void GamePanel::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawPixmap(rect(),m_bkImage);
}
