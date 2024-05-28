/********************************************************************************
** Form generated from reading UI file 'adminhomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINHOMEWINDOW_H
#define UI_ADMINHOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminHomeWindow
{
public:
    QLabel *label;
    QPushButton *exitButton;
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
    QTableWidget *tableWidget;

    void setupUi(QDialog *AdminHomeWindow)
    {
        if (AdminHomeWindow->objectName().isEmpty())
            AdminHomeWindow->setObjectName("AdminHomeWindow");
        AdminHomeWindow->setEnabled(true);
        AdminHomeWindow->resize(800, 600);
        label = new QLabel(AdminHomeWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 211, 61));
        QFont font;
        font.setPointSize(50);
        label->setFont(font);
        exitButton = new QPushButton(AdminHomeWindow);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(670, 520, 101, 31));
        exitButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 0, 0);"));
        tabWidget = new QTabWidget(AdminHomeWindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 70, 741, 441));
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
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 741, 411));
        tableWidget->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget->horizontalHeader()->setDefaultSectionSize(164);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setMinimumSectionSize(20);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(AdminHomeWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminHomeWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminHomeWindow)
    {
        AdminHomeWindow->setWindowTitle(QCoreApplication::translate("AdminHomeWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AdminHomeWindow", "Admin", nullptr));
        exitButton->setText(QCoreApplication::translate("AdminHomeWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("AdminHomeWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("AdminHomeWindow", "\320\230\320\274\321\217", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("AdminHomeWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("AdminHomeWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("AdminHomeWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AdminHomeWindow", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AdminHomeWindow", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("AdminHomeWindow", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));

        comboBox->setPlaceholderText(QCoreApplication::translate("AdminHomeWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        regUser->setText(QCoreApplication::translate("AdminHomeWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("AdminHomeWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AdminHomeWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminHomeWindow", "\320\244\320\230\320\236 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminHomeWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminHomeWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AdminHomeWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AdminHomeWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AdminHomeWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminHomeWindow: public Ui_AdminHomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINHOMEWINDOW_H
