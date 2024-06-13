#ifndef QCUSTOMPLOTWIDGET_H
#define QCUSTOMPLOTWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class qCustomPlotWidget; }
QT_END_NAMESPACE

class qCustomPlotWidget : public QWidget
{
    Q_OBJECT

public:
    qCustomPlotWidget(QWidget *parent = nullptr);
    ~qCustomPlotWidget();

private:
    Ui::qCustomPlotWidget *ui;
};
#endif // QCUSTOMPLOTWIDGET_H
