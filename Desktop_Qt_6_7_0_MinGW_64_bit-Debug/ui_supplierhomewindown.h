/********************************************************************************
** Form generated from reading UI file 'supplierhomewindown.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIERHOMEWINDOWN_H
#define UI_SUPPLIERHOMEWINDOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupplierHomeWindowN
{
public:
    QWidget *centralwidget;
    QLabel *vendorLabel;
    QPushButton *exitButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *addButton;
    QLineEdit *lineEdit_13;
    QWidget *tab_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *changeButton;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QWidget *tab_5;
    QComboBox *comboBox_2;
    QPushButton *deleteButton;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_16;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SupplierHomeWindowN)
    {
        if (SupplierHomeWindowN->objectName().isEmpty())
            SupplierHomeWindowN->setObjectName("SupplierHomeWindowN");
        SupplierHomeWindowN->resize(800, 600);
        centralwidget = new QWidget(SupplierHomeWindowN);
        centralwidget->setObjectName("centralwidget");
        vendorLabel = new QLabel(centralwidget);
        vendorLabel->setObjectName("vendorLabel");
        vendorLabel->setGeometry(QRect(460, 200, 111, 41));
        QFont font;
        font.setPointSize(18);
        vendorLabel->setFont(font);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(10, 533, 80, 24));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 70, 781, 451));
        QFont font1;
        font1.setPointSize(9);
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName("tab");
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(130, 100, 131, 28));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(130, 180, 131, 28));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(130, 220, 131, 28));
        addButton = new QPushButton(tab);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(650, 340, 83, 29));
        lineEdit_13 = new QLineEdit(tab);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(130, 140, 131, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(130, 80, 131, 41));
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(130, 140, 131, 28));
        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setEnabled(false);
        lineEdit_5->setGeometry(QRect(130, 220, 131, 28));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setEnabled(false);
        lineEdit_6->setGeometry(QRect(130, 260, 131, 28));
        changeButton = new QPushButton(tab_2);
        changeButton->setObjectName("changeButton");
        changeButton->setGeometry(QRect(580, 320, 83, 29));
        lineEdit_10 = new QLineEdit(tab_2);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setEnabled(true);
        lineEdit_10->setGeometry(QRect(290, 140, 131, 28));
        lineEdit_11 = new QLineEdit(tab_2);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setEnabled(true);
        lineEdit_11->setGeometry(QRect(290, 220, 131, 28));
        lineEdit_12 = new QLineEdit(tab_2);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setEnabled(true);
        lineEdit_12->setGeometry(QRect(290, 260, 131, 28));
        lineEdit_14 = new QLineEdit(tab_2);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setEnabled(false);
        lineEdit_14->setGeometry(QRect(130, 180, 131, 28));
        lineEdit_15 = new QLineEdit(tab_2);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setEnabled(true);
        lineEdit_15->setGeometry(QRect(290, 180, 131, 28));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        comboBox_2 = new QComboBox(tab_5);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setEnabled(true);
        comboBox_2->setGeometry(QRect(130, 80, 131, 41));
        deleteButton = new QPushButton(tab_5);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(620, 340, 83, 29));
        lineEdit_7 = new QLineEdit(tab_5);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setEnabled(false);
        lineEdit_7->setGeometry(QRect(130, 140, 131, 28));
        lineEdit_8 = new QLineEdit(tab_5);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setEnabled(false);
        lineEdit_8->setGeometry(QRect(130, 220, 131, 28));
        lineEdit_9 = new QLineEdit(tab_5);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setEnabled(false);
        lineEdit_9->setGeometry(QRect(130, 260, 131, 28));
        lineEdit_16 = new QLineEdit(tab_5);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setEnabled(false);
        lineEdit_16->setGeometry(QRect(130, 180, 131, 28));
        tabWidget->addTab(tab_5, QString());
        SupplierHomeWindowN->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SupplierHomeWindowN);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        SupplierHomeWindowN->setMenuBar(menubar);
        statusbar = new QStatusBar(SupplierHomeWindowN);
        statusbar->setObjectName("statusbar");
        SupplierHomeWindowN->setStatusBar(statusbar);

        retranslateUi(SupplierHomeWindowN);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SupplierHomeWindowN);
    } // setupUi

    void retranslateUi(QMainWindow *SupplierHomeWindowN)
    {
        SupplierHomeWindowN->setWindowTitle(QCoreApplication::translate("SupplierHomeWindowN", "MainWindow", nullptr));
        vendorLabel->setText(QCoreApplication::translate("SupplierHomeWindowN", "TextLabel", nullptr));
        exitButton->setText(QCoreApplication::translate("SupplierHomeWindowN", "Exit", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\246\320\265\320\275\320\260", nullptr));
        addButton->setText(QCoreApplication::translate("SupplierHomeWindowN", "Add", nullptr));
        lineEdit_13->setText(QString());
        lineEdit_13->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SupplierHomeWindowN", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\276\320\262\320\260\321\200", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\246\320\265\320\275\320\260", nullptr));
        changeButton->setText(QCoreApplication::translate("SupplierHomeWindowN", "Change", nullptr));
        lineEdit_10->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\276\320\262\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_11->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\276\320\262\321\213\320\271 \320\260\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        lineEdit_12->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\276\320\262\320\260\321\217 \321\206\320\265\320\275\320\260", nullptr));
        lineEdit_14->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        lineEdit_15->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\276\320\262\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SupplierHomeWindowN", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
        comboBox_2->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\276\320\262\320\260\321\200", nullptr));
        deleteButton->setText(QCoreApplication::translate("SupplierHomeWindowN", "Delete", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\246\320\265\320\275\320\260", nullptr));
        lineEdit_16->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("SupplierHomeWindowN", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierHomeWindowN: public Ui_SupplierHomeWindowN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIERHOMEWINDOWN_H
