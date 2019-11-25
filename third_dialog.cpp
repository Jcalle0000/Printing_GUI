#include "third_dialog.h"
#include "ui_third_dialog.h"

Third_Dialog::Third_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Third_Dialog)
{
    ui->setupUi(this);
}

Third_Dialog::~Third_Dialog()
{
    delete ui;
}
