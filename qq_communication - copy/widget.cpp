#include "widget.h"
#include "ui_widget.h"
#include<QDataStream>
#include<QMessageBox>
#include<QDateTime>
#include<QTableWidget>
#include<QComboBox>
#include<QFont>
#include<QColorDialog>
#include<QFileDialog>
#include<QDebug>

Widget::Widget(QWidget *parent,QString name)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    myName = name;

    //初始化端口
    this->port = 9999;
    //new 套接字
    this->udpSocket = new QUdpSocket(this);
    //绑定端口
    //采用ShareAdress模式（即允许其他的服务器连接到相同的地址和端口，
    //特别是在多个客户端监听同一个服务器端口时特别有效），和ReuseAddressHint模式（重新链接服务器）
    udpSocket->bind(this->port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    //监听信号
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::receiveMessage);

    //链接发送按钮
    connect(ui->sendBtn,&QPushButton::clicked,[=](){
        //Msg为发送消息的枚举类型
        sendMsg(Msg);
    });

    //新用户进入
    sendMsg(UserEnter);

    //退出功能
    connect(ui->exitBtn,&QPushButton::clicked,[=](){
        this->close();
    });

    //字体
    connect(ui->wordStyle,&QFontComboBox::currentFontChanged,this,[=](const QFont &font){
        //设置全局字体
        ui->msgEdit->setFontFamily(font.toString());
        ui->msgEdit->setFocus();
    });

    //字体大小
    void (QComboBox:: *sizeBtn)(const QString &text)=&QComboBox::currentTextChanged;
    connect(ui->wordSize,sizeBtn,this,[=](const QString &text){
        ui->msgEdit->setFontPointSize(text.toDouble());
         ui->msgEdit->setFocus();
    });

    //加粗
    connect(ui->boldBtn,&QPushButton::clicked,this,[=](bool checked){
        //是否按下
        if(checked){
           ui->msgEdit->setFontWeight(QFont::Bold);
        }else{
            ui->msgEdit->setFontWeight(QFont::Normal);
        }
    });

    //倾斜
    connect(ui->italicBtn,&QPushButton::clicked,this,[=](bool checked){
        ui->msgEdit->setFontItalic(checked);
        ui->msgEdit->setFocus();
    });

    //下划线
    connect(ui->underlineBtn,&QPushButton::clicked,this,[=](bool checked){
        ui->msgEdit->setFontUnderline(checked);
        ui->msgEdit->setFocus();
    });

     //清空
    connect(ui->cleanBtn,&QPushButton::clicked,this,[=](){
        ui->msgBrowser->clear();
    });

    //字体颜色
    connect(ui->colorBtn,&QPushButton::clicked,this,[=](){
        QColor color=QColorDialog::getColor(color,this);
         ui->msgEdit->setTextColor(color);
    });

    //文件保存
    connect(ui->saveBtn,&QPushButton::clicked,[=](){
       if(ui->msgBrowser->document()->isEmpty())
       {
           QMessageBox::warning(this,"警告","保存内容不能为空！");
       }
       else
       {
           QString filename = QFileDialog::getSaveFileName(this,"保存聊天记录","聊天记录","(*.txt)");
           if(!filename.isEmpty())
           {
               //保存文件名不为空 在进行保存
               QFile file(filename);
               file.open(QIODevice::WriteOnly | QFile::Text);
               QTextStream stream(&file);
               stream<<ui->msgBrowser->toPlainText();
               file.close();
           }
           else
           {
               QMessageBox::warning(this,"警告","保存名称不能为空！");
           }
       }
    });

    //翻金币
    ui->coinBtn->setIcon(QPixmap(":/images/Coin.png"));
    connect(ui->coinBtn,&QPushButton::clicked,[=](){
        MainScene w;
        w.show();
    });
}

//获取名字
QString Widget::getName()
{
    return this->myName;
}

//获取聊天信息
QString Widget::getMsg()
{
    //返回输入框的内容
    QString msg = ui->msgEdit->toHtml();
    //将内容清空
    ui->msgEdit->clear();
    //设置光标
    ui->msgEdit->setFocus();
    return msg;
}

//广播udp信息
void Widget::sendMsg(Widget::Msgtype type)
{
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);

    stream<<type<<this->getName();

    switch(type)
    {
    case Msg:
        if(ui->msgEdit->toHtml()=="")
        {
            QMessageBox::warning(this,"警告","输入内容不能为空!");
            return;
        }
        stream<<this->getMsg();
        break;
    case UserEnter:
        break;
    case UserLeft:
        break;
    }
    //书写报文
    udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port);
}

//接收udp信息
void Widget::receiveMessage()
{
    //读取报文大小
    qint64 size=udpSocket->pendingDatagramSize();
    //qint64 类型转换为 int
    int mysize = static_cast<int>(size);
    //初始化接收矩阵
    QByteArray array = QByteArray(mysize,0);
    //读取报文
    udpSocket->readDatagram(array.data(),size);
    QDataStream stream(&array,QIODevice::ReadOnly);
    int msgtype;
    stream >> msgtype;//读取类型
    QString name,msg;//用户名，聊天信息
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    switch (msgtype)
    {
    case Msg://普通聊天
        stream>>name>>msg;//流出姓名和聊天内容

        //增加聊天记录
        ui->msgBrowser->setTextColor(Qt::blue);
        ui->msgBrowser->setCurrentFont(QFont("Times New Roman",12));
        ui->msgBrowser->append("["+name+"]"+time);
        ui->msgBrowser->append(msg);
        break;
    case UserEnter:
        stream>>name;
        userEnter(name);
        break;
    case UserLeft:
        stream>>name;
        userLeft(name,time);
        break;

    }
}

//用户进入
void Widget::userEnter(QString userName)
{
    bool isEmpty = ui->tableWidget->findItems(userName,Qt::MatchExactly).isEmpty();
    if(isEmpty)
    {
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,user);
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append(userName+"用户已上线");
        ui->NumLabel->setText(QString("在线人数：%1人").arg(ui->tableWidget->rowCount()));

        sendMsg(UserEnter);
    }
}

//用户退出
void Widget::userLeft(QString userName, QString time)
{
    bool isEmpty = ui->tableWidget->findItems(userName,Qt::MatchExactly).isEmpty();
    if(!isEmpty)
    {
        //寻找行
        int row = ui->tableWidget->findItems(userName,Qt::MatchExactly).first()->row();
        //移除该行
        ui->tableWidget->removeRow(row);

        //追加信息
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append(userName+"用户于"+time+"下线");
        ui->NumLabel->setText(QString("在线人数：%1人").arg(ui->tableWidget->rowCount()));
    }
}



void Widget::closeEvent(QCloseEvent *e)
{
    emit this->closeWidget();

    sendMsg(UserLeft);

    udpSocket->close();
    udpSocket->destroyed();
}

Widget::~Widget()
{
    delete ui;
}
