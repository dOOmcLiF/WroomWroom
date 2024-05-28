/********************************************************************************
** Form generated from reading UI file 'exitdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITDIALOG_H
#define UI_EXITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ExitDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *ExitDialog)
    {
        if (ExitDialog->objectName().isEmpty())
            ExitDialog->setObjectName("ExitDialog");
        ExitDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ExitDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ExitDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 90, 311, 91));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        retranslateUi(ExitDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ExitDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ExitDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ExitDialog);
    } // setupUi

    void retranslateUi(QDialog *ExitDialog)
    {
        ExitDialog->setWindowTitle(QCoreApplication::translate("ExitDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ExitDialog", "\320\222\321\213 \321\203\320\262\320\265\321\200\320\265\320\275\321\213, \321\207\321\202\320\276 \321\205\320\276\321\202\320\270\321\202\320\265 \320\262\321\213\320\271\321\202\320\270?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExitDialog: public Ui_ExitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITDIALOG_H
