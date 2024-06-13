#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QVector>
#include<QMessageBox>

namespace Ui {
class LogIn;
}

class LogIn : public QWidget
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();

private:
    Ui::LogIn *ui;
    //QVector<bool> IsShow;
};

#endif // LOGIN_H
