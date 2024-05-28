/********************************************************************************
** Form generated from reading UI file 'buyerhomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYERHOMEWINDOW_H
#define UI_BUYERHOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_BuyerHomeWindow
{
public:
    QLabel *label;

    void setupUi(QDialog *BuyerHomeWindow)
    {
        if (BuyerHomeWindow->objectName().isEmpty())
            BuyerHomeWindow->setObjectName("BuyerHomeWindow");
        BuyerHomeWindow->resize(800, 600);
        QFont font;
        font.setPointSize(50);
        BuyerHomeWindow->setFont(font);
        label = new QLabel(BuyerHomeWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 210, 361, 111));

        retranslateUi(BuyerHomeWindow);

        QMetaObject::connectSlotsByName(BuyerHomeWindow);
    } // setupUi

    void retranslateUi(QDialog *BuyerHomeWindow)
    {
        BuyerHomeWindow->setWindowTitle(QCoreApplication::translate("BuyerHomeWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("BuyerHomeWindow", "Buyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuyerHomeWindow: public Ui_BuyerHomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYERHOMEWINDOW_H
