#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include"playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent * event);

    //创建游戏场景对象指针
    PlayScene * pScene = NULL;

signals:
    //写一个自定义的信号(只需要声明，不需要实现)，告诉主场景，点击了返回
    void ChooseSceneBack();

public slots:
};

#endif // CHOOSELEVELSCENE_H
