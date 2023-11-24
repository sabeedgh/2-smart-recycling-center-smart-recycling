#include "connection.h"
#include<QDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //db.setHostName("localhost");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("sabee");
    db.setPassword("esprit18");

if (db.open())
{
    qDebug()<<"Connexion à la base de données réussie.";
    test=true;
}
else
{
    qDebug()<<"Erreur lors de la connexion à la base de données.";
}
return  test;
}
