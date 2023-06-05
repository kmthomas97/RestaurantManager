#include "findproduct.h"
#include "ui_findproduct.h"

FindProduct::FindProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindProduct)
{
    ui->setupUi(this);
}

FindProduct::~FindProduct()
{
   // qDebug() << "~FindProduct()";
    delete ui;
    delete model;
}

void FindProduct::on_btnFindProduct_clicked()
{
    QString productName = ui->txtProductName->text();

    //qDebug() << "Product Name : "<< productName;
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

    query.prepare("select * from Product where ProductName like '%" + productName + "%'");
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

