#include "buyerhomewindown.h"
#include "ui_buyerhomewindown.h"
#include "entrywindow.h"

#include <QTableView>
#include <QStandardItem>
#include <QMessageBox>
#include <QWindow>
#include <QInputDialog>
#include <QFont>
#include <QValidator>
#include <QDate>
#include <QPoint>

BuyerHomeWindowN::BuyerHomeWindowN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BuyerHomeWindowN)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::WindowMinMaxButtonsHint);
    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QFont font = ui->listWidget->font();
    font.setPointSize(14);
    ui->listWidget->setFont(font);

    QRegularExpression cardNumberRegex("^\\d{4}(\\s?\\d{4}){3}$");
    QRegularExpressionValidator *cardNumberValidator = new QRegularExpressionValidator(cardNumberRegex, this);
    ui->cardNumber->setValidator(cardNumberValidator);

    QRegularExpression expiryDateRegex("^(0[1-9]|1[0-2])\\/\\d{2}$");
    QRegularExpressionValidator *expiryDateValidator = new QRegularExpressionValidator(expiryDateRegex, this);
    ui->monthYear->setValidator(expiryDateValidator);

    QIntValidator *cvcValidator = new QIntValidator(100, 999, this);
    ui->cvcCvv->setValidator(cvcValidator);

    QRegularExpression eMailRegex("\\b[a-zA-Z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}\\b");
    QRegularExpressionValidator *eMailValidator = new QRegularExpressionValidator(eMailRegex, this);
    ui->email->setValidator(eMailValidator);

    ui->payButton->setEnabled(false);

    updateTotalPrice();
    loadSupplies();

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &BuyerHomeWindowN::reloadSupplies);
    connect(ui->tableView, &QTableView::doubleClicked, this, &BuyerHomeWindowN::on_tableView_doubleClicked);
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &BuyerHomeWindowN::onItemDoubleClicked);
    connect(ui->listWidget, &QListWidget::itemChanged, this, &BuyerHomeWindowN::updateTotalPrice);
    connect(ui->payButton_2, &QPushButton::clicked, this, &BuyerHomeWindowN::showSuccessDialog);
}

BuyerHomeWindowN::~BuyerHomeWindowN()
{
    delete ui;
}

void BuyerHomeWindowN::reloadSupplies(int index)
{
    Q_UNUSED(index);
    loadSupplies();
}

void BuyerHomeWindowN::setNameLabel(const QString& x)
{
    ui->nameLabel->setText(x);
}

void BuyerHomeWindowN::on_exitButton_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void BuyerHomeWindowN::loadSupplies()
{
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(QStringList() << "Название" << "Количество" << "Артикул" << "Цена" << "Поставщик");

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList suppliesData;
    try
    {
        suppliesData = db.loadSuppliesFromDataBase("Supplies.csv");
    }
    catch (DbCritical &e)
    {
        QMessageBox::critical(this,QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
        return;
    }

    for (const QString& line : suppliesData) {
        QStringList supplyData = line.split(",");
        if (supplyData.size() >= 5) {
            QList<QStandardItem*> rowItems;
            for (const QString& item : supplyData.mid(0, 5)) {
                rowItems.append(new QStandardItem(item));
            }
            model->appendRow(rowItems);
        }
    }
}


void BuyerHomeWindowN::on_pushButton_clicked()
{
    int vendorCode = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 2)).toInt();

    if (vendorCode == 0) {
        QMessageBox::information(this, "Ошибка", "Выделите товар для добавления!");
        return;
    }

    QStringList suppliesData;
    try {
        suppliesData = db.loadSuppliesFromDataBase("Supplies.csv");
    } catch (DbCritical &e) {
        QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
    }

    bool itemFound = false;
    for (const QString& line : suppliesData) {
        QStringList supplyData = line.split(",");
        if (supplyData.size() >= 5) {
            int vendorCodeFromData = supplyData[2].toInt();
            if (vendorCodeFromData == vendorCode) {
                int quantity = supplyData[1].toInt();
                if (quantity == 0) {
                    QMessageBox::warning(this, "Ошибка", "Товар отсутствует на складе.");
                    return;
                }
                QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
                item->setData(Qt::UserRole, vendorCodeFromData);
                item->setText(supplyData[0] + " | Количество: 1 | Цена: " + supplyData[3]);
                ui->listWidget->addItem(item);
                itemFound = true;
            }
        }
    }

    if (itemFound) {
        QMessageBox::information(this, "Успех", "Товар успешно добавлен в корзину!");
    } else {
        QMessageBox::warning(this, "Ошибка", "Товар не найден в базе данных.");
    }

    if (ui->listWidget->count() > 0) {
        ui->payButton->setEnabled(true);
    }
}

