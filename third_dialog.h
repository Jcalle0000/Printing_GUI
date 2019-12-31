#ifndef THIRD_DIALOG_H
#define THIRD_DIALOG_H

#include <QDialog>

#include<QtDebug>
#include<QFileInfo>
#include<QMainWindow>
#include<QtSql>

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlDriver>


namespace Ui {
class Third_Dialog;
}

class Third_Dialog : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase mydb_2;

public:
    explicit Third_Dialog(QWidget *parent = nullptr);
    ~Third_Dialog();

private slots:
//    void on_pushButton_clicked(); // we ended up deleting this button
    void on_Save_Button_clicked();

private:
    Ui::Third_Dialog *ui;
};

#endif // THIRD_DIALOG_H
