#ifndef FINDEMPLOYEE_H
#define FINDEMPLOYEE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class FindEmployee;
}

class FindEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit FindEmployee(QWidget *parent = nullptr);
    ~FindEmployee();

private slots:
    void on_btnFind_clicked();

private:
    Ui::FindEmployee *ui;
    QSqlQueryModel *model;
};

#endif // FINDEMPLOYEE_H
