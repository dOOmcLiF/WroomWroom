#ifndef ENTRYWINDOW_H
#define ENTRYWINDOW_H

#include <QMainWindow>
#include <adminhomewindown.h>
#include <buyerhomewindown.h>
#include <supplierhomewindown.h>
#include <regwindown.h>
#include <database.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void showAdminWindow(const QString& surname);
    void showSupplierWindow(const QString& surname);
    void showBuyerWindow();
    void showRegWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    AdminHomeWindowN ahw;
    BuyerHomeWindowN bhw;
    SupplierHomeWindowN shw;
    RegWindowN rw;
    DataBase db;
};
#endif // ENTRYWINDOW_H
