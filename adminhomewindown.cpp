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
    this->setWindowTitle("WroomWroom");
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->purchaseHistoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->priceChangeHistoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->telephoneNumber->setInputMask("+7-000-000-00-00;");
    loadPurchaseHistory();
    loadPriceChangeHistory();

    ui->company->hide();
    loginX = ui->login->x();
    loginY = ui->login->y();
    passwordX = ui->password->x();
    passwordY = ui->password->y();

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AdminHomeWindowN::comboBoxIndexChanged);
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
    const auto company = ui->company->text();
    const auto email = ui->email->text();
    bool RegSuccess = false;
    bool SameLogins = false;
    bool RegSupplierSuccess = false;

    if (surname.isEmpty() || name.isEmpty() || patronymic.isEmpty() || password.isEmpty() || address.isEmpty() || telephoneNumber.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Поля не могут быть пустыми!");
        return;
    }

    if (ui->comboBox->currentIndex() == 1)
    {
        if (surname.isEmpty() || name.isEmpty() || patronymic.isEmpty() || password.isEmpty() || address.isEmpty() || telephoneNumber.isEmpty() || company.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Поля не могут быть пустыми!");
            return;
        }
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
        RegSuccess = db.addUserByAdmin(surname, name, patronymic, address, telephoneNumber,login, password, role, email);
    }
    catch(DbCritical &e)
    {
        QMessageBox::critical(this,QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    if (ui->comboBox->currentIndex() == 1)
    {
        try
        {
            RegSupplierSuccess = db.addSupplierCompany(surname, name, patronymic, company, address, telephoneNumber, login);
        }
        catch(DbCritical &e)
        {
            QMessageBox::critical(this,QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
            QCoreApplication::quit();
        }
    }

    if (RegSuccess == true)
    {
        QMessageBox::information(this,"Уведомление","Учетная запись успешно создана!");
        ui->surname->clear();
        ui->name->clear();
        ui->patronymic->clear();
        ui->address->clear();
        ui->telephoneNumber->clear();
        ui->login->clear();
        ui->password->clear();
        ui->email->clear();
        on_tabWidget_currentChanged(ui->tabWidget->currentIndex());
        return;
    }

    if (RegSupplierSuccess == true)
    {
        QMessageBox::information(this,"Уведомление","Учетная запись успешно создана!");
        ui->surname->clear();
        ui->name->clear();
        ui->patronymic->clear();
        ui->address->clear();
        ui->telephoneNumber->clear();
        ui->login->clear();
        ui->password->clear();
        ui->company->clear();
        ui->email->clear();
        on_tabWidget_currentChanged(ui->tabWidget->currentIndex());
        return;
    }

    if (RegSuccess == false)
        QMessageBox::warning(this,"Ошибка","Неудачная регистрация!");

}

void AdminHomeWindowN::readUsersFromFile()
{
    model->removeRows(0, model->rowCount());

    QStringList headers = {"Фамилия", "Имя", "Отчество", "Адрес", "Телефон", "Логин", "Пароль", "Роль"};
    model->setHorizontalHeaderLabels(headers);

    QStringList userData;
    try
    {
        userData = db.loadUsersFromDataBase();
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
    readUsersFromFile();
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
    QString login = model->data(model->index(row, 5)).toString();
    QString password = model->data(model->index(row, 6)).toString();
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
        purchaseData = db.loadPurchasesFromDatabase();
    } catch (DbCritical &e) {
        QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    QStringList userData;
    try {
        userData = db.loadUsersFromDataBase();
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
            QString customerLogin = purchaseDetails[3];

            QString fullCustomerName;
            for (const QString& userLine : userData) {
                QStringList userDetails = userLine.split(",");
                if (userDetails.size() >= 8 && userDetails[7] == "Buyer" && userDetails[5] == customerLogin) {
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
        priceChangeData = db.loadPriceChangeHistory();
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

void AdminHomeWindowN::comboBoxIndexChanged(int index)
{
    int indexOfSupplierOption = 1;
    if (index == indexOfSupplierOption) {
        ui->company->setGeometry(loginX, loginY, ui->company->width(), ui->company->height());
        ui->company->show();

        ui->login->move(loginX, loginY + ui->company->height() + 10);
        ui->password->move(passwordX, loginY + ui->company->height() + 10 + ui->login->height() + 10);
    } else {
        ui->company->hide();
        ui->login->move(loginX, loginY);
        ui->password->move(passwordX, passwordY);
    }
}
