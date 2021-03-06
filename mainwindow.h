#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"
#include "third_dialog.h"

//added from the thirdcpp
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlDriver>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
     QSqlDatabase mydb;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Student_Button_clicked();

    void on_Admin_Button_clicked();

    void on_LogIn_Button_clicked();

private:
    Ui::MainWindow *ui;
    SecDialog *SecDialog_Object; // we are pointing to this object using the SecDialog class
    Third_Dialog *Third_Dialog_Object; // Third_Dialog
//     QSqlDatabase mydb;
};
#endif // MAINWINDOW_H
