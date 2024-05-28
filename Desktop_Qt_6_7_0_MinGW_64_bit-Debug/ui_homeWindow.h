/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Homewindow
{
public:
    QLabel *label;

    void setupUi(QWidget *Homewindow)
    {
        if (Homewindow->objectName().isEmpty())
            Homewindow->setObjectName("Homewindow");
        Homewindow->resize(800, 600);
        label = new QLabel(Homewindow);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 170, 311, 221));
        QFont font;
        font.setPointSize(73);
        label->setFont(font);

        retranslateUi(Homewindow);

        QMetaObject::connectSlotsByName(Homewindow);
    } // setupUi

    void retranslateUi(QWidget *Homewindow)
    {
        Homewindow->setWindowTitle(QCoreApplication::translate("Homewindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("Homewindow", "123", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Homewindow: public Ui_Homewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
