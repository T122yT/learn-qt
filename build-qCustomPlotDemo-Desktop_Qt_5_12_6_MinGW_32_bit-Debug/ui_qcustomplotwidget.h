/********************************************************************************
** Form generated from reading UI file 'qcustomplotwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCUSTOMPLOTWIDGET_H
#define UI_QCUSTOMPLOTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_qCustomPlotWidget
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *customPlot;

    void setupUi(QWidget *qCustomPlotWidget)
    {
        if (qCustomPlotWidget->objectName().isEmpty())
            qCustomPlotWidget->setObjectName(QString::fromUtf8("qCustomPlotWidget"));
        qCustomPlotWidget->resize(800, 600);
        gridLayout = new QGridLayout(qCustomPlotWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        customPlot = new QCustomPlot(qCustomPlotWidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        gridLayout->addWidget(customPlot, 0, 0, 1, 1);


        retranslateUi(qCustomPlotWidget);

        QMetaObject::connectSlotsByName(qCustomPlotWidget);
    } // setupUi

    void retranslateUi(QWidget *qCustomPlotWidget)
    {
        qCustomPlotWidget->setWindowTitle(QApplication::translate("qCustomPlotWidget", "qCustomPlotWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qCustomPlotWidget: public Ui_qCustomPlotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCUSTOMPLOTWIDGET_H
