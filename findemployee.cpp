#include "findemployee.h"
#include "ui_findemployee.h"

FindEmployee::FindEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindEmployee)
{
    ui->setupUi(this);
}

FindEmployee::~FindEmployee()
{
    delete ui;
    delete model;
}

void FindEmployee::on_btnFind_clicked()
{
    QString employeeName = ui->txtEmployeeName->text();

    qDebug() << "Employee Name : "<< employeeName;
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

    query.prepare("select * from Employee where FirstName like '%" + employeeName + "%'");
    query.exec();
    qDebug() << "Last query : "<<query.lastQuery();
    qDebug() << "Last error : "<<query.lastError().text();

    if(model == NULL)
    {
        model = new QSqlQueryModel();

    }

    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1, 200);
    ui->tableView->setColumnWidth(0,200);
    database.close();
}





