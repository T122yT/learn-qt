#include "login.h"
#include "ui_login.h"
#include<QToolButton>
#include<widget.h>
#include<QMessageBox>

LogIn::LogIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    //设置图标
    this->setWindowIcon(QIcon(":/images/qq.png"));
    //设置名称
    this->setWindowTitle("qq 2024");
    //用户名列表
    QStringList list;
    list<<"Mike"<<"Tom"<<"Alice"<<"Jim"<<"Ammy"<<"Judy"<<"Ben"<<"Sandy"<<"Tonny";
    //图片资源列表
    QStringList listIcon;
    listIcon<<"spqy"<<"ymrl"<<"qq"<<"Cherry"<<"dr"<<"jj"<<"lswh"<<"qmnn"<<"spqy";


    QVector<QToolButton *>vector;
    for(int i=0;i<9;i++)
    {
        QToolButton *btn = new QToolButton(this);
        //加载图标，网名
        btn->setIcon(QPixmap(QString(":/images/%1.png").arg(listIcon[i])));
        btn->setIconSize(QPixmap(QString(":/images/%1.png").arg(listIcon[i])).size());
        btn->setText(QString("%1").arg(list[i]));
        //设置背景透明
        btn->setAutoRaise(true);
        //设置显示格式
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        //添加到layout布局中
        ui->vlayout->addWidget(btn);
        vector.push_back(btn);
//        IsShow.push_back(false);
    }
    for(int i=0;i<9;i++)
    {
        connect(vector[i],&QToolButton::clicked,[=](){
//            if(IsShow[i])
//            {
//                QMessageBox::warning(this,"警告","该聊天框已被打开");
//                return;
//            }
//            IsShow[i] = true;
            Widget *widget = new Widget(nullptr,vector[i]->text());
            widget->setWindowIcon(vector[i]->icon());
            widget->setWindowTitle(vector[i]->text());
            widget->setFixedSize(1200,800);
            widget->show();
//            //聊天关闭时，将对应的isshow便为false
//            connect(widget,&Widget::closeWidget,this,[=](){
//                isShow[i] = false;
//            });

        });
    }

}

LogIn::~LogIn()
{
    delete ui;
}
