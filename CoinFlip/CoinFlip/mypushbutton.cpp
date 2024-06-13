#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
#include<QEasingCurve>

//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImage,QString pressImage)
{
    //成员变量normalImagePath保存正常显示图片路径
    normalImagePath = normalImage;
    //成员变量pressImagePath保存正常显示图片路径
    pressImagePath = pressImage;
    //创建QPixmap对象
    QPixmap pixmap;
    //判断是否能够加载正常显示的图片，若不能加载失败
    bool ret = pixmap.load(normalImage);
    if(!ret)
    {
        qDebug()<<normalImage<<"加载图片失败";
    }
    //设置button固定尺寸
    this->setFixedSize(pixmap.width(),pixmap.height());
    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pixmap);
    //设置图标最大尺寸（较小的图标将不会放大）
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

//向下跳
void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation *animation1 = new QPropertyAnimation(this,"geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),width(),height()));
    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y()+10,width(),height()));
    //设置缓和曲线，QEasingCure::OutBounce为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}
//向上跳
void MyPushButton::zoom2()
{
    //创建动画对象
    QPropertyAnimation *animation2 = new QPropertyAnimation(this,"geometry");
    animation2->setDuration(200);
    animation2->setStartValue(QRect(this->x(),this->y()+10,width(),height()));
    animation2->setEndValue(QRect(this->x(),this->y(),width(),height()));
    animation2->setEasingCurve(QEasingCurve::OutBounce);
    animation2->start();

}

void MyPushButton::mousePressEvent(QMouseEvent *event)
{
    if(pressImagePath != "")//选中路径不为空，显示选中图片
    {
        QPixmap pixmap;
        bool ret = pixmap.load(pressImagePath);
        if(!ret)
        {
            qDebug()<<pressImagePath<<"加载图片失败";
        }

        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    }
    //交给父类执行按下事件
    return QPushButton::mousePressEvent(event);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *event)
{
     if(normalImagePath != "") //选中路径不为空，显示选中图片
     {
        QPixmap pixmap;
        bool ret = pixmap.load(normalImagePath);
        if(!ret)
        {
            qDebug() << normalImagePath << "加载图片失败!";
        }
        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
     }
     //交给父类执行 释放事件
     return QPushButton::mouseReleaseEvent(event);
}
