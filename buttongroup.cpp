#include "buttongroup.h"
#include "ui_buttongroup.h"

ButtonGroup::ButtonGroup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ButtonGroup)
{
    ui->setupUi(this);
}

ButtonGroup::~ButtonGroup()
{
    delete ui;
}

void ButtonGroup::initButtons()
{
    //开始游戏
    ui->start->setImage(":/images/start-1.png",":/images/start-1.png",":/images/start-1.png");

    //出牌
    ui->playCard->setImage(":/images/chupai_btn-1.png",":/images/chupai_btn-2.png",":/images/chupai_btn-3.png");
    ui->playCard1->setImage(":/images/chupai_btn-1.png",":/images/chupai_btn-2.png",":/images/chupai_btn-3.png");
    //不要
    ui->pass->setImage(":/images/pass_btn-1.png",":/images/pass_btn-2.png",":/images/pass_btn-3.png");
    //不抢
    ui->giveUp->setImage(":/images/buqiang-1.png",":/images/buqiang-2.png",":/images/buqiang-3.png");
    //1，2，3分
    ui->one->setImage(":/images/1fen-1.png",":/images/1fen-2.png",":/images/1fen-3.png");
    ui->two->setImage(":/images/2fen-1.png",":/images/2fen-2.png",":/images/2fen-3.png");
    ui->three->setImage(":/images/3fen-1.png",":/images/3fen-2.png",":/images/3fen-3.png");
    //设置按钮大小
    QVector<MyButton*>btns;
    btns<<ui->start<< ui->playCard<< ui->playCard1<<ui->pass<<ui->giveUp<< ui->one<< ui->two<< ui->three;
    for(int i=0;i<btns.size();i++){
        btns[i]->setFixedSize(90,45);
    }
    connect(ui->start, &MyButton::clicked, this, &ButtonGroup::startGame);
    connect(ui->playCard, &MyButton::clicked, this, &ButtonGroup::playHand);
    connect(ui->playCard1, &MyButton::clicked, this, &ButtonGroup::playHand);
    connect(ui->pass, &MyButton::clicked, this, &ButtonGroup::pass);
    connect(ui->giveUp, &MyButton::clicked, this, [=]()
            {
                emit betPoint(0);
            });
    connect(ui->one, &MyButton::clicked, this, [=]()
            {
                emit betPoint(1);
            });
    connect(ui->two, &MyButton::clicked, this, [=]()
            {
                emit betPoint(2);
            });
    connect(ui->three, &MyButton::clicked, this, [=]()
            {
                emit betPoint(3);
            });

}


void ButtonGroup::selectPanel(Panel type)
{
    ui->stackedWidget->setCurrentIndex(type);
}
