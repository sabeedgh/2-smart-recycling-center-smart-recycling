#ifndef PRODUIT_H
#define PRODUIT_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class produit
{
    QString type,date;
    int id;
    float quantity,prix;
public:

    produit();
    produit(int,QString,QString,float,float);
    QString gettype(){return type;}
    QString getdate(){return date;}
    int getid(){return id;}
    float getquantity(){return quantity;}
    float getprix(){return prix;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // PRODUIT_H
