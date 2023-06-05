#ifndef FINDPRODUCT_H
#define FINDPRODUCT_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class FindProduct;
}

class FindProduct : public QDialog
{
    Q_OBJECT

public:
    explicit FindProduct(QWidget *parent = nullptr);
    ~FindProduct();

private slots:
    void on_btnFindProduct_clicked();

private:
    Ui::FindProduct *ui;
    QSqlQueryModel *model;
};

#endif // FINDPRODUCT_H
