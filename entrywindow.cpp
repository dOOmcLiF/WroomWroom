#include "entrywindow.h"
#include "ui_entrywindow.h"
#include "database.h"

#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("WroomWroom");

    ui->password->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const auto login = ui->login->text();
    const auto password = ui->password->text();
    int AuthSuccess = 0;

    if(login.trimmed().isEmpty() || password.trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Поля не могут быть пустыми!");
        return;
    }

    try
    {
        AuthSuccess = db.checkUsersDB(login, password);
    }
    catch (DbCritical &e)
    {
        QMessageBox::critical(this,QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }
    catch (UserNotFound &e)
    {
        QMessageBox::warning(this,"Ошибка","Неправильный логин или пароль!\nПроверьте правильность введённых данных!");
        return;
    }

    switch (AuthSuccess) {
    case 1:
        this->hide();
        ahw.show();
        break;
    case 2:
        this->hide();
        shw.setLabel_2(login);
        shw.show();
        break;
    case 3:
        this->hide();
        bhw.setNameLabel(login);
        bhw.show();
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    rw.show();
}


