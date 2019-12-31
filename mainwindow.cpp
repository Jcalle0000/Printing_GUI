#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QSqlDriver>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/Users/jasoncalle/Desktop/Fall 19/Data Structures/QT_Projects/widget_trial_1/test.db");

    if(!mydb.open() )
    {
        ui->Status_User_info->setText("Failed to open Desktop");
    }
    else
    {
        ui->Status_User_info->setText("Connected to sqlite3");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Admin_Button_clicked()
{
//    ui->label->setText("Admin ID:");
//    hide();
    Third_Dialog_Object=new Third_Dialog(this);
    Third_Dialog_Object->show();
}



void MainWindow::on_Student_Button_clicked()
{
    ui->label->setText("Student ID:");
}


void MainWindow::on_LogIn_Button_clicked()
{

    QString emplid,password;
    emplid = ui->lineEdit_ID->text();
    password = ui->lineEdit_Password->text();

    if(mydb.open() )
    {
        QSqlQuery qry; //qsqlquery is the class and qry is the object?
        // used to communicate with the database

//      qDebug() << qry.prepare("INSERT INTO students (emplid,name,password) VALUES (7,'RR',7)")<< "RR is active";
//      qry.exec();


       if(qry.exec("SELECT * FROM students WHERE emplid='"+emplid+"' and password='"+password+"' ;") ) // if data is found to match we continue
        {
//          qDebug()<< qry.prepare("SELECT * FROM students WHERE emplid='"+emplid+"' and password='"+password+"' ;");
          // ' "+is_our_variable+" ' that we are comparing in our table

            int count=0;
            while( qry.next() ) // keeping looping until theres no next?
            {
                count++;
            }
            // qry.next() -- result must be in the active state and is select must be true

            if (count==1)
                ui->Status_User_info->setText("EmploID and password is correct");
                hide(); // hides the current ui
                SecDialog_Object = new SecDialog(this); // SecDialog_Object is created inside the header file
                SecDialog_Object->show();

            if (count>=1)
                ui->Status_User_info->setText("Duplicate EmploID and password");
            if (count<1)
                ui->Status_User_info->setText("EmploID and password is not correct");
        }

        else
            {
               qDebug()<<"Failed to open database";
               return ; // does this terminate the file
            }
    }

}


