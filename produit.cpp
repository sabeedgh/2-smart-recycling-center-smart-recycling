#include "produit.h"

produit::produit(int id,QString type,QString date,float quantity,float prix)
{
this->type=type;
    this->id=id;
    this->date=date;
    this->quantity=quantity;
    this->prix=prix;
}
bool produit::ajouter()
{

}
QSqlQueryModel * produit::afficher()
{

}
bool produit::supprimer(int id)
{

}
