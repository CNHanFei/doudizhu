#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <QWidget>
#include<QPixmap>
#include"card.h"
#include"player.h"
class CardPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);
public:
    //设置图片
    void setImage(QPixmap &front,QPixmap &back);
    QPixmap getImage();

    //扑克牌显示那一面
    void setFrontSide(bool m_isfront);
    bool isFrontSide();

    //记录窗口有没有被选中
    void setSelected(bool flag);
    bool isSelected();

    //正面窗口显示的花色和点数
    void setCard(Card&card );
    Card getCard();

    //扑克牌的所有者
    void setOwner(Player*player);   //设置所有者
    Player* getOwner();  //获得所有者

protected:
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
private:
    QPixmap m_front;
    QPixmap m_back;

    bool m_isfront;
    bool m_isSelect;//记录是否被选中
    Card m_card;//记录窗口的花色和点数
    Player* m_owner;
signals:
};

#endif // CARDPANEL_H
