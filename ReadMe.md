# 1.自定义按钮类MyButton

这个类主要是有个设置图片路径函数，再通过pixmap.load加载图片，重载了几个事件

- `setImage(QString normal,QString hover,QString pressed);`

- `enterEvent(QEvent *ev);`

- `leaveEvent(QEvent *ev);`
- `mousePressEvent(QMouseEvent *ev);`
- ` mouseReleaseEvent(QMouseEvent *ev);`
- `paintEvent(QPaintEvent*ev);`

在触发事件的时候，通过pixmap.load加载不同的图片，再用QPainter绘制出来

**在mousePressEvent函数中，最后用QPushButton::mousePressEvent(ev);//再次调用父类虚函数，发射原本的clicked信号**

# 2. 按钮组窗口ButtonGroup

ButtonGroup通过stackedWidget来设置多个不同页面

这个类主要是初始化按钮，栈窗口切换功能

在ui里选择用stackedWidget作为面板，给每个page里添加pushbutton然后把pushbutton提升为MyButton类，这样就可以调用MyButton的setImage方法来给每个按钮设置图片

- `void initButtons();`
- `void selectPanel(Panel type);`  Panel枚举值，通过stackedWidget的setCurrentIndex函数来选择加载哪个子页面

initButtons函数里主要是对每个按钮设置图片

```c++
	//开始游戏
	ui->start->setImage(":/images/start-1.png",":/images/start-1.png",":/images/start-1.png");

    //出牌
    ui->playCard->setImage(":/images/chupai_btn-1.png",":/images/chupai_btn-2.png",":/images/chupai_btn-3.png");
    ui->playCard1->setImage(":/images/chupai_btn-1.png",":/images/chupai_btn-2.png",":/images/chupai_btn-3.png")
```

**在完成这个类的编写后，在主界面添加一个widget，然后提升为ButtonGroup**，然后在主界面的cpp文件中调用initButtons方法就完成了重新启动自动初始化的功能

```
 	ui->btnGroup->initButtons();
    ui->btnGroup->selectPanel(ButtonGroup::Start);
```

# 3.游戏面板类GamePanel

类中GameControlInit函数实例化了三个玩家（通过gameControl的getxxxplayer）

initPlayerContext函数初始化放牌位置，
先是用三个数组记录三个玩家的各个位置

```c++
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


```

在类中定义结构体，用来存储每个玩家的各种信息

```
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
```

通过for循环来对三个玩家进行初始化，然后把结构体信息保存到map里，key是玩家Player类，value是context结构体，这样通过key—value就可以知道玩家的所有信息了

```
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
```

