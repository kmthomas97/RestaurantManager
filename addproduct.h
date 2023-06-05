#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddProduct;
}

class AddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

private slots:
    void on_btnSave_clicked();

private:
    Ui::AddProduct *ui;
};

#endif // ADDPRODUCT_H
