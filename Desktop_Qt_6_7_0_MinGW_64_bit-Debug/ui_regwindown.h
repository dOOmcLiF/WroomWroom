/********************************************************************************
** Form generated from reading UI file 'regwindown.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWINDOWN_H
#define UI_REGWINDOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegWindowN
{
public:
    QWidget *centralwidget;
    QLineEdit *name;
    QLineEdit *phoneNumber;
    QLineEdit *address;
    QLineEdit *surname;
    QPushButton *pushButton;
    QLineEdit *repeatPassword;
    QLineEdit *patronymic;
    QToolButton *toolButton;
    QLineEdit *password;
    QLineEdit *login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegWindowN)
    {
        if (RegWindowN->objectName().isEmpty())
            RegWindowN->setObjectName("RegWindowN");
        RegWindowN->resize(800, 600);
        centralwidget = new QWidget(RegWindowN);
        centralwidget->setObjectName("centralwidget");
        name = new QLineEdit(centralwidget);
        name->setObjectName("name");
        name->setGeometry(QRect(310, 130, 201, 31));
        phoneNumber = new QLineEdit(centralwidget);
        phoneNumber->setObjectName("phoneNumber");
        phoneNumber->setGeometry(QRect(310, 250, 201, 31));
        address = new QLineEdit(centralwidget);
        address->setObjectName("address");
        address->setGeometry(QRect(310, 210, 201, 31));
        surname = new QLineEdit(centralwidget);
        surname->setObjectName("surname");
        surname->setGeometry(QRect(310, 90, 201, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(340, 450, 141, 31));
        repeatPassword = new QLineEdit(centralwidget);
        repeatPassword->setObjectName("repeatPassword");
        repeatPassword->setGeometry(QRect(310, 340, 201, 31));
        patronymic = new QLineEdit(centralwidget);
        patronymic->setObjectName("patronymic");
        patronymic->setGeometry(QRect(310, 170, 201, 31));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(60, 20, 71, 61));
        toolButton->setStyleSheet(QString::fromUtf8("background-image: url(:/new/backlogo/5700554.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/new/backlogo/5700554.png);"));
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(310, 380, 201, 31));
        login = new QLineEdit(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(310, 300, 201, 31));
        RegWindowN->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegWindowN);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        RegWindowN->setMenuBar(menubar);
        statusbar = new QStatusBar(RegWindowN);
        statusbar->setObjectName("statusbar");
        RegWindowN->setStatusBar(statusbar);
        QWidget::setTabOrder(surname, name);
        QWidget::setTabOrder(name, patronymic);
        QWidget::setTabOrder(patronymic, address);
        QWidget::setTabOrder(address, phoneNumber);
        QWidget::setTabOrder(phoneNumber, login);
        QWidget::setTabOrder(login, repeatPassword);
        QWidget::setTabOrder(repeatPassword, password);
        QWidget::setTabOrder(password, pushButton);
        QWidget::setTabOrder(pushButton, toolButton);

        retranslateUi(RegWindowN);

        QMetaObject::connectSlotsByName(RegWindowN);
    } // setupUi

    void retranslateUi(QMainWindow *RegWindowN)
    {
        RegWindowN->setWindowTitle(QCoreApplication::translate("RegWindowN", "MainWindow", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("RegWindowN", "\320\230\320\274\321\217", nullptr));
        phoneNumber->setPlaceholderText(QCoreApplication::translate("RegWindowN", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        address->setPlaceholderText(QCoreApplication::translate("RegWindowN", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        surname->setPlaceholderText(QCoreApplication::translate("RegWindowN", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("RegWindowN", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        repeatPassword->setPlaceholderText(QCoreApplication::translate("RegWindowN", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        patronymic->setPlaceholderText(QCoreApplication::translate("RegWindowN", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        toolButton->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("RegWindowN", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        login->setPlaceholderText(QCoreApplication::translate("RegWindowN", "\320\233\320\276\320\263\320\270\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegWindowN: public Ui_RegWindowN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWINDOWN_H
