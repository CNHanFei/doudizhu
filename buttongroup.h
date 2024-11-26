#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <QWidget>

namespace Ui {
class ButtonGroup;
}

class ButtonGroup : public QWidget
{
    Q_OBJECT

public:
    enum Panel{
      Start,PlayCard,PassOrPlay,CallLord,Empty
    };
    explicit ButtonGroup(QWidget *parent = nullptr);
    ~ButtonGroup();

    //初始化按钮
    void initButtons();
    //栈窗口的page页切换
    void selectPanel(Panel type);

private:
    Ui::ButtonGroup *ui;

signals:
    //开始游戏
    void startGame();
    //抢地主
    void betPoint(int bet);
    //出牌
    void playHand();
    //不出牌
    void pass();
};

#endif // BUTTONGROUP_H
