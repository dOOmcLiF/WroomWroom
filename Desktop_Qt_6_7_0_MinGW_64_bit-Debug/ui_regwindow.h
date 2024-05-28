/********************************************************************************
** Form generated from reading UI file 'regwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWINDOW_H
#define UI_REGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regwindow
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QToolButton *toolButton;

    void setupUi(QWidget *regwindow)
    {
        if (regwindow->objectName().isEmpty())
            regwindow->setObjectName("regwindow");
        regwindow->resize(600, 600);
        lineEdit = new QLineEdit(regwindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 130, 201, 31));
        lineEdit_2 = new QLineEdit(regwindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 170, 201, 31));
        lineEdit_3 = new QLineEdit(regwindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(200, 210, 201, 31));
        pushButton = new QPushButton(regwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 450, 141, 31));
        comboBox = new QComboBox(regwindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(230, 410, 141, 21));
        lineEdit_6 = new QLineEdit(regwindow);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(200, 330, 201, 31));
        lineEdit_7 = new QLineEdit(regwindow);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(200, 370, 201, 31));
        lineEdit_4 = new QLineEdit(regwindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(200, 250, 201, 31));
        lineEdit_5 = new QLineEdit(regwindow);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(200, 290, 201, 31));
        toolButton = new QToolButton(regwindow);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(20, 20, 71, 61));
        toolButton->setStyleSheet(QString::fromUtf8("background-image: url(:/new/backlogo/5700554.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/new/backlogo/5700554.png);"));

        retranslateUi(regwindow);

        QMetaObject::connectSlotsByName(regwindow);
    } // setupUi

    void retranslateUi(QWidget *regwindow)
    {
        regwindow->setWindowTitle(QCoreApplication::translate("regwindow", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("regwindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("regwindow", "\320\230\320\274\321\217", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("regwindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        pushButton->setText(QCoreApplication::translate("regwindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("regwindow", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("regwindow", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272", nullptr));

        comboBox->setPlaceholderText(QCoreApplication::translate("regwindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("regwindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("regwindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("regwindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("regwindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class regwindow: public Ui_regwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWINDOW_H
