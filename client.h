#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQueryModel>

//
class Client
{
public:
    Client();
    Client(int,QString,QString,QString);
    int getcode_fiscale();
    QString getmail();
    QString getdate_1er_contact();
    QString getadresse();
    void setcode_fiscale(int);
    void setmail(QString);
    void setdate_1er_contact(QString);
    void setadresse(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    Client rechercherParMail(QString);






private:
    int code_fiscale;
    QString mail,date_1er_contact,adresse;


};

#endif // CLIENT_H
