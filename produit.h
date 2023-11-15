#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTextDocument>

class Produit
{
    QString type;
    QDate dater;
    int id,quantity,prix;
public:
    Produit();
    Produit(QString,QDate,int,int,int);
        QString gettype();
        QDate getdater();
        int getid();
        int getquantity();
        int getprix();
        void settype(QString);
        void setdater(QDate);
        void setid(int);
        void setquantity(int);
        void setprix(int);
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int);
        void exportToPDF();

};

#endif // PRODUIT_H
