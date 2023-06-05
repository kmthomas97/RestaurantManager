
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddProduct = new AddProduct();
    ptrRegisterEmployee = new RegisterEmployee();
    ptrFindProduct = new FindProduct();
    ptrFindEmployee = new FindEmployee();

}

MainWindow::~MainWindow()
{
    delete ptrAddProduct;
    delete ptrRegisterEmployee;
    delete ptrFindProduct;
    delete ptrFindEmployee;
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ptrAddProduct->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrRegisterEmployee->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrFindProduct->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ptrFindEmployee->show();
}

