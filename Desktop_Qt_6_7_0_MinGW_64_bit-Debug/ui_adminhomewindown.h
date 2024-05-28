/********************************************************************************
** Form generated from reading UI file 'adminhomewindown.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINHOMEWINDOWN_H
#define UI_ADMINHOMEWINDOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminHomeWindowN
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QPushButton *regUser;
    QLineEdit *lineEdit_6;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *deleteButton;
    QWidget *tab_3;
    QTableView *purchaseHistoryTable;
    QWidget *tab_4;
    QTableView *priceChangeHistoryTable;
    QPushButton *exitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminHomeWindowN)
    {
        if (AdminHomeWindowN->objectName().isEmpty())
            AdminHomeWindowN->setObjectName("AdminHomeWindowN");
        AdminHomeWindowN->resize(800, 614);
        centralwidget = new QWidget(AdminHomeWindowN);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 77, 782, 457));
        tab = new QWidget();
        tab->setObjectName("tab");
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 80, 113, 31));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(80, 120, 113, 31));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(80, 160, 113, 31));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(260, 120, 113, 31));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(260, 160, 113, 31));
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(260, 80, 111, 31));
        regUser = new QPushButton(tab);
        regUser->setObjectName("regUser");
        regUser->setGeometry(QRect(590, 340, 111, 31));
        regUser->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(260, 200, 113, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(tab_2);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        deleteButton = new QPushButton(tab_2);
        deleteButton->setObjectName("deleteButton");

        verticalLayout->addWidget(deleteButton);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        purchaseHistoryTable = new QTableView(tab_3);
        purchaseHistoryTable->setObjectName("purchaseHistoryTable");
        purchaseHistoryTable->setGeometry(QRect(10, 10, 761, 411));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        priceChangeHistoryTable = new QTableView(tab_4);
        priceChangeHistoryTable->setObjectName("priceChangeHistoryTable");
        priceChangeHistoryTable->setGeometry(QRect(10, 10, 761, 411));
        tabWidget->addTab(tab_4, QString());
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(10, 540, 782, 24));
        exitButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 0, 0);"));
        AdminHomeWindowN->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminHomeWindowN);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AdminHomeWindowN->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminHomeWindowN);
        statusbar->setObjectName("statusbar");
        AdminHomeWindowN->setStatusBar(statusbar);

        retranslateUi(AdminHomeWindowN);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(AdminHomeWindowN);
    } // setupUi

    void retranslateUi(QMainWindow *AdminHomeWindowN)
    {
        AdminHomeWindowN->setWindowTitle(QCoreApplication::translate("AdminHomeWindowN", "MainWindow", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("AdminHomeWindowN", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("AdminHomeWindowN", "\320\230\320\274\321\217", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("AdminHomeWindowN", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("AdminHomeWindowN", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("AdminHomeWindowN", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AdminHomeWindowN", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AdminHomeWindowN", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("AdminHomeWindowN", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));

        comboBox->setPlaceholderText(QCoreApplication::translate("AdminHomeWindowN", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        regUser->setText(QCoreApplication::translate("AdminHomeWindowN", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("AdminHomeWindowN", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AdminHomeWindowN", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        deleteButton->setText(QCoreApplication::translate("AdminHomeWindowN", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AdminHomeWindowN", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("AdminHomeWindowN", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\277\320\276\320\272\321\203\320\277\320\276\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("AdminHomeWindowN", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \321\206\320\265\320\275", nullptr));
        exitButton->setText(QCoreApplication::translate("AdminHomeWindowN", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminHomeWindowN: public Ui_AdminHomeWindowN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINHOMEWINDOWN_H
