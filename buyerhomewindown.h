#ifndef BUYERHOMEWINDOWN_H
#define BUYERHOMEWINDOWN_H

#include "database.h"

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSpinBox>
#include <QListWidgetItem>

namespace Ui {
class BuyerHomeWindowN;
}

class BuyerHomeWindowN : public QMainWindow
{
    Q_OBJECT

public:
    explicit BuyerHomeWindowN(QWidget *parent = nullptr);
    ~BuyerHomeWindowN();
    void setNameLabel(const QString& x);

private slots:
    void on_exitButton_clicked();

    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_payButton_clicked();

    void onItemDoubleClicked(QListWidgetItem *item);

    void on_backButton_clicked();

    void showSuccessDialog();

    void on_clearCart_clicked();

    void on_deleteProductFromCart_clicked();

private:
    Ui::BuyerHomeWindowN *ui;
    QStandardItemModel* cartModel;
    DataBase db;
    void loadSupplies();
    void reloadSupplies(int index);
    double calculateTotalPrice();
    void updateTotalPrice();
};

#endif // BUYERHOMEWINDOWN_H
