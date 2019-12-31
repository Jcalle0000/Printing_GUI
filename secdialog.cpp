#include "secdialog.h"
#include "ui_secdialog.h"

// references for adding a new windows and hiding them
// https://www.youtube.com/watch?v=6_elY8O20I8&list=PLS1QulWo1RIZiBcTr5urECberTITj7gjA&index=10

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
//    ui->Full_Name_label->setText()


};

SecDialog::~SecDialog()
{
    delete ui;
}
