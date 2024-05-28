#ifndef SUPPLIERHOMEWINDOWN_H
#define SUPPLIERHOMEWINDOWN_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class SupplierHomeWindowN;
}

class SupplierHomeWindowN : public QMainWindow
{
    Q_OBJECT

public:
    explicit SupplierHomeWindowN(QWidget *parent = nullptr);
    ~SupplierHomeWindowN();
    void setLabel_2(const QString& x);

private slots:
    void on_exitButton_clicked();

    void on_addButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

    void on_changeButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::SupplierHomeWindowN *ui;
    DataBase db;
};

#endif // SUPPLIERHOMEWINDOWN_H
