
#include "database.h"

#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QException>
#include <QDebug>
#include <QDate>

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    checkAndCreateFilesIfNeeded();
}

void DataBase::checkAndCreateFilesIfNeeded()
{
    QStringList requiredFiles = {
        "Cards.csv",
        "PriceChangeHistory.csv",
        "Purchases.csv",
        "SuppliersCompanies.csv",
        "Supplies.csv",
        "Users.csv"
    };

    for (const QString& fileName : requiredFiles) {
        QFile file(fileName);
        if (!file.exists()) {
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                throw DbCritical();
            }
            if (fileName == "Users.csv") {
                QTextStream out(&file);
                out << "Admin,Admin,Admin,Admin,Admin,admin,admin,Admin,admin@example.com\n";
            }
            file.close();
            qDebug() << "Created file:" << fileName;
        }
    }
}

int DataBase::checkUsersDB(const QString& login, const QString& password)
{
    int AuthSuccess = 0;
    QFile file("Users.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QStringList line = in.readLine().split(",");
        if (line[5] == login && line[6] == password)
        {
            file.close();
            if (line[7] == "Admin")
                AuthSuccess = 1;
            if (line[7] == "Supplier")
                AuthSuccess = 2;
            if (line[7] == "Buyer")
                AuthSuccess = 3;
            break;
        }
    }

    if(AuthSuccess == 0)
    {
        throw UserNotFound();
    }

    file.close();
    return AuthSuccess;
}

bool DataBase::addUser(const QString& surname, const QString& name, const QString& patronymic, const QString& address, const QString& telephoneNumber, const QString& login, const QString& password, const QString& email)
{
    QFile file("Users.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        lines.append(line);
    }

    QString roleToWrite = "Buyer";
    QString newLine = QString("%1,%2,%3,%4,%5,%6,%7,%8,%9").arg(surname, name, patronymic, address, telephoneNumber, login, password, roleToWrite, email);
    lines.append(newLine);

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();

    return true;
}

bool DataBase::addUserByAdmin(const QString& surname, const QString& name, const QString& patronymic, const QString& address, const QString& telephoneNumber, const QString& login, const QString& password, const QString& role, const QString& email)
{
    QFile file("Users.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        lines.append(line);
    }

    QString roleToWrite = "";

    if (role == "Покупатель")
        roleToWrite = "Buyer";
    if (role == "Поставщик")
        roleToWrite = "Supplier";
    if (role == "Администратор")
        roleToWrite = "Admin";

    QString newLine = QString("%1,%2,%3,%4,%5,%6,%7,%8,%9").arg(surname, name, patronymic, address, telephoneNumber, login, password, roleToWrite, email);
    lines.append(newLine);

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();

    return true;
}

int DataBase::getRoles()
{
    QString surname, password;
    int role = 0;
    QFile file("Users.csv");
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QStringList line = in.readLine().split(",");
        if (line[0] == surname && line[5] == password)
        {
            file.close();
            if (line[6] == "Admin")
                role = 1;
            if (line[6] == "Supplier")
                role = 2;
            if (line[6] == "Buyer")
                role = 3;
            break;
        }
    }

    file.close();
    return role;
}

bool DataBase::addSupplying(QString name, QString count, QString vendorCode, QString price, QString vendor)
{
    bool AddSupplyingSuccess = false;
    QFile file("Supplies.csv");
    file.open(QFile::Append);

    QTextStream ts(&file);
    ts << name << "," << count << "," << vendorCode << "," << price << "," << vendor << "\n";
    AddSupplyingSuccess = true;

    file.close();
    return AddSupplyingSuccess;
}

QStringList DataBase::loadUsersFromDataBase()
{
    QStringList userData;
    QFile file("Users.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        userData.append(line);
    }

    file.close();
    return userData;
}

QStringList DataBase::loadSuppliesFromDataBase()
{
    QStringList userData;
    QFile file("Supplies.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        userData.append(line);
    }

    file.close();
    return userData;

}

