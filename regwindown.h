#ifndef REGWINDOWN_H
#define REGWINDOWN_H

#include "database.h"

#include <QMainWindow>

namespace Ui {
class RegWindowN;
}

class RegWindowN : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegWindowN(QWidget *parent = nullptr);
    ~RegWindowN();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();


private:
    Ui::RegWindowN *ui;
    DataBase db;
};

#endif // REGWINDOWN_H