void BuyerHomeWindowN::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString vendorName = index.sibling(index.row(), 4).data().toString();
    QStringList userData;
    try {
        userData = db.loadUsersFromDataBase("Users.csv");
    } catch (DbCritical &e) {
        QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
        QCoreApplication::quit();
        return;
    }

    QString vendorInfo;
    for (const QString& line : userData) {
        QStringList userDetails = line.split(",");
        if (userDetails.size() >= 7 && userDetails[6] == "Supplier" && userDetails[0] == vendorName) {
            vendorInfo = "Название: " + userDetails[0] + "\n"
                         "Адрес: " + userDetails[3] + "\n"
                         "Телефон: " + userDetails[4];
            break;
        }
    }

    if (!vendorInfo.isEmpty()) {
        QMessageBox::information(this, "Информация о поставщике", vendorInfo);
        return;
    } else {
        QMessageBox::warning(this, "Ошибка", "Информация о поставщике не найдена.");
    }
}

void BuyerHomeWindowN::onItemDoubleClicked(QListWidgetItem *item)
{
    bool ok;
    QString itemText = item->text();
    QStringList parts = itemText.split(" | ");
    if (parts.size() >= 3) {
        int vendorCode = item->data(Qt::UserRole).toInt();
        QStringList suppliesData;
        try {
            suppliesData = db.loadSuppliesFromDataBase("Supplies.csv");
        } catch (DbCritical &e) {
            QMessageBox::critical(this, QString("Ошибка"), QString("База данных не открыта!\nОбратитесь к администратору!"));
            QCoreApplication::quit();
            return;
        }

        int currentQuantityInStock = 0;
        for (const QString& line : suppliesData) {
            QStringList supplyData = line.split(",");
            if (supplyData.size() >= 5 && supplyData[2].toInt() == vendorCode) {
                currentQuantityInStock = supplyData[1].toInt();
                break;
            }
        }

        QStringList quantityParts = parts[1].split(": ");
        if (quantityParts.size() >= 2) {
            int currentQuantity = quantityParts[1].toInt();
            int newQuantity = QInputDialog::getInt(this, "Изменить количество", "Введите новое количество:", currentQuantity, 0, currentQuantityInStock, 1, &ok);
            if (ok) {
                if (newQuantity == 0) {
                    int row = ui->listWidget->row(item);
                    QMessageBox::StandardButton reply = QMessageBox::question(this, "Удалить товар",
                                                                              "Вы действительно хотите удалить товар из корзины?",
                                                                              QMessageBox::Yes | QMessageBox::No);
                    if (reply == QMessageBox::Yes) {
                        ui->listWidget->takeItem(row);
                        delete item;
                        updateTotalPrice();
                    }
                } else if (newQuantity > currentQuantityInStock) {
                    QMessageBox::warning(this, "Ошибка", "Введенное количество превышает наличие товара на складе.");
                } else {
                    int row = ui->listWidget->row(item);
                    ui->listWidget->takeItem(row);
                    delete item;

                    QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
                    newItem->setData(Qt::UserRole, vendorCode);
                    QString newItemText = parts[0] + " | Количество: " + QString::number(newQuantity) + " | " + parts[2];
                    newItem->setText(newItemText);
                    ui->listWidget->insertItem(row, newItem);
                    updateTotalPrice();
                }
            }
        }
    }
}