QStringList DataBase::getSuppliesForVendor(const QString& vendor)
{
    QStringList supplies;
    QFile file("Supplies.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 5 && parts[4] == vendor) {
            supplies.append(parts[0] + "," + parts[2]);
        }
    }

    file.close();
    return supplies;
}

QStringList DataBase::getSupplyDataForVendor(const QString& vendor, const QString& supplyName, const QString& vendorCode)
{
    QStringList supplyData;
    QFile file("Supplies.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 5 && parts[4] == vendor && parts[0] == supplyName && parts[2] == vendorCode) {
            supplyData = parts.mid(0, 4);
            break;
        }
    }

    file.close();
    return supplyData;
}

bool DataBase::updateSupply(const QString& vendor, const QString& oldVendorCode, const QString& newName, const QString& newCount, const QString& newVendorCode, const QString& newPrice)
{
    QFile file("Supplies.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList lines;
    QTextStream in(&file);
    QString oldPrice, oldName, oldCount;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 5 && parts[4] == vendor && parts[2] == oldVendorCode) {
            oldName = parts[0];
            oldCount = parts[1];
            oldPrice = parts[3];
            if (!newName.isEmpty()) parts[0] = newName;
            if (newName.isEmpty()) parts[0] = oldName;
            if (!newCount.isEmpty()) parts[1] = newCount;
            if (newCount.isEmpty()) parts[1] = oldCount;
            if (!newVendorCode.isEmpty()) parts[2] = newVendorCode;
            if (newVendorCode.isEmpty()) parts[2] = oldVendorCode;
            if (!newPrice.isEmpty()) parts[3] = newPrice;
            if (newPrice.isEmpty()) parts[3] = oldPrice;
            line = parts.join(",");
        }
        lines.append(line);
    }

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();

    if (!newPrice.isEmpty()) {
        logPriceChange(oldVendorCode, oldPrice, newPrice);
    }

    return true;
}

void DataBase::logPriceChange(const QString& vendorCode, const QString& oldPrice, const QString& newPrice)
{
    QFile file("PriceChangeHistory.csv");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream outStream(&file);
        QString date = QDate::currentDate().toString("dd.MM.yyyy");
        double oldPriceValue = oldPrice.toDouble();
        double newPriceValue = newPrice.toDouble();
        double priceDifference = newPriceValue - oldPriceValue;
        outStream << vendorCode << "," << date << "," << oldPrice << "," << newPrice << "," << QString::number(priceDifference, 'f', 2) << "\n";
        file.close();
    } else {
        throw DbCritical();
    }
}

bool DataBase::deleteSupply(const QString& vendor, const QString& vendorCode)
{
    QFile file("Supplies.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 5 && (parts[4] != vendor || parts[2] != vendorCode)) {
            lines.append(line);
        }
    }
    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();

    return true;
}

bool DataBase::isVendorCodeExists(const QString& vendorCode)
{
    QFile file("Supplies.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 4 && parts[2] == vendorCode) {
            file.close();
            return true;
            break;
        }
    }

    file.close();
    return false;
}

void DataBase::deleteUserFromFile(const QString& surname, const QString& name, const QString& patronymic,
                                  const QString& address, const QString& phone, const QString& login,
                                  const QString& password, const QString& role)
{
    QFile file("Users.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 7 &&
            (parts[0] != surname ||
             parts[1] != name ||
             parts[2] != patronymic ||
             parts[3] != address ||
             parts[4] != phone ||
             parts[5] != login ||
             parts[6] != password ||
             parts[7] != role)) {
            lines.append(line);
        }
    }

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();
}

bool DataBase::updateSupplyQuantity(const QString& vendorCode, int newQuantity)
{
    QFile file("Supplies.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 5 && parts[2] == vendorCode) {
            parts[1] = QString::number(newQuantity);
            line = parts.join(",");
        }
        lines.append(line);
    }

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();

    return true;
}

