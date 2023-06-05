#include "addproduct.h"
#include "ui_addproduct.h"

AddProduct::AddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct)
{
    ui->setupUi(this);
}

AddProduct::~AddProduct()
{
    delete ui;
}

void AddProduct::on_btnSave_clicked()
{
    QString productName = ui->txtProductName->text();
    QString quantity = ui->txtQuantity->text();
    QString cost = ui->txtCost->text();
    QString expirationDate = ui->txtExpirationDate->text();

    qDebug() << "Product Name : "<< productName << "Quantity : " <<quantity << "Cost : " <<cost << "ExpirationDate : "<< expirationDate;
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/kaitl/Code/database/RestaurantManager.db");

    if(QFile::exists("C:/Users/kaitl/Code/database/RestaurantManager.db"))
    {
    qDebug() << "Database file exists";
    }
    else
    {
        qDebug() << "Database file doesn't exist";
        return;
    }

    if(!database.open())
    {
        qDebug() <<"Error: Unable to open Database";
        return;
    }
    else
    {
        qDebug() <<"Database open successfully..";
    }


    QSqlQuery query(database);

    query.prepare("insert into Product (ProductName, Quantity, Cost, ExpirationDate) values('" + productName + "','" + quantity + "','" + cost + "','" + expirationDate + "')");
    query.exec();
    qDebug() << "Last error : "<< query.lastError().text();
    database.close();


}



