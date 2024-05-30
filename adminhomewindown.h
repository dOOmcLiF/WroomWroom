#ifndef ADMINHOMEWINDOWN_H
#define ADMINHOMEWINDOWN_H

#include "database.h"

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class AdminHomeWindowN;
}

class AdminHomeWindowN : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminHomeWindowN(QWidget *parent = nullptr);
    void readUsersFromFile(const QString& filename);
    ~AdminHomeWindowN();

private slots:

    void on_exitButton_clicked();

    void on_regUser_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_deleteButton_clicked();

private:
    Ui::AdminHomeWindowN *ui;
    DataBase db;
    QStandardItemModel *model;
    void loadPurchaseHistory();
    QStandardItemModel *purchaseHistoryModel;
    void loadPriceChangeHistory();
    QStandardItemModel *priceChangeHistoryModel;
    int loginX, loginY;
    int passwordX, passwordY;
    void comboBoxIndexChanged(int index);
};

#endif // ADMINHOMEWINDOWN_H
