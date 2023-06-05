#include "registeremployee.h"
#include "ui_registeremployee.h"

RegisterEmployee::RegisterEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterEmployee)
{
    ui->setupUi(this);
}

RegisterEmployee::~RegisterEmployee()
{
    qDebug() << "in ~RegisterEmployee()";
    delete ui;
}

void RegisterEmployee::on_btnSave_clicked()
{
    QString firstName = ui->txtFirstName->text();
    QString middleName = ui->txtMiddleName->text();
    QString lastName = ui->txtLastName->text();
    QString position = ui->txtPosition->text();
    QString contactNo = ui->txtContactNo->text();
    QString address = ui->txtAddress->text();

    qDebug() << "FirstName : "<< firstName << "MiddleName : " <<middleName << "LastName : " <<lastName << "Position : "<< position<< "ContactNo : "<< contactNo << "Address : "<< address;
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

    query.prepare("insert into Employee (FirstName, MiddleName, LastName, Position, ContactNo, Address) values('" + firstName+ "','" + middleName + "','" + lastName + "','" + position + "','" + contactNo + "','" + address + "')");
    query.exec();
    qDebug() << "Last error : "<< query.lastError().text();
    database.close();

}
