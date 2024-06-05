
#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QException>

class UserNotFound : public QException
{
public:
    void raise() const override { throw *this; }
    UserNotFound *clone() const override { return new UserNotFound(*this); }
};
class DbCritical : public QException
{
    void raise() const override { throw *this; }
    DbCritical *clone() const override { return new DbCritical(*this); }
};

class DataBase : public QObject
{
       Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    void checkAndCreateFilesIfNeeded();
    int checkUsersDB(const QString& surname, const QString& password);
    bool addUser(const QString& surname, const QString& name, const QString& patronymic, const QString& address, const QString& telephoneNumber, const QString& login, const QString& password, const QString& email);
    bool addUserByAdmin(const QString& surname, const QString& name, const QString& patronymic, const QString& address, const QString& telephoneNumber, const QString& login, const QString& password, const QString& role, const QString& email);
    int getRoles();
    bool addSupplying(QString name, QString count, QString vendorCode, QString price, QString vendor);
    QStringList loadUsersFromDataBase();
    QStringList loadSuppliesFromDataBase();
    QStringList getSuppliesForVendor(const QString& vendor);
    QStringList getSupplyDataForVendor(const QString& vendor, const QString& supplyName, const QString& vendorCode);
    bool updateSupply(const QString& vendor, const QString& oldVendorCode, const QString& newName, const QString& newCount, const QString& newVendorCode, const QString& newPrice);
    void logPriceChange(const QString& vendorCode, const QString& oldPrice, const QString& newPrice);
    bool deleteSupply(const QString& vendor, const QString& vendorCode);
    void deleteUserFromFile(const QString& surname, const QString& name, const QString& patronymic, const QString& address, const QString& phone, const QString& login, const QString& password, const QString& role);
    bool isVendorCodeExists(const QString& vendorCode);
    void savePurchaseToDatabase(const QString &filename, const QString &vendorCode, const QString &date, const QString &customerName, const QString &quantity);
    QStringList loadPurchasesFromDatabase();
    bool updateSupplyQuantity(const QString& vendorCode, int newQuantity);
    QStringList loadPriceChangeHistory();
    bool checkSameLogins(const QString& login);
    bool addSupplierCompany(const QString& surname, const QString& name, const QString& patronymic, const QString& companyName, const QString& address, const QString& telephoneNumber, const QString& login);
    QStringList loadSuppliersCompaniesFromFile(const QString& filename);
    QStringList loadCardDataFromDatabase();
    void saveCardDataToDatabase(const QString& cardNumber, const QString& expiryDate, const QString& buyerLogin);
    bool isCardDataExists(const QString& buyerLogin);
    QString encryptCardData(QString cardNumber, QString key);
    QString decryptCardData(QString encryptedCardNumber, QString key);
};

#endif // DATABASE_H
