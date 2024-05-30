#include "regwindown.h"
#include "ui_regwindown.h"
#include "database.h"
#include "entrywindow.h"

#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QRegularExpression>

RegWindowN::RegWindowN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegWindowN)
{
    ui->setupUi(this);
    ui->phoneNumber->setInputMask("+7-000-000-00-00;");
}

RegWindowN::~RegWindowN()
{
    delete ui;
}

void RegWindowN::on_pushButton_clicked()
{
    const auto surname = ui->surname->text();
    const auto name = ui->name->text();
    const auto patronymic = ui->patronymic->text();
    const auto address = ui->address->text();
    const auto telephoneNumber = ui->phoneNumber->text();
    const auto login = ui->login->text();
    const auto password = ui->repeatPassword->text();
    const auto repeatPassword = ui->password->text();


    bool RegSuccess = false;
    bool SameLogins = false;

    if(surname.isEmpty() || name.isEmpty() || patronymic.isEmpty() || password.isEmpty() || repeatPassword.isEmpty() || address.isEmpty() || telephoneNumber.isEmpty() || login.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Поля не могут быть пустыми!");
        return;
    }

    if (password != repeatPassword)
    {
        QMessageBox::warning(this,"Ошибка","Пароли не совпадают");
        return;
    }

    try
    {
        SameLogins = db.checkSameLogins(login);
    }
    catch(DbCritical &e)
    {
        QMessageBox::critical(this,QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    if (SameLogins)
    {
        QMessageBox::warning(this,QString("Ошибка"), QString("Введённый логин уже используется!"));
        return;
    }

    try
    {
        RegSuccess = db.addUser(surname, name, patronymic, address, telephoneNumber, login, password);
    }
    catch(DbCritical &e)
    {
        QMessageBox::critical(this,QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    if (RegSuccess == true)
    {
        QMessageBox::information(this,"Уведомление","Учетная запись успешно создана!");
        this->close();
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
    }

    if (RegSuccess == false)
        QMessageBox::warning(this,"Ошибка","Неудачная регистрация!");

}

void RegWindowN::on_toolButton_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}