double BuyerHomeWindowN::calculateTotalPrice()
{
    double totalPrice = 0.0;

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        QString itemText = item->text();
        QStringList parts = itemText.split(" | ");

        if (parts.size() >= 3) {
            QStringList quantityParts = parts[1].split(": ");
            if (quantityParts.size() >= 2) {
                int quantity = quantityParts[1].toInt();
                QStringList priceParts = parts[2].split(": ");
                if (priceParts.size() >= 2) {
                    double price = priceParts[1].toDouble();
                    totalPrice += quantity * price;
                }
            }
        }
    }

    return totalPrice;
}

void BuyerHomeWindowN::updateTotalPrice()
{
    double totalPrice = calculateTotalPrice();
    ui->totalPrice->setText(QString("₽%1").arg(totalPrice, 0, 'f', 2));
}

void BuyerHomeWindowN::on_payButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void BuyerHomeWindowN::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void BuyerHomeWindowN::showSuccessDialog()
{
    if (ui->cardNumber->text().isEmpty() ||
        ui->monthYear->text().isEmpty() ||
        ui->cvcCvv->text().isEmpty() ||
        ui->email->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля!");
        return;
    }

    QString cardNumber = ui->cardNumber->text();
    int cardNumberPos = 0;
    QValidator::State cardNumberState = ui->cardNumber->validator()->validate(cardNumber, cardNumberPos);
    if (cardNumberState != QValidator::Acceptable) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат номера карты!");
        return;
    }

    QString expiryDate = ui->monthYear->text();
    int expiryDatePos = 0;
    QValidator::State expiryDateState = ui->monthYear->validator()->validate(expiryDate, expiryDatePos);
    if (expiryDateState != QValidator::Acceptable) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат срока действия!");
        return;
    }

    QString cvc = ui->cvcCvv->text();
    int cvcPos = 0;
    QValidator::State cvcState = ui->cvcCvv->validator()->validate(cvc, cvcPos);
    if (cvcState != QValidator::Acceptable) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат CVC!");
        return;
    }

    QString email = ui->email->text();
    QRegularExpression emailRegex("\\b[a-zA-Z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}\\b");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат email!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение покупки",
                                                              "Вы уверены, что хотите совершить покупку?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QStringList purchaseData;
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QListWidgetItem *item = ui->listWidget->item(i);
            QString itemText = item->text();
            QStringList parts = itemText.split(" | ");
            if (parts.size() >= 3) {
                QStringList quantityParts = parts[1].split(": ");
                if (quantityParts.size() >= 2) {
                    int quantity = quantityParts[1].toInt();
                    QString vendorCode = QString::number(item->data(Qt::UserRole).toInt());
                    purchaseData.append(vendorCode + "," + QString::number(quantity));
                }
            }
        }

        QDate currentDate = QDate::currentDate();
        QString dateString = currentDate.toString("dd.MM.yyyy");

        QString customerName = ui->nameLabel->text();

        for (const QString &purchaseItem : purchaseData) {
            QStringList parts = purchaseItem.split(",");
            if (parts.size() == 2) {
                db.savePurchaseToDatabase("Purchases.csv", parts[0], dateString, customerName, parts[1]);
            }
        }

        QMessageBox::information(this, "Успешная покупка", "Покупка прошла успешно! Спасибо за заказ.");

        ui->listWidget->clear();
        ui->totalPrice->clear();
        ui->cardNumber->clear();
        ui->email->clear();
        ui->cvcCvv->clear();
        ui->monthYear->clear();
        ui->stackedWidget->setCurrentIndex(0);
    }
    if (ui->listWidget->count() == 0) {
        ui->payButton->setEnabled(false);
    }
    updateTotalPrice();
}
