#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

#include<QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
