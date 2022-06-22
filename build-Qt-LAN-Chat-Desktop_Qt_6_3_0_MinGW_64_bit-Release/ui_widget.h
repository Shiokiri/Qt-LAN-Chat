/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextBrowser *messageBrowser;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QToolButton *boldToolBtn;
    QToolButton *italicToolBtn;
    QToolButton *underlineToolBtn;
    QToolButton *colorToolBtn;
    QToolButton *sendToolBtn;
    QToolButton *saveToolBtn;
    QToolButton *clearToolBtn;
    QTextEdit *messageTextEdit;
    QTableWidget *userTableWidget;
    QPushButton *sendButton;
    QLabel *userNumLabel;
    QPushButton *exitButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1000, 600);
        messageBrowser = new QTextBrowser(Widget);
        messageBrowser->setObjectName(QString::fromUtf8("messageBrowser"));
        messageBrowser->setGeometry(QRect(10, 10, 661, 361));
        fontComboBox = new QFontComboBox(Widget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(10, 380, 161, 31));
        sizeComboBox = new QComboBox(Widget);
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));
        sizeComboBox->setGeometry(QRect(180, 380, 61, 31));
        boldToolBtn = new QToolButton(Widget);
        boldToolBtn->setObjectName(QString::fromUtf8("boldToolBtn"));
        boldToolBtn->setGeometry(QRect(250, 380, 30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/bold.svg"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon);
        boldToolBtn->setIconSize(QSize(22, 22));
        boldToolBtn->setCheckable(true);
        boldToolBtn->setAutoRaise(true);
        italicToolBtn = new QToolButton(Widget);
        italicToolBtn->setObjectName(QString::fromUtf8("italicToolBtn"));
        italicToolBtn->setGeometry(QRect(290, 380, 30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/italic.svg"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon1);
        italicToolBtn->setIconSize(QSize(22, 22));
        italicToolBtn->setCheckable(true);
        italicToolBtn->setAutoRaise(true);
        underlineToolBtn = new QToolButton(Widget);
        underlineToolBtn->setObjectName(QString::fromUtf8("underlineToolBtn"));
        underlineToolBtn->setGeometry(QRect(330, 380, 30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/underline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon2);
        underlineToolBtn->setIconSize(QSize(22, 22));
        underlineToolBtn->setCheckable(true);
        underlineToolBtn->setAutoRaise(true);
        colorToolBtn = new QToolButton(Widget);
        colorToolBtn->setObjectName(QString::fromUtf8("colorToolBtn"));
        colorToolBtn->setGeometry(QRect(370, 380, 30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/color.svg"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon3);
        colorToolBtn->setIconSize(QSize(22, 22));
        colorToolBtn->setAutoRaise(true);
        sendToolBtn = new QToolButton(Widget);
        sendToolBtn->setObjectName(QString::fromUtf8("sendToolBtn"));
        sendToolBtn->setGeometry(QRect(410, 380, 30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons/send.svg"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolBtn->setIcon(icon4);
        sendToolBtn->setIconSize(QSize(22, 22));
        sendToolBtn->setAutoRaise(true);
        saveToolBtn = new QToolButton(Widget);
        saveToolBtn->setObjectName(QString::fromUtf8("saveToolBtn"));
        saveToolBtn->setGeometry(QRect(450, 380, 30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons/save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon5);
        saveToolBtn->setIconSize(QSize(22, 22));
        saveToolBtn->setAutoRaise(true);
        clearToolBtn = new QToolButton(Widget);
        clearToolBtn->setObjectName(QString::fromUtf8("clearToolBtn"));
        clearToolBtn->setGeometry(QRect(490, 380, 30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons/clear.svg"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon6);
        clearToolBtn->setIconSize(QSize(22, 22));
        clearToolBtn->setAutoRaise(true);
        messageTextEdit = new QTextEdit(Widget);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(10, 420, 661, 131));
        userTableWidget = new QTableWidget(Widget);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTableWidget->setObjectName(QString::fromUtf8("userTableWidget"));
        userTableWidget->setGeometry(QRect(680, 10, 311, 541));
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);
        userTableWidget->horizontalHeader()->setStretchLastSection(true);
        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(590, 560, 81, 31));
        userNumLabel = new QLabel(Widget);
        userNumLabel->setObjectName(QString::fromUtf8("userNumLabel"));
        userNumLabel->setGeometry(QRect(20, 560, 111, 21));
        exitButton = new QPushButton(Widget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(900, 560, 91, 31));

        retranslateUi(Widget);

        sizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\261\200\345\237\237\347\275\221\350\201\212\345\244\251\345\267\245\345\205\267", nullptr));
        sizeComboBox->setItemText(0, QCoreApplication::translate("Widget", "8", nullptr));
        sizeComboBox->setItemText(1, QCoreApplication::translate("Widget", "9", nullptr));
        sizeComboBox->setItemText(2, QCoreApplication::translate("Widget", "10", nullptr));
        sizeComboBox->setItemText(3, QCoreApplication::translate("Widget", "11", nullptr));
        sizeComboBox->setItemText(4, QCoreApplication::translate("Widget", "12", nullptr));
        sizeComboBox->setItemText(5, QCoreApplication::translate("Widget", "13", nullptr));
        sizeComboBox->setItemText(6, QCoreApplication::translate("Widget", "14", nullptr));
        sizeComboBox->setItemText(7, QCoreApplication::translate("Widget", "15", nullptr));
        sizeComboBox->setItemText(8, QCoreApplication::translate("Widget", "16", nullptr));
        sizeComboBox->setItemText(9, QCoreApplication::translate("Widget", "17", nullptr));
        sizeComboBox->setItemText(10, QCoreApplication::translate("Widget", "18", nullptr));
        sizeComboBox->setItemText(11, QCoreApplication::translate("Widget", "19", nullptr));
        sizeComboBox->setItemText(12, QCoreApplication::translate("Widget", "20", nullptr));
        sizeComboBox->setItemText(13, QCoreApplication::translate("Widget", "21", nullptr));
        sizeComboBox->setItemText(14, QCoreApplication::translate("Widget", "22", nullptr));
        sizeComboBox->setItemText(15, QCoreApplication::translate("Widget", "23", nullptr));
        sizeComboBox->setItemText(16, QCoreApplication::translate("Widget", "24", nullptr));
        sizeComboBox->setItemText(17, QCoreApplication::translate("Widget", "25", nullptr));

#if QT_CONFIG(tooltip)
        boldToolBtn->setToolTip(QCoreApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
#endif // QT_CONFIG(tooltip)
        boldToolBtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        italicToolBtn->setToolTip(QCoreApplication::translate("Widget", "\345\200\276\346\226\234", nullptr));
#endif // QT_CONFIG(tooltip)
        italicToolBtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        underlineToolBtn->setToolTip(QCoreApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        underlineToolBtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        colorToolBtn->setToolTip(QCoreApplication::translate("Widget", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        colorToolBtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        sendToolBtn->setToolTip(QCoreApplication::translate("Widget", "\344\274\240\350\276\223\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        sendToolBtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        saveToolBtn->setToolTip(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        saveToolBtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        clearToolBtn->setToolTip(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        clearToolBtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\344\270\273\346\234\272\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = userTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "IP\345\234\260\345\235\200", nullptr));
        sendButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        userNumLabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt;\">\345\234\250\347\272\277\344\272\272\346\225\260\357\274\2320\344\272\272</span></p></body></html>", nullptr));
        exitButton->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
