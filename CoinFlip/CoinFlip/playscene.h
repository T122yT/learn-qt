#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include<QPaintEvent>
#include"mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int levelNum);

    int levelIndex;//内部成员属性，记录所选的关卡

    void paintEvent(QPaintEvent *event);

    int gameArray[4][4];//二维数组数据

    //金币按钮数组
    MyCoin *coinBtn[4][4];

    //胜利标志
    bool isWin = true;

signals:
    void ChooseSceneBack();

public slots:
};

#endif // PLAYSCENE_H