void DataBase::savePurchaseToDatabase(const QString &filename, const QString &vendorCode, const QString &date, const QString &customerName, const QString &quantity)
{
    QFile purchaseFile(filename);
    if (purchaseFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream outStream(&purchaseFile);
        outStream << vendorCode << "," << quantity << "," << date << "," << customerName << "\n";
        purchaseFile.close();
    } else {
        throw DbCritical();
    }

    QFile suppliesFile("Supplies.csv");
    if (suppliesFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&suppliesFile);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            QStringList parts = line.split(",");
            if (parts.size() >= 5 && parts[2] == vendorCode) {
                int currentQuantity = parts[1].toInt();
                int newQuantity = currentQuantity - quantity.toInt();
                if (newQuantity >= 0) {
                    updateSupplyQuantity(vendorCode, newQuantity);
                }
                break;
            }
        }
        suppliesFile.close();
    } else {
        throw DbCritical();
    }
}

QStringList DataBase::loadPurchasesFromDatabase()
{
    QStringList purchaseData;
    QFile file("Purchases.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        purchaseData.append(line);
    }

    file.close();
    return purchaseData;
}

QStringList DataBase::loadPriceChangeHistory()
{
    QStringList priceChangeData;
    QFile file("PriceChangeHistory.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            priceChangeData.append(line);
        }
        file.close();
        return priceChangeData;
    } else {
        throw DbCritical();
    }
}

bool DataBase::checkSameLogins(const QString &login)
{
    QFile file("Users.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");

        if (parts[5] == login) {
            return true;
            break;
        }
    }

    file.close();
    return false;
}

bool DataBase::addSupplierCompany(const QString &surname, const QString &name, const QString &patronymic, const QString &companyName, const QString &address, const QString &telephoneNumber, const QString& login)
{
    QFile file("SuppliersCompanies.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        lines.append(line);
    }

    QString newLine = QString("%1,%2,%3,%4,%5,%6,%7").arg(surname, name, patronymic, companyName, address, telephoneNumber, login);
    lines.append(newLine);

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();

    return true;
}

QStringList DataBase::loadSuppliersCompaniesFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList suppliersCompanies;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        suppliersCompanies.append(line);
    }
    file.close();
    return suppliersCompanies;
}

QStringList DataBase::loadCardDataFromDatabase()
{
    QStringList cardData;
    QFile file("Cards.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }
    QString key = "SecretKeyForEncryptCardNumber";
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 3) {
            QString encryptedCardNumber = parts[0];
            QString decryptedCardNumber = decryptCardData(encryptedCardNumber, key);
            cardData.append(decryptedCardNumber + "," + parts[1] + "," + parts[2]);
        }
    }
    file.close();
    return cardData;
}

void DataBase::saveCardDataToDatabase(const QString& cardNumber, const QString& expiryDate, const QString& buyerLogin)
{
    QFile file("Cards.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw DbCritical();
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        lines.append(line);
    }

    QString key = "SecretKeyForEncryptCardNumber";
    QString newCardNumber = encryptCardData(cardNumber, key);

    QString newLine = QString("%1,%2,%3").arg(newCardNumber, expiryDate, buyerLogin);
    lines.append(newLine);

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";

    file.close();
}

bool DataBase::isCardDataExists(const QString& buyerLogin)
{
    QFile file("Cards.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw DbCritical();
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 3 && parts[2] == buyerLogin) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

QString DataBase::encryptCardData(QString cardNumber,QString key)
{
    QString encryptedCardNumber;
    QByteArray cardBytes = cardNumber.toUtf8();
    QByteArray keyBytes = key.toUtf8();

    for (int i = 0, j = 0; i < cardBytes.size(); i++, j = (j + 1) % keyBytes.size()) {
        encryptedCardNumber.append(static_cast<char>(cardBytes[i] ^ keyBytes[j]));
    }

    return encryptedCardNumber;
}

QString DataBase::decryptCardData(QString encryptedCardNumber, QString key)
{
    QString decryptedCardNumber;
    QByteArray encryptedBytes = encryptedCardNumber.toUtf8();
    QByteArray keyBytes = key.toUtf8();

    for (int i = 0, j = 0; i < encryptedBytes.size(); i++, j = (j + 1) % keyBytes.size()) {
        decryptedCardNumber.append(static_cast<char>(encryptedBytes[i] ^ keyBytes[j]));
    }

    return decryptedCardNumber;
}
