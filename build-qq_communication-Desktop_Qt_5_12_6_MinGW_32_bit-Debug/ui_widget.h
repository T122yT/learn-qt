/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *msgBrowser;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *wordStyle;
    QComboBox *wordSize;
    QPushButton *boldBtn;
    QPushButton *italicBtn;
    QPushButton *underlineBtn;
    QPushButton *colorBtn;
    QPushButton *saveBtn;
    QPushButton *cleanBtn;
    QPushButton *coinBtn;
    QTextEdit *msgEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sendBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *NumLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(957, 611);
        horizontalLayout_5 = new QHBoxLayout(Widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, 9, 9, 9);
        widget_4 = new QWidget(Widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setEnabled(true);
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        msgBrowser = new QTextBrowser(widget_2);
        msgBrowser->setObjectName(QString::fromUtf8("msgBrowser"));

        verticalLayout->addWidget(msgBrowser);


        verticalLayout_2->addWidget(widget_2);

        frame_2 = new QFrame(widget_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wordStyle = new QFontComboBox(frame_2);
        wordStyle->setObjectName(QString::fromUtf8("wordStyle"));

        horizontalLayout->addWidget(wordStyle);

        wordSize = new QComboBox(frame_2);
        wordSize->addItem(QString());
        wordSize->addItem(QString());
        wordSize->addItem(QString());
        wordSize->addItem(QString());
        wordSize->addItem(QString());
        wordSize->addItem(QString());
        wordSize->addItem(QString());
        wordSize->addItem(QString());
        wordSize->setObjectName(QString::fromUtf8("wordSize"));

        horizontalLayout->addWidget(wordSize);

        boldBtn = new QPushButton(frame_2);
        boldBtn->setObjectName(QString::fromUtf8("boldBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldBtn->setIcon(icon);
        boldBtn->setCheckable(true);

        horizontalLayout->addWidget(boldBtn);

        italicBtn = new QPushButton(frame_2);
        italicBtn->setObjectName(QString::fromUtf8("italicBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicBtn->setIcon(icon1);
        italicBtn->setCheckable(true);

        horizontalLayout->addWidget(italicBtn);

        underlineBtn = new QPushButton(frame_2);
        underlineBtn->setObjectName(QString::fromUtf8("underlineBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineBtn->setIcon(icon2);
        underlineBtn->setCheckable(true);

        horizontalLayout->addWidget(underlineBtn);

        colorBtn = new QPushButton(frame_2);
        colorBtn->setObjectName(QString::fromUtf8("colorBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorBtn->setIcon(icon3);

        horizontalLayout->addWidget(colorBtn);

        saveBtn = new QPushButton(frame_2);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveBtn->setIcon(icon4);

        horizontalLayout->addWidget(saveBtn);

        cleanBtn = new QPushButton(frame_2);
        cleanBtn->setObjectName(QString::fromUtf8("cleanBtn"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        cleanBtn->setIcon(icon5);

        horizontalLayout->addWidget(cleanBtn);

        coinBtn = new QPushButton(frame_2);
        coinBtn->setObjectName(QString::fromUtf8("coinBtn"));

        horizontalLayout->addWidget(coinBtn);


        verticalLayout_2->addWidget(frame_2);

        msgEdit = new QTextEdit(widget_3);
        msgEdit->setObjectName(QString::fromUtf8("msgEdit"));
        msgEdit->setMinimumSize(QSize(0, 100));

        verticalLayout_2->addWidget(msgEdit);

        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        sendBtn = new QPushButton(widget);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout_2->addWidget(sendBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        NumLabel = new QLabel(widget);
        NumLabel->setObjectName(QString::fromUtf8("NumLabel"));

        horizontalLayout_2->addWidget(NumLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(widget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout_2->addWidget(exitBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget);


        horizontalLayout_3->addWidget(widget_3);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget_5);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout_4->addWidget(tableWidget);


        horizontalLayout_3->addWidget(widget_5);


        horizontalLayout_5->addWidget(widget_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        wordSize->setItemText(0, QApplication::translate("Widget", "5", nullptr));
        wordSize->setItemText(1, QApplication::translate("Widget", "6", nullptr));
        wordSize->setItemText(2, QApplication::translate("Widget", "7", nullptr));
        wordSize->setItemText(3, QApplication::translate("Widget", "8", nullptr));
        wordSize->setItemText(4, QApplication::translate("Widget", "9", nullptr));
        wordSize->setItemText(5, QApplication::translate("Widget", "10", nullptr));
        wordSize->setItemText(6, QApplication::translate("Widget", "11", nullptr));
        wordSize->setItemText(7, QApplication::translate("Widget", "12", nullptr));

#ifndef QT_NO_TOOLTIP
        boldBtn->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        boldBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        italicBtn->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        italicBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        underlineBtn->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        underlineBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        colorBtn->setToolTip(QApplication::translate("Widget", "\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        colorBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveBtn->setToolTip(QApplication::translate("Widget", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
        saveBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        cleanBtn->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
#endif // QT_NO_TOOLTIP
        cleanBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        coinBtn->setToolTip(QApplication::translate("Widget", "\347\277\273\351\207\221\345\270\201", nullptr));
#endif // QT_NO_TOOLTIP
        coinBtn->setText(QString());
        sendBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        NumLabel->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\344\272\272\346\225\260:0\344\272\272", nullptr));
        exitBtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
