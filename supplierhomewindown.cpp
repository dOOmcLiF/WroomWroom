#include "supplierhomewindown.h"
#include "ui_supplierhomewindown.h"
#include "entrywindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QComboBox>

SupplierHomeWindowN::SupplierHomeWindowN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SupplierHomeWindowN)
{
    ui->setupUi(this);
    this->setWindowTitle("WroomWroom");
    connect(ui->comboBox_2, &QComboBox::currentIndexChanged, this, &SupplierHomeWindowN::on_comboBox_currentIndexChanged);

    nameValidator = new QRegularExpressionValidator(QRegularExpression("^[a-zA-Zа-яА-Я0-9\\s]+$"), this);
    vendorCodeValidator = new QRegularExpressionValidator(QRegularExpression("^[a-zA-Z0-9]+$"), this);
    quantityValidator = new QIntValidator(this);
    priceValidator = new QDoubleValidator(this);
    priceValidator->setLocale(QLocale::English);
    priceValidator->setNotation(QDoubleValidator::StandardNotation);
    priceValidator->setDecimals(2);

    ui->name->setValidator(nameValidator);
    ui->vendorCode->setValidator(vendorCodeValidator);
    ui->quantity->setValidator(quantityValidator);
    ui->price->setValidator(priceValidator);

    ui->newName->setValidator(nameValidator);
    ui->newVendorCode->setValidator(vendorCodeValidator);
    ui->newQuantity->setValidator(quantityValidator);
    ui->newPrice->setValidator(priceValidator);
}

SupplierHomeWindowN::~SupplierHomeWindowN()
{
    delete ui;
    delete nameValidator;
    delete vendorCodeValidator;
    delete quantityValidator;
    delete priceValidator;
}

void SupplierHomeWindowN::on_exitButton_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void SupplierHomeWindowN::on_addButton_clicked()
{
    const auto name = ui->name->text();
    const auto vendorCode = ui->vendorCode->text();
    const auto count = ui->quantity->text();
    const auto price = ui->price->text();
    const auto vendorLabel = ui->vendorLabel->text();
    bool AddSupplyingSuccess = false;

    if (name.trimmed().isEmpty() || vendorCode.trimmed().isEmpty() || price.trimmed().isEmpty() || count.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поля не могут быть пустыми!");
        return;
    }

    try {
        if (db.isVendorCodeExists(vendorCode)) {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Предупреждение", "Товар с таким артикулом уже существует!\nХотите добавить новый товар с таким же артикулом, но с другими ценой и количеством?",
                                                                      QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::No) {
                return;
            }
        }
    } catch (DbCritical& e) {
        QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
        QCoreApplication::quit();
        return;
    }

    try {
        AddSupplyingSuccess = db.addSupplying(name, count, vendorCode, price, vendorLabel);
    } catch (DbCritical& e) {
        QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
        QCoreApplication::quit();
        return;
    }

    if (AddSupplyingSuccess == false) {
        QMessageBox::warning(this, "Ошибка", "Неудачное добавление товара!");
    } else {
        QMessageBox::information(this, "Уведомление", "Товар успешно добавлен!");
        ui->name->clear();
        ui->quantity->clear();
        ui->vendorCode->clear();
        ui->price->clear();
    }
}

void SupplierHomeWindowN::setLabel_2(const QString& x)
{
    ui->vendorLabel->setText(x);
}

void SupplierHomeWindowN::on_tabWidget_currentChanged(int index)
{
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->oldName->clear();
    ui->oldVendorCode->clear();
    ui->oldPrice->clear();
    ui->name_2->clear();
    ui->vendorCode_2->clear();
    ui->price_2->clear();
    ui->oldQuantity->clear();
    ui->quantity_2->clear();

    QString vendor = ui->vendorLabel->text();
    QStringList supplies;
    try {
        supplies = db.getSuppliesForVendor(vendor);
    } catch (DbCritical& e) {
        QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
        QCoreApplication::quit();
    }
    if (index == 1) {
        for (const QString& supply : supplies) {
            QStringList parts = supply.split(",");
            if (parts.size() >= 2) {
                ui->comboBox->addItem(parts[0], parts[1]);
            }
        }
    } else if (index == 2) {
        for (const QString& supply : supplies) {
            QStringList parts = supply.split(",");
            if (parts.size() >= 2) {
                ui->comboBox_2->addItem(parts[0], parts[1]);
            }
        }
    }
}


