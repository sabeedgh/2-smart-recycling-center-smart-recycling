#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include <QString>
#include <QRegularExpression>
#include <QDebug>
Client::Client()
{
code_fiscale=0; mail=""; adresse=""; date_1er_contact="";


}



Client::Client(int a,QString b,QString c,QString d)
{
    this->code_fiscale=a;
    this->mail=b;
    this->adresse=c;
    this->date_1er_contact=d;

}
int Client::getcode_fiscale(){return code_fiscale; }
QString Client::getmail(){return mail; }
QString Client::getdate_1er_contact(){return date_1er_contact; }
QString Client::getadresse(){return adresse; }
void Client::setcode_fiscale(int a){this->code_fiscale=a;}
void Client::setmail(QString b){this->mail=b;}
void Client::setdate_1er_contact(QString c)
{this->date_1er_contact=c;


}
void Client::setadresse(QString d){this->adresse=d;}
bool Client::ajouter()
{



    QSqlQuery query;
    QString code_string= QString::number(code_fiscale);
          query.prepare("INSERT INTO client (codefiscale, mail, adresse,date1ercontact) "
                        "VALUES (:code, :mail_adress, :adress, :date)");
          query.bindValue(0, code_string);
          query.bindValue(1, mail);
          query.bindValue(2, adresse);
           query.bindValue(3, date_1er_contact);
          return query.exec();

}





bool Client::supprimer(int code_fiscale)
{
    QSqlQuery query;
    QString code_string= QString::number(code_fiscale);
          query.prepare("DELETE FROM client WHERE codefiscale=:codefiscale");
          query.bindValue(":codefiscale", code_string);

          return query.exec();


}






bool Client::modifier(){
    QSqlQuery query;
    QString code_string= QString::number(code_fiscale);
    query.prepare("UPDATE client SET codefiscale=:codefiscale, mail=:mail, adresse=:adresse, date1ercontact=:date1ercontact WHERE codefiscale=:codefiscale");

    query.bindValue(":codefiscale", code_string);
    query.bindValue(":mail", mail);
    query.bindValue(":adresse", adresse);
     query.bindValue(":date1ercontact", date_1er_contact);

    return query.exec();

}





Client Client::rechercherParMail(QString email)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM clients WHERE mail = :mail");
    query.bindValue(":mail", email);

    query.bindValue(":codefiscale", code_fiscale);
    query.bindValue(":mail",mail);
    query.bindValue(":adresse", adresse);
     query.bindValue(":date1ercontact", date_1er_contact);



        Client client(code_fiscale, mail, date_1er_contact, adresse);
        return client;


    // Si le client n'a pas été trouvé, retournez un objet Client vide ou lancez une exception.
    return Client();
}
















QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM client");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("code fiscale"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("date 1er contact"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));


    return model;
}



