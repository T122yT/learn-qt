#include "playscene.h"
#include<QDebug>
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include"mycoin.h"
#include"dataconfig.h"
#include<QPropertyAnimation>
#include<QSound>

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

PlayScene::PlayScene(int levelNum)
{
    //QString str = QString("进入了第%1关").arg(levelNum);
    //qDebug()<<str;

    this->levelIndex = levelNum;
    //设置窗口固定大小
    this->setFixedSize(320*2,588*2);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币");

    //创建菜单栏
    QMenuBar *bar = this->menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");
    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出，退出游戏
    connect(quitAction,&QAction::triggered,[=](){this->close();});

    //返回音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav");
    QSound *flipSound = new QSound(":/res/ConFlipSound.wav");
    QSound *winSound = new QSound(":/res/LevelWinSound.wav");

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

    //当前关卡标题
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("微软雅黑");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Level：%1").arg(this->levelIndex);
    label->setText(str);
    label->setGeometry(QRect(60,this->height()-100,300, 100)); //设置大小和位置

    //设置胜利图片
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());


    //初始化每个关卡的二维数组
    dataConfig config;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4;j++)
        {
            gameArray[i][j]= config.mData[this->levelIndex][i][j];
        }
    }

    //创建金币的背景图片
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            //绘制背景图片
            QLabel* label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(150 + i*100,400+j*100);

//            //创建金币对象（test）
//            MyCoin *coin = new MyCoin(":/res/Coin0001.png");
//            coin->setParent(this);
//            coin->move(152 + i*100,402+j*100);

            //创建金币对象
            QString img;
            if(gameArray[i][j]==1)
            {
                img = ":/res/Coin0001.png";
            }
            else
            {
                img = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(152 + i*100,402+j*100);
            coin->posX = i;//记录x坐标
            coin->posY = j;//记录y坐标
            coin->flag = gameArray[i][j];//记录正反标记

            //bug修复
            //设置当金币翻转时 禁止点击其他金币
            connect(coin,&MyCoin::clicked,[=](){
                for(int i = 0 ; i < 4;i++)
                {
                    for(int j = 0 ; j < 4; j++)
                    {
                        coinBtn[i][j]->isWin = true;
                    }
                }
            });

            //把金币放到二维数组中 以便后期维护
            coinBtn[i][j] = coin;
            //点击金币进行翻转
            connect(coin,&MyCoin::clicked,[=](){
                //音效
                flipSound->play();

                coin->changeFlag();
                gameArray[i][j] = gameArray[i][j] == 0?1:0;//数组内部记录标志的同步修改

                //延时翻转周围金币
                QTimer::singleShot(300,this,[=](){

                    if(coin->posX+1<=3)//周围的右侧金币翻转条件
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        gameArray[coin->posX+1][coin->posY] = gameArray[coin->posX+1][coin->posY] == 0?1:0;//数组内部记录标志的同步修改
                    }
                    if(coin->posX-1>=0)//周围的左侧金币翻转条件
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        gameArray[coin->posX-1][coin->posY] = gameArray[coin->posX-1][coin->posY] == 0?1:0;//数组内部记录标志的同步修改
                    }
                    if(coin->posY+1<=3)//周围的下侧金币翻转条件
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        gameArray[coin->posX][coin->posY+1] = gameArray[coin->posX][coin->posY+1] == 0?1:0;//数组内部记录标志的同步修改
                    }
                    if(coin->posY-1>=0)//周围的上侧金币翻转条件
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        gameArray[coin->posX][coin->posY-1] = gameArray[coin->posX][coin->posY-1] == 0?1:0;//数组内部记录标志的同步修改
                    }

                    //bug修复
                    //等待周围金币翻转完成，解除其他金币的禁用
                    for(int i = 0 ; i < 4;i++)
                    {
                        for(int j = 0 ; j < 4; j++)
                        {
                            coinBtn[i][j]->isWin = false;
                        }
                    }

                    //判断是否胜利
                    this->isWin = true;
                    for(int i = 0; i<4; i++)
                    {
                        for(int j = 0; j<4;j++)
                        {
                            if(coinBtn[i][j]->flag == false)//只要有一个反面 就算失败
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if(this->isWin == true)
                    {
                        //胜利音效
                        winSound->play();
                        //胜利了
                        qDebug()<<"胜利了";

                        //设置胜利状态，方便胜利后禁用按钮
                        for(int i = 0 ; i < 4;i++)
                        {
                            for(int j = 0 ; j < 4; j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }

                        //将胜利图片移动下来
                        QPropertyAnimation *animation = new QPropertyAnimation(winLabel,"geometry");
                        //设置时间间隔
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+214,winLabel->width(),winLabel->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });

            });
        }
    }

}

void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( 20,60,pix.width(),pix.height(),pix);
}
