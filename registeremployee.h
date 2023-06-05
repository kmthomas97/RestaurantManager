#ifndef REGISTEREMPLOYEE_H
#define REGISTEREMPLOYEE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class RegisterEmployee;
}

class RegisterEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterEmployee(QWidget *parent = nullptr);
    ~RegisterEmployee();

private slots:
    void on_btnSave_clicked();

private:
    Ui::RegisterEmployee *ui;
};

#endif // REGISTEREMPLOYEE_H
