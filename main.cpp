#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "crud.h"
#include <QSqlDatabase>
#include<QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Crud c ;
    QSqlDatabase db;
    bool test=c.createcrud();
    MainWindow w;
    if (test)
    {
        w.show();
        QMessageBox::information(nullptr , QObject::tr("database is open"), QObject::tr("connection successful.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("conection failed.\n""Click Cancel to exit."),QMessageBox::Cancel);

    return a.exec();
}
