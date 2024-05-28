/********************************************************************************
** Form generated from reading UI file 'supplierhomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIERHOMEWINDOW_H
#define UI_SUPPLIERHOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SupplierHomeWindow
{
public:
    QLabel *label;

    void setupUi(QDialog *SupplierHomeWindow)
    {
        if (SupplierHomeWindow->objectName().isEmpty())
            SupplierHomeWindow->setObjectName("SupplierHomeWindow");
        SupplierHomeWindow->resize(800, 600);
        label = new QLabel(SupplierHomeWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 220, 341, 151));
        QFont font;
        font.setPointSize(50);
        label->setFont(font);

        retranslateUi(SupplierHomeWindow);

        QMetaObject::connectSlotsByName(SupplierHomeWindow);
    } // setupUi

    void retranslateUi(QDialog *SupplierHomeWindow)
    {
        SupplierHomeWindow->setWindowTitle(QCoreApplication::translate("SupplierHomeWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SupplierHomeWindow", "Supplier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierHomeWindow: public Ui_SupplierHomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIERHOMEWINDOW_H
