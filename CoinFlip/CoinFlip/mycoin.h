#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include<QPushButton>
#include<QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString butImg);//代表图片路径

    int posX;//x坐标
    int posY;
    bool flag;//正反标志

    //金币翻转
    void changeFlag();//改变标志，执行翻转效果
    QTimer *timer1;//正面翻反面 定时器
    QTimer *timer2;//反面翻正面 定时器
    int min = 1;//最小图片
    int max = 8;//最大图片

    bool isAnimation = false;//做翻转动画的标志

    //重写按下
    void mousePressEvent(QMouseEvent * e);

    //胜利标志
    bool isWin = false;




signals:

public slots:
};

#endif // MYCOIN_H
