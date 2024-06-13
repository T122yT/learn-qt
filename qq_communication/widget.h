#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent,QString name);
    ~Widget();

    //枚举 分别代表 普遍信息 用户进入 用户离开
    enum Msgtype{Msg,UserEnter,UserLeft};
    //广播udp信息
    void sendMsg(Msgtype type);
    //获取名字
    QString getName();
    //获取聊天信息
    QString getMsg();
    //处理用户进入
    void userEnter(QString userName);
    //处理用户离开
    void userLeft(QString userName,QString time);
    //接收udp信息
    void receiveMessage();


    //重写关闭事件
    void closeEvent(QCloseEvent *e);

signals:

    void closeWidget();
    void openCoin();



private:
    Ui::Widget *ui;
    //名字
    QString myName;
    //端口
    quint16 port;
    //udp套接字
    QUdpSocket *udpSocket;
};
#endif // WIDGET_H
