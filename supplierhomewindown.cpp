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
    connect(ui->comboBox_2, &QComboBox::currentIndexChanged, this, &SupplierHomeWindowN::on_comboBox_currentIndexChanged);
}

SupplierHomeWindowN::~SupplierHomeWindowN()
{
    delete ui;
}

void SupplierHomeWindowN::on_exitButton_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void SupplierHomeWindowN::on_addButton_clicked()
{
    const auto name = ui->lineEdit->text();
    const auto vendorCode = ui->lineEdit_2->text();
    const auto count = ui->lineEdit_13->text();
    const auto price = ui->lineEdit_3->text();
    const auto vendorLabel = ui->vendorLabel->text();
    bool AddSupplyingSuccess = false;

    if (name.trimmed().isEmpty() || vendorCode.trimmed().isEmpty() || price.trimmed().isEmpty() || count.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поля не могут быть пустыми!");
        return;
    }

    try {
        if (db.isVendorCodeExists(vendorCode)) {
            QMessageBox::warning(this, "Ошибка", "Товар с таким артикулом уже существует!");
            return;
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
        ui->lineEdit->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
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
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_16->clear();

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

    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_16->clear();

    if (!supplyData.isEmpty()) {
        if (senderComboBox == ui->comboBox) {
            if (supplyData.size() >= 1) ui->lineEdit_4->setText(supplyData[0]);
            if (supplyData.size() >= 2) ui->lineEdit_14->setText(supplyData[1]);
            if (supplyData.size() >= 3) ui->lineEdit_5->setText(supplyData[2]);
            if (supplyData.size() >= 4) ui->lineEdit_6->setText(supplyData[3]);
        } else if (senderComboBox == ui->comboBox_2) {
            if (supplyData.size() >= 1) ui->lineEdit_7->setText(supplyData[0]);
            if (supplyData.size() >= 2) ui->lineEdit_16->setText(supplyData[1]);
            if (supplyData.size() >= 3) ui->lineEdit_8->setText(supplyData[2]);
            if (supplyData.size() >= 4) ui->lineEdit_9->setText(supplyData[3]);
        }
    }
}

void SupplierHomeWindowN::on_changeButton_clicked()
{
    QString vendor = ui->vendorLabel->text();

    QString supplyName = ui->comboBox->currentText();
    QString oldVendorCode = ui->lineEdit_5->text();
    QString newName = ui->lineEdit_10->text();
    QString newCount = ui->lineEdit_15->text();
    QString newVendorCode = ui->lineEdit_11->text();
    QString newPrice = ui->lineEdit_12->text();

    if (supplyName.isEmpty() || newName.isEmpty() || newVendorCode.isEmpty() || newPrice.isEmpty() || newCount.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поля не могут быть пустыми!");
        return;
    }

    bool updateSuccess = false;
    try {
        if (db.isVendorCodeExists(newVendorCode)) {
            QMessageBox::warning(this, "Ошибка", "Товар с таким артикулом уже существует!");
            return;
        }
    } catch (DbCritical& e) {
        QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
        QCoreApplication::quit();
        return;
    }
    try
    {
        updateSuccess = db.updateSupply(vendor, oldVendorCode, newName, newCount, newVendorCode, newPrice);
    }
    catch(DbCritical &e)
    {
        QMessageBox::critical(this, "Ошибка", "База данных не открыта!\nОбратитесь к администратору!");
        QCoreApplication::quit();
    }

    if (updateSuccess) {
        QMessageBox::information(this, "Уведомление", "Данные о товаре успешно обновлены!");
        ui->comboBox->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_10->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_12->clear();
        ui->lineEdit_14->clear();
        ui->lineEdit_15->clear();
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось обновить данные о товаре!");
    }


}


void SupplierHomeWindowN::on_deleteButton_clicked()
{
    QString vendor = ui->vendorLabel->text();
    QString vendorCode = ui->lineEdit_8->text();

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
            //on_tabWidget_currentChanged(ui->tabWidget->currentIndex());
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось удалить товар!");
        }
    }
}