void SupplierHomeWindowN::on_comboBox_currentIndexChanged(int index)
{
    QComboBox* senderComboBox = qobject_cast<QComboBox*>(sender());
    if (!senderComboBox) {
        return;
    }

    QString vendor = ui->vendorLabel->text();
    QString currentText = senderComboBox->itemText(index);
    QString vendorCode = senderComboBox->itemData(index).toString();

    QStringList supplyData;
    try {
        supplyData = db.getSupplyDataForVendor(vendor, currentText, vendorCode);
    } catch (DbCritical& e) {
        QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
        QCoreApplication::quit();
    }

    ui->oldName->clear();
    ui->oldVendorCode->clear();
    ui->oldPrice->clear();
    ui->name_2->clear();
    ui->vendorCode_2->clear();
    ui->price_2->clear();
    ui->oldQuantity->clear();
    ui->quantity_2->clear();

    if (!supplyData.isEmpty()) {
        if (senderComboBox == ui->comboBox) {
            if (supplyData.size() >= 1) ui->oldName->setText(supplyData[0]);
            if (supplyData.size() >= 2) ui->oldQuantity->setText(supplyData[1]);
            if (supplyData.size() >= 3) ui->oldVendorCode->setText(supplyData[2]);
            if (supplyData.size() >= 4) ui->oldPrice->setText(supplyData[3]);
        } else if (senderComboBox == ui->comboBox_2) {
            if (supplyData.size() >= 1) ui->name_2->setText(supplyData[0]);
            if (supplyData.size() >= 2) ui->quantity_2->setText(supplyData[1]);
            if (supplyData.size() >= 3) ui->vendorCode_2->setText(supplyData[2]);
            if (supplyData.size() >= 4) ui->price_2->setText(supplyData[3]);
        }
    }
}

void SupplierHomeWindowN::on_changeButton_clicked()
{
    QString vendor = ui->vendorLabel->text();

    QString supplyName = ui->comboBox->currentText();
    QString oldVendorCode = ui->oldVendorCode->text();
    QString newName = ui->newName->text();
    QString newCount = ui->newQuantity->text();
    QString newVendorCode = ui->newVendorCode->text();
    QString newPrice = ui->newPrice->text();

    if (supplyName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите товар для изменения!");
        return;
    }

    if (oldVendorCode != newVendorCode) {
        try {
            if (db.isVendorCodeExists(newVendorCode)) {
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Предупреждение", "Товар с таким новым артикулом уже существует!\nХотите обновить товар с таким артикулом?",
                                                                          QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) {
                    return;
                }
            }
        } catch (DbCritical& e) {
            QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
            QCoreApplication::quit();
            return;
        }
    }

    bool updateSuccess = false;
    try {
        updateSuccess = db.updateSupply(vendor, oldVendorCode, newName, newCount, newVendorCode, newPrice);
    } catch (DbCritical& e) {
        QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
        QCoreApplication::quit();
        return;
    }

    if (updateSuccess) {
        QMessageBox::information(this, "Уведомление", "Данные о товаре успешно обновлены!");
        ui->comboBox->clear();
        ui->oldName->clear();
        ui->oldVendorCode->clear();
        ui->oldPrice->clear();
        ui->newName->clear();
        ui->newVendorCode->clear();
        ui->newPrice->clear();
        ui->oldQuantity->clear();
        ui->newQuantity->clear();
        on_tabWidget_currentChanged(ui->tabWidget->currentIndex());
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось обновить данные о товаре!");
    }
}


void SupplierHomeWindowN::on_deleteButton_clicked()
{
    QString vendor = ui->vendorLabel->text();
    QString vendorCode = ui->vendorCode_2->text();

    if (vendorCode.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите товар для удаления!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение", "Вы действительно хотите удалить этот товар?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        bool deleteSuccess = false;
        try
        {
            deleteSuccess = db.deleteSupply(vendor, vendorCode);
        }
        catch (DbCritical& e)
        {
            QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
            QCoreApplication::quit();
        }

        if (deleteSuccess) {
            QMessageBox::information(this, "Уведомление", "Товар успешно удален!");
            on_tabWidget_currentChanged(ui->tabWidget->currentIndex());
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось удалить товар!");
        }
    }
}
