#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include<QSound>


MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //设置固定大小
    this->setFixedSize(320*2,588*2);
    //设置应用图片
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置窗口标题
    this->setWindowTitle("CoinFlip");
    //退出功能
    connect(ui->actionquit,&QAction::triggered,[=](){this->close();});

    //准备开始音效
    QSound *startSound = new QSound(":/res/TapButtonSound.wav");

    //创建自定义的开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5,this->height()*0.7);

    //监听点击事件，执行特效
    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();

        startSound->play();//开始音效

        //延时0.5s后 进入选择场景
        QTimer::singleShot(500,this,[=](){
            //自身隐藏
            this->hide();
            //保持页面位置
            chooseScene->setGeometry(this->geometry());
            //显示选择关卡
            chooseScene->show();
        });
    });

    //监听到自定义的返回信号
    connect(chooseScene,&ChooseLevelScene::ChooseSceneBack,[=](){
        this->setGeometry(chooseScene->geometry());
        this->show();
    });
}


void MainScene::paintEvent(QPaintEvent *event)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/res/OtherSceneBg.png");
    //绘制背景图片
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    //缩放图片
    pix = pix.scaled(pix.width(),pix.height());
    //绘制标题
    painter.drawPixmap(30,50,pix.width(),pix.height(),pix);
}


MainScene::~MainScene()
{
    delete ui;
}

