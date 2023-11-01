#ifndef CLIENT_H
#define CLIENT_H
#include<QString>

class client
{
public:
    void setcin(QString n);
    void setprenom(QString n);
    void setnom(QString n);
    QString get_cin();
    QString get_nom();
    QString get_prenom();
    client();
private :
    QString cin,nom,prenom;

};

#endif // CLIENT_H
