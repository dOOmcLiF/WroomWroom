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
    QLineEdit *name;
    QLineEdit *vendorCode;
    QLineEdit *price;
    QPushButton *addButton;
    QLineEdit *quantity;
    QWidget *tab_2;
    QComboBox *comboBox;
    QLineEdit *oldName;
    QLineEdit *oldVendorCode;
    QLineEdit *oldPrice;
    QPushButton *changeButton;
    QLineEdit *newName;
    QLineEdit *newVendorCode;
    QLineEdit *newPrice;
    QLineEdit *oldQuantity;
    QLineEdit *newQuantity;
    QWidget *tab_5;
    QComboBox *comboBox_2;
    QPushButton *deleteButton;
    QLineEdit *name_2;
    QLineEdit *vendorCode_2;
    QLineEdit *price_2;
    QLineEdit *quantity_2;
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
        name = new QLineEdit(tab);
        name->setObjectName("name");
        name->setGeometry(QRect(130, 100, 131, 28));
        vendorCode = new QLineEdit(tab);
        vendorCode->setObjectName("vendorCode");
        vendorCode->setGeometry(QRect(130, 180, 131, 28));
        price = new QLineEdit(tab);
        price->setObjectName("price");
        price->setGeometry(QRect(130, 220, 131, 28));
        addButton = new QPushButton(tab);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(650, 340, 83, 29));
        quantity = new QLineEdit(tab);
        quantity->setObjectName("quantity");
        quantity->setGeometry(QRect(130, 140, 131, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(130, 80, 131, 41));
        oldName = new QLineEdit(tab_2);
        oldName->setObjectName("oldName");
        oldName->setEnabled(false);
        oldName->setGeometry(QRect(130, 140, 131, 28));
        oldVendorCode = new QLineEdit(tab_2);
        oldVendorCode->setObjectName("oldVendorCode");
        oldVendorCode->setEnabled(false);
        oldVendorCode->setGeometry(QRect(130, 220, 131, 28));
        oldPrice = new QLineEdit(tab_2);
        oldPrice->setObjectName("oldPrice");
        oldPrice->setEnabled(false);
        oldPrice->setGeometry(QRect(130, 260, 131, 28));
        changeButton = new QPushButton(tab_2);
        changeButton->setObjectName("changeButton");
        changeButton->setGeometry(QRect(580, 320, 83, 29));
        newName = new QLineEdit(tab_2);
        newName->setObjectName("newName");
        newName->setEnabled(true);
        newName->setGeometry(QRect(290, 140, 131, 28));
        newVendorCode = new QLineEdit(tab_2);
        newVendorCode->setObjectName("newVendorCode");
        newVendorCode->setEnabled(true);
        newVendorCode->setGeometry(QRect(290, 220, 131, 28));
        newPrice = new QLineEdit(tab_2);
        newPrice->setObjectName("newPrice");
        newPrice->setEnabled(true);
        newPrice->setGeometry(QRect(290, 260, 131, 28));
        oldQuantity = new QLineEdit(tab_2);
        oldQuantity->setObjectName("oldQuantity");
        oldQuantity->setEnabled(false);
        oldQuantity->setGeometry(QRect(130, 180, 131, 28));
        newQuantity = new QLineEdit(tab_2);
        newQuantity->setObjectName("newQuantity");
        newQuantity->setEnabled(true);
        newQuantity->setGeometry(QRect(290, 180, 131, 28));
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
        name_2 = new QLineEdit(tab_5);
        name_2->setObjectName("name_2");
        name_2->setEnabled(false);
        name_2->setGeometry(QRect(130, 140, 131, 28));
        vendorCode_2 = new QLineEdit(tab_5);
        vendorCode_2->setObjectName("vendorCode_2");
        vendorCode_2->setEnabled(false);
        vendorCode_2->setGeometry(QRect(130, 220, 131, 28));
        price_2 = new QLineEdit(tab_5);
        price_2->setObjectName("price_2");
        price_2->setEnabled(false);
        price_2->setGeometry(QRect(130, 260, 131, 28));
        quantity_2 = new QLineEdit(tab_5);
        quantity_2->setObjectName("quantity_2");
        quantity_2->setEnabled(false);
        quantity_2->setGeometry(QRect(130, 180, 131, 28));
        tabWidget->addTab(tab_5, QString());
        SupplierHomeWindowN->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SupplierHomeWindowN);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        SupplierHomeWindowN->setMenuBar(menubar);
        statusbar = new QStatusBar(SupplierHomeWindowN);
        statusbar->setObjectName("statusbar");
        SupplierHomeWindowN->setStatusBar(statusbar);
        QWidget::setTabOrder(name, quantity);
        QWidget::setTabOrder(quantity, vendorCode);
        QWidget::setTabOrder(vendorCode, price);
        QWidget::setTabOrder(price, addButton);
        QWidget::setTabOrder(addButton, tabWidget);
        QWidget::setTabOrder(tabWidget, comboBox);
        QWidget::setTabOrder(comboBox, oldName);
        QWidget::setTabOrder(oldName, oldQuantity);
        QWidget::setTabOrder(oldQuantity, oldVendorCode);
        QWidget::setTabOrder(oldVendorCode, oldPrice);
        QWidget::setTabOrder(oldPrice, newName);
        QWidget::setTabOrder(newName, newQuantity);
        QWidget::setTabOrder(newQuantity, newVendorCode);
        QWidget::setTabOrder(newVendorCode, newPrice);
        QWidget::setTabOrder(newPrice, changeButton);
        QWidget::setTabOrder(changeButton, comboBox_2);
        QWidget::setTabOrder(comboBox_2, name_2);
        QWidget::setTabOrder(name_2, quantity_2);
        QWidget::setTabOrder(quantity_2, vendorCode_2);
        QWidget::setTabOrder(vendorCode_2, price_2);
        QWidget::setTabOrder(price_2, deleteButton);
        QWidget::setTabOrder(deleteButton, exitButton);

        retranslateUi(SupplierHomeWindowN);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SupplierHomeWindowN);
    } // setupUi

    void retranslateUi(QMainWindow *SupplierHomeWindowN)
    {
        SupplierHomeWindowN->setWindowTitle(QCoreApplication::translate("SupplierHomeWindowN", "MainWindow", nullptr));
        vendorLabel->setText(QCoreApplication::translate("SupplierHomeWindowN", "TextLabel", nullptr));
        exitButton->setText(QCoreApplication::translate("SupplierHomeWindowN", "Exit", nullptr));
        name->setText(QString());
        name->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        vendorCode->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        price->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\246\320\265\320\275\320\260", nullptr));
        addButton->setText(QCoreApplication::translate("SupplierHomeWindowN", "Add", nullptr));
        quantity->setText(QString());
        quantity->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SupplierHomeWindowN", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\276\320\262\320\260\321\200", nullptr));
        oldName->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        oldVendorCode->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        oldPrice->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\246\320\265\320\275\320\260", nullptr));
        changeButton->setText(QCoreApplication::translate("SupplierHomeWindowN", "Change", nullptr));
        newName->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\276\320\262\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        newVendorCode->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\276\320\262\321\213\320\271 \320\260\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        newPrice->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\276\320\262\320\260\321\217 \321\206\320\265\320\275\320\260", nullptr));
        oldQuantity->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        newQuantity->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\276\320\262\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SupplierHomeWindowN", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
        comboBox_2->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\276\320\262\320\260\321\200", nullptr));
        deleteButton->setText(QCoreApplication::translate("SupplierHomeWindowN", "Delete", nullptr));
        name_2->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        vendorCode_2->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        price_2->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\246\320\265\320\275\320\260", nullptr));
        quantity_2->setPlaceholderText(QCoreApplication::translate("SupplierHomeWindowN", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("SupplierHomeWindowN", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierHomeWindowN: public Ui_SupplierHomeWindowN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIERHOMEWINDOWN_H
