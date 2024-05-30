#include "adminhomewindown.h"
#include "ui_adminhomewindown.h"
#include "entrywindow.h"

#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QFile>

AdminHomeWindowN::AdminHomeWindowN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminHomeWindowN)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->purchaseHistoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->priceChangeHistoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->telephoneNumber->setInputMask("+7-000-000-00-00;");
    loadPurchaseHistory();
    loadPriceChangeHistory();
}

AdminHomeWindowN::~AdminHomeWindowN()
{
    delete ui;
}

void AdminHomeWindowN::on_exitButton_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void AdminHomeWindowN::on_regUser_clicked()
{
    const auto surname = ui->surname->text();
    const auto name = ui->name->text();
    const auto patronymic = ui->patronymic->text();
    const auto address = ui->address->text();
    const auto telephoneNumber = ui->telephoneNumber->text();
    const auto login = ui->login->text();
    const auto password = ui->password->text();
    const auto role = ui->comboBox->currentText();
    bool RegSuccess = false;

    if (surname.isEmpty() || name.isEmpty() || patronymic.isEmpty() || password.isEmpty() || address.isEmpty() || telephoneNumber.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Поля не могут быть пустыми!");
        return;
    }

    try
    {
        RegSuccess = db.addUserByAdmin(surname, name, patronymic, address, telephoneNumber,login, password, role);
    }
    catch(DbCritical &e)
    {
        QMessageBox::critical(this,QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    if (RegSuccess == true)
    {
        QMessageBox::information(this,"Уведомление","Учетная запись успешно создана!");
        return;
    }

    if (RegSuccess == false)
        QMessageBox::warning(this,"Ошибка","Неудачная регистрация!");

}

void AdminHomeWindowN::readUsersFromFile(const QString& filename)
{
    model->removeRows(0, model->rowCount());

    QStringList headers = {"Фамилия", "Имя", "Отчество", "Адрес", "Телефон", "Логин", "Пароль", "Роль"};
    model->setHorizontalHeaderLabels(headers);

    QStringList userData;
    try
    {
        userData = db.loadUsersFromDataBase(filename);
    }
    catch (DbCritical& e)
    {
        QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    int row = 0;
    foreach (QString line, userData) {
        QStringList userData = line.split(",");
        QList<QStandardItem*> items;
        foreach (QString data, userData) {
            items.append(new QStandardItem(data));
        }
        model->insertRow(row, items);
        row++;
    }
}

void AdminHomeWindowN::on_tabWidget_currentChanged(int index)
{
    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    readUsersFromFile("Users.csv");
}


void AdminHomeWindowN::on_deleteButton_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите ячейку для удаления строки.");
        return;
    }

    int row = selectedIndexes.first().row();

    QString surname = model->data(model->index(row, 0)).toString();
    QString name = model->data(model->index(row, 1)).toString();
    QString patronymic = model->data(model->index(row, 2)).toString();
    QString address = model->data(model->index(row, 3)).toString();
    QString phone = model->data(model->index(row, 4)).toString();
    QString password = model->data(model->index(row, 5)).toString();
    QString login = model->data(model->index(row, 6)).toString();
    QString role = model->data(model->index(row, 7)).toString();

    QMessageBox::StandardButton answer = QMessageBox::question(this, "Подтверждение", "Вы действительно хотите удалить пользователя:\n"
                                                                                          + surname + " " + name + " " + patronymic + "\n"
                                                                                          + address + ", " + phone + ", " + role + "?",
                                                               QMessageBox::Yes | QMessageBox::No);

    if (answer == QMessageBox::Yes) {
        model->removeRow(row);
        try
        {
            db.deleteUserFromFile(surname, name, patronymic, address, phone, login, password, role);
        }
        catch (DbCritical& e)
        {
            QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        }
    }
}

void AdminHomeWindowN::loadPurchaseHistory()
{
    purchaseHistoryModel = new QStandardItemModel(this);
    purchaseHistoryModel->setHorizontalHeaderLabels(QStringList() << "Артикул" << "Количество" << "Дата" << "ФИО покупателя");

    QStringList purchaseData;
    try {
        purchaseData = db.loadPurchasesFromDatabase("Purchases.csv");
    } catch (DbCritical &e) {
        QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    QStringList userData;
    try {
        userData = db.loadUsersFromDataBase("Users.csv");
    } catch (DbCritical &e) {
        QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    for (const QString& line : purchaseData) {
        QStringList purchaseDetails = line.split(",");
        if (purchaseDetails.size() >= 4) {
            QString vendorCode = purchaseDetails[0];
            QString quantity = purchaseDetails[1];
            QString date = purchaseDetails[2];
            QString customerName = purchaseDetails[3];

            QString fullCustomerName;
            for (const QString& userLine : userData) {
                QStringList userDetails = userLine.split(",");
                if (userDetails.size() >= 8 && userDetails[7] == "Buyer" && userDetails[0] == customerName) {
                    fullCustomerName = userDetails[0] + " " + userDetails[1] + " " + userDetails[2];
                    break;
                }
            }

            QList<QStandardItem*> rowItems;
            rowItems << new QStandardItem(vendorCode)
                     << new QStandardItem(quantity)
                     << new QStandardItem(date)
                     << new QStandardItem(fullCustomerName);
            purchaseHistoryModel->appendRow(rowItems);
        }
    }

    ui->purchaseHistoryTable->setModel(purchaseHistoryModel);
    ui->purchaseHistoryTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void AdminHomeWindowN::loadPriceChangeHistory()
{
    QStringList priceChangeData;
    try
    {
        priceChangeData = db.loadPriceChangeHistory("PriceChangeHistory.csv");
    } catch (DbCritical &e) {
        QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    priceChangeHistoryModel = new QStandardItemModel(this);
    priceChangeHistoryModel->setHorizontalHeaderLabels(QStringList() << "Артикул" << "Дата" << "Старая цена" << "Новая цена" << "Разница в цене");

    for (const QString& line : priceChangeData) {
        QStringList priceChangeDetails = line.split(",");
        if (priceChangeDetails.size() >= 5) {
            QString vendorCode = priceChangeDetails[0];
            QString date = priceChangeDetails[1];
            QString oldPrice = priceChangeDetails[2];
            QString newPrice = priceChangeDetails[3];
            QString priceDifference = priceChangeDetails[4];

            QList<QStandardItem*> rowItems;
            rowItems << new QStandardItem(vendorCode)
                     << new QStandardItem(date)
                     << new QStandardItem(oldPrice)
                     << new QStandardItem(newPrice)
                     << new QStandardItem(priceDifference);
            priceChangeHistoryModel->appendRow(rowItems);
        }
    }

    ui->priceChangeHistoryTable->setModel(priceChangeHistoryModel);
    ui->priceChangeHistoryTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
