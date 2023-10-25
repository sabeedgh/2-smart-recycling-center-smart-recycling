#ifndef CRUD_H
#define CRUD_H
#include <QSqlDatabase>
#include<QDebug>
#include <QMessageBox>
#include "main.cpp"



class Crud
{
    QSqlDatabase db;
public:
    Crud();
    bool createcrud();
    void closecrud();
};

#endif // CRUD_H
