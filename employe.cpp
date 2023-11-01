#include "employe.h"

client::client()
{
cin ="";
prenom="";
nom="";
}
void client:: setcin(QString n)
{
    cin=n;
}
void client:: setprenom(QString n)
{
    prenom=n;
}
void client:: setnom(QString n)
{
    nom=n;
}
QString client :: get_cin()
{
    return cin ;
}
QString client :: get_prenom()
{
    return prenom ;
}
QString client :: get_nom()
{
    return nom ;
}
