#include "third_dialog.h"
#include "ui_third_dialog.h"




// this is the new admin page data page
// we will want to connect this to the sql to save the data
Third_Dialog::Third_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Third_Dialog)
{
    ui->setupUi(this);

   QSqlDatabase mydb_2= QSqlDatabase::addDatabase("QSQLITE");
   mydb_2.setDatabaseName("/Users/jasoncalle/Desktop/Fall 19/Data Structures/QT_Projects/widget_trial_1/test.db");

// Error after giving it the same database name
//QSqlDatabasePrivate::removeDatabase: connection 'qt_sql_default_connection' is still in use, all queries will cease to work.
//QSqlDatabasePrivate::addDatabase: duplicate connection name 'qt_sql_default_connection', old connection removed.

    if(!mydb_2.open() )
    {
     ui->Status_Label->setText("Failed to open Desktop");
    }
    else
    {
     ui->Status_Label->setText("Connected to sqlite3");
    }

}
 // what
Third_Dialog::~Third_Dialog()
{
    delete ui;
}


void Third_Dialog::on_Save_Button_clicked()
{
    QString ID_SQL,NAME_SQL,PASSWORD_SQL; // we are taking the data
    ID_SQL = ui->lineEdit_2_ID->text();
    NAME_SQL = ui->lineEdit_NAME->text();
    PASSWORD_SQL = ui->lineEdit_3_PASSWORD->text();

    qDebug() << ID_SQL << NAME_SQL << PASSWORD_SQL;

    if(!mydb_2.isOpen() ) // checks to see if connection is opened, maybe not be needed to be opened to execute commands
    {
        qDebug()<<"Failed to open the database";
        return; // ends the program
    }

    QSqlQuery qry_2; //qsqlquery is the class and qry is the object?

    qDebug() << qry_2.prepare("INSERT INTO students (emplid,name,password) VALUES (9,'JJ',9)");
    qry_2.exec();

//    qDebug() << qry.exec("INSERT INTO students (name,password) VALUES (NAME_SQL,PASSWORD_SQL)");


//    // used to communicate with the databaseqry.exec("SELECT * FROM students where username= '"+ID_SQL+"' and password '"+PASSWORD_SQL+"' ") )
//    {
//        int count=0;
//        while(qry.next() )
//        {
//            count++;
//        }
//        if (count==1)
//            ui->Status_Label->setText("username and password is correct");
//        if (count>=1)
//            ui->Status_Label->setText("Duplicate username and password");
//        if (count<1)
//            ui->Status_Label->setText("username and password is not correct");
//    }
}
