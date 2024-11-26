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

