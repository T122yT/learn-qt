#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);  原始的构造函数

    //重写构造函数
    MyPushButton(QString normalImage,QString pressImage = "");

    QString normalImagePath;//默认显示的图片
    QString pressImagePath;//按下后显示的图片

    //定义鼠标事件
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //弹跳特效
    void zoom1();//向下跳
    void zoom2();//向上跳

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
