
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

bool DataBase::addUser(const QString& surname, const QString& name, const QString& patronymic, const QString& address, const QString& telephoneNumber, const QString& login, const QString& password)
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
    QString newLine = QString("%1,%2,%3,%4,%5,%6,%7,%8").arg(surname, name, patronymic, address, telephoneNumber, login, password, roleToWrite);
    lines.append(newLine);

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();

    return true;
}

bool DataBase::addUserByAdmin(const QString& surname, const QString& name, const QString& patronymic, const QString& address, const QString& telephoneNumber, const QString& login, const QString& password, const QString& role)
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

    QString newLine = QString("%1,%2,%3,%4,%5,%6,%7,%8").arg(surname, name, patronymic, address, telephoneNumber, login, password, roleToWrite);
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

QStringList DataBase::loadUsersFromDataBase(QString filename)
{
    QStringList userData;
    QFile file(filename);
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

QStringList DataBase::loadSuppliesFromDataBase(QString filename)
{
    QStringList userData;
    QFile file(filename);
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
    QString oldPrice;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() >= 5 && parts[4] == vendor && parts[2] == oldVendorCode) {
            oldPrice = parts[3];
            parts[0] = newName;
            parts[1] = newCount;
            parts[2] = newVendorCode;
            parts[3] = newPrice;
            line = parts.join(",");
        }
        lines.append(line);
    }

    file.resize(0);
    QTextStream out(&file);
    out << lines.join("\n") << "\n";
    file.close();

    logPriceChange(oldVendorCode, oldPrice, newPrice);

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

QStringList DataBase::loadPurchasesFromDatabase(const QString& filename)
{
    QStringList purchaseData;
    QFile file(filename);
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

QStringList DataBase::loadPriceChangeHistory(const QString& filename)
{
    QStringList priceChangeData;
    QFile file(filename);
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
