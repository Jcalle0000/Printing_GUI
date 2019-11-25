#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Admin_Button_clicked()
{
    ui->label->setText("Admin ID:");
//    ThirdDialog_Object=new Third_Dialog(this);
//    ThirdDialgo_Object->show();
}

void MainWindow::on_Student_Button_clicked()
{
    ui->label->setText("Student ID:");
}

void MainWindow::on_LogIn_Button_clicked()
{
    QString ID=ui->lineEdit_ID->text();
    QString password = ui ->lineEdit_Password->text();

    if(ID=="test" && password=="test")
    {
//        QMessageBox::information(this,"Login","Username and password is correct");
        hide();
        SecDialog_Object=new SecDialog(this);
        SecDialog_Object->show();
    }
    else
    {
        QMessageBox::warning(this,"Login","Incorrect Data");
    }

}


