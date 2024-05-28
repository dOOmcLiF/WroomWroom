/********************************************************************************
** Form generated from reading UI file 'buyerhomewindown.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYERHOMEWINDOWN_H
#define UI_BUYERHOMEWINDOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuyerHomeWindowN
{
public:
    QWidget *centralwidget;
    QPushButton *exitButton;
    QTabWidget *tabWidget;
    QWidget *tab_9;
    QTableView *tableView;
    QPushButton *pushButton;
    QWidget *tab_10;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *payButton;
    QListWidget *listWidget;
    QLabel *totalPrice;
    QLabel *label_2;
    QWidget *page_2;
    QPushButton *backButton;
    QLabel *label_3;
    QLineEdit *cardNumber;
    QLineEdit *monthYear;
    QLineEdit *cvcCvv;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *email;
    QLabel *label_7;
    QPushButton *payButton_2;
    QLabel *nameLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BuyerHomeWindowN)
    {
        if (BuyerHomeWindowN->objectName().isEmpty())
            BuyerHomeWindowN->setObjectName("BuyerHomeWindowN");
        BuyerHomeWindowN->resize(800, 625);
        centralwidget = new QWidget(BuyerHomeWindowN);
        centralwidget->setObjectName("centralwidget");
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(700, 550, 80, 24));
        QFont font;
        font.setPointSize(9);
        exitButton->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 60, 771, 481));
        tabWidget->setFont(font);
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        tableView = new QTableView(tab_9);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 751, 431));
        pushButton = new QPushButton(tab_9);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(650, 390, 83, 29));
        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        stackedWidget = new QStackedWidget(tab_10);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 771, 451));
        page = new QWidget();
        page->setObjectName("page");
        payButton = new QPushButton(page);
        payButton->setObjectName("payButton");
        payButton->setGeometry(QRect(660, 410, 80, 24));
        listWidget = new QListWidget(page);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(80, 40, 601, 311));
        totalPrice = new QLabel(page);
        totalPrice->setObjectName("totalPrice");
        totalPrice->setGeometry(QRect(550, 350, 321, 51));
        QFont font1;
        font1.setPointSize(25);
        totalPrice->setFont(font1);
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 350, 101, 51));
        label_2->setFont(font1);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        backButton = new QPushButton(page_2);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(20, 410, 80, 24));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 60, 321, 51));
        QFont font2;
        font2.setPointSize(18);
        label_3->setFont(font2);
        cardNumber = new QLineEdit(page_2);
        cardNumber->setObjectName("cardNumber");
        cardNumber->setGeometry(QRect(250, 140, 231, 31));
        monthYear = new QLineEdit(page_2);
        monthYear->setObjectName("monthYear");
        monthYear->setGeometry(QRect(250, 210, 101, 31));
        cvcCvv = new QLineEdit(page_2);
        cvcCvv->setObjectName("cvcCvv");
        cvcCvv->setGeometry(QRect(390, 210, 91, 31));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(250, 110, 101, 21));
        QFont font3;
        font3.setPointSize(12);
        label_4->setFont(font3);
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 180, 111, 21));
        label_5->setFont(font3);
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(390, 180, 111, 21));
        label_6->setFont(font3);
        email = new QLineEdit(page_2);
        email->setObjectName("email");
        email->setGeometry(QRect(250, 280, 231, 31));
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(250, 250, 191, 21));
        label_7->setFont(font3);
        payButton_2 = new QPushButton(page_2);
        payButton_2->setObjectName("payButton_2");
        payButton_2->setGeometry(QRect(660, 410, 80, 24));
        stackedWidget->addWidget(page_2);
        tabWidget->addTab(tab_10, QString());
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(630, 20, 111, 51));
        nameLabel->setFont(font1);
        BuyerHomeWindowN->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BuyerHomeWindowN);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        BuyerHomeWindowN->setMenuBar(menubar);
        statusbar = new QStatusBar(BuyerHomeWindowN);
        statusbar->setObjectName("statusbar");
        BuyerHomeWindowN->setStatusBar(statusbar);

        retranslateUi(BuyerHomeWindowN);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BuyerHomeWindowN);
    } // setupUi

    void retranslateUi(QMainWindow *BuyerHomeWindowN)
    {
        BuyerHomeWindowN->setWindowTitle(QCoreApplication::translate("BuyerHomeWindowN", "MainWindow", nullptr));
        exitButton->setText(QCoreApplication::translate("BuyerHomeWindowN", "Exit", nullptr));
        pushButton->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\232\321\203\320\277\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("BuyerHomeWindowN", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\202\320\276\320\262\320\260\321\200\320\276\320\262", nullptr));
        payButton->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\236\320\277\320\273\320\260\321\202\320\270\321\202\321\214", nullptr));
        totalPrice->setText(QString());
        label_2->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\230\321\202\320\276\320\263\320\276:", nullptr));
        backButton->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\276\320\277\320\273\320\260\321\202\321\213:", nullptr));
        cardNumber->setPlaceholderText(QCoreApplication::translate("BuyerHomeWindowN", "16 \321\206\320\270\321\204\321\200", nullptr));
        monthYear->setPlaceholderText(QCoreApplication::translate("BuyerHomeWindowN", "\320\234\320\234/\320\223\320\223", nullptr));
        cvcCvv->setPlaceholderText(QCoreApplication::translate("BuyerHomeWindowN", "3 \321\206\320\270\321\204\321\200\321\213", nullptr));
        label_4->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\260\321\200\321\202\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\241\321\200\320\276\320\272 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("BuyerHomeWindowN", "CVC / CVV", nullptr));
        email->setPlaceholderText(QCoreApplication::translate("BuyerHomeWindowN", "ivan_ivanov@mail.ru", nullptr));
        label_7->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\220\320\264\321\200\320\265\321\201 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\277\320\276\321\207\321\202\321\213", nullptr));
        payButton_2->setText(QCoreApplication::translate("BuyerHomeWindowN", "\320\232\321\203\320\277\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QCoreApplication::translate("BuyerHomeWindowN", "\320\232\320\276\321\200\320\267\320\270\320\275\320\260", nullptr));
        nameLabel->setText(QCoreApplication::translate("BuyerHomeWindowN", "name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuyerHomeWindowN: public Ui_BuyerHomeWindowN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYERHOMEWINDOWN_H
