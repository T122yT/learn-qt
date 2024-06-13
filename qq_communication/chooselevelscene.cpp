#include "chooselevelscene.h"
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include<QLabel>
#include"playscene.h"
#include<QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //设置窗口固定大小
    this->setFixedSize(320*2,588*2);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡");

    //创建菜单栏
    QMenuBar *bar = this->menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");
    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出，退出游戏
    connect(quitAction,&QAction::triggered,[=](){this->close();});

    //选择关卡音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav");
    QSound *backSound = new QSound(":/res/BackButtonSound.wav");

    //创建返回按钮
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width()-20,this->height()-backBtn->height()-20);

    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){

        //播放返回音效
        backSound->play();

        //qDebug()<<"点击返回";
        //延时500ms，告诉主场景，返回了
        QTimer::singleShot(500,this,[=](){
            this->hide();
            //发送自定义信号，关闭自身，该信号写到 signals 下做声明
            emit this->ChooseSceneBack();
        });
    });

    for(int i = 0; i<20; i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(80+(i%4)*140,260+(i/4)*140);

        //显示按钮上的文字
        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->size());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //设置居中
        label->move(80+(i%4)*140,260+(i/4)*140);
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true); //鼠标事件穿透(按到label下面的按钮)

        connect(menuBtn,&MyPushButton::clicked,[=](){
            //qDebug()<<i;
            if(pScene == NULL)
            {
                //进入游戏场景
                this->hide();//隐藏选关场景
                pScene = new PlayScene(i+1);//创建游戏场景
                pScene->setGeometry(this->geometry());
                pScene->show();

                //播放选择音效
                chooseSound->play();

                //监听 PlayScene 的返回信号，删除该scene并且将指针指向空
                connect(pScene,&PlayScene::ChooseSceneBack,[=](){
                    this->setGeometry(pScene->geometry());
                    this->show();
                    delete pScene;
                    pScene = NULL;
                });
            }
        });

    }

}

void ChooseLevelScene::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width()-pix.width())*0.5,60,pix.width(),pix.height(),pix);
}
