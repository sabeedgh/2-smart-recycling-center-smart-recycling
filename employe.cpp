#include "employe.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
//
Employe::Employe()
{
id=0;
}
Employe::Employe(int id,int num_telephone,int nbre_enfant ,QString nom,QString prenom,QString statue_familiale,QString mot_de_passe,QString date_de_naissance,QString poste,QString date_d_embauche)
{
    this->id=id;this->num_telephone=num_telephone;this->nbre_enfant=nbre_enfant;this->nom=nom;this->prenom=prenom;this->statue_familiale=statue_familiale;this->mot_de_passe=mot_de_passe;this->date_de_naissance=date_de_naissance;this->poste=poste;this->date_d_embauche=date_d_embauche;
}
QString Employe::getnom(){return nom;}
QString Employe::getprenom(){return prenom;}
QString Employe::getstatue_familiale(){return statue_familiale;}
QString Employe::getmot_de_passe(){return mot_de_passe;}
QString Employe::getdate_de_naissance(){return date_de_naissance;}
QString Employe::getposte(){return poste;}
QString Employe::getdate_d_embauche(){return date_d_embauche;}
int Employe::getid(){return id;}
int Employe::getnum_telephone(){return num_telephone;}
int Employe::getnbre_enfant(){return nbre_enfant;}
void Employe::setnom (QString nom){this->nom=nom;}
void Employe::setprenom (QString prenom){this->prenom=prenom;}
void Employe::setstatue_familiale (QString statue_familiale){this->statue_familiale=statue_familiale;}
void Employe::setmot_de_passe (QString mot_de_passe){this->mot_de_passe=mot_de_passe;}
void Employe::setdate_de_naissance (QString date_de_naissance){this->date_de_naissance=date_de_naissance;}
void Employe::setposte (QString poste){this->poste=poste;}
void Employe::setdate_d_embauche (QString date_d_embauche ){this->date_d_embauche=date_d_embauche;}
void Employe::setid (int id){this->id=id;}
void Employe::setnum_telephone (int num_telephone ){this->num_telephone=num_telephone;}
void Employe::setnbre_enfant (int nbre_enfant){this->nbre_enfant=nbre_enfant;}
bool Employe::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
   // QString num_telephone_string=QString::number(num_telephone);
   // QString nbre_enfant_string=QString::number(nbre_enfant);

         query.prepare("INSERT INTO employe (IDENTIFIANT, MOTDEPASSE, NOM, PRENOM, DATEDENAISSANCE, NUMERODETELEPHONE, STATUEFAMILIALE, NOMBREDENFANT, POSTE, DATEDEMBAUCHE) "
                       "VALUES (:id, :password, :forename, :surname, :birth_date, :phone_number, :family_statue, :number_children, :post, :hiring_date)");
         query.bindValue(":id", id_string);
         query.bindValue(":password", mot_de_passe);
         query.bindValue(":forename", nom);
         query.bindValue(":surname", prenom);
         query.bindValue(":birth_date", date_de_naissance);
         query.bindValue(":phone_number", num_telephone);
         query.bindValue(":family_statue", statue_familiale);
         query.bindValue(":number_children", nbre_enfant);
         query.bindValue(":post", poste);
         query.bindValue(":hiring_date", date_d_embauche);

         return query.exec();


}


bool Employe::supprimer(int id )
{
            QSqlQuery query;
            QString res=QString::number( id);
            query.prepare(" DELETE FROM employe WHERE IDENTIFIANT =: id" );
            query.bindValue(0, id);
           return query.exec();
}
QSqlQueryModel * Employe::afficher()
{
  QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM employe");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Motdepasse"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Datedenaissance"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numerodetelephone "));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statuefamiliale"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombredenfant"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("Poste"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Datdembauche"));


  return model ;
}
bool Employe::modifier(){
    QSqlQuery query;
    query.prepare("UPDATE employe SET MOTDEPASSE = :password, NOM = :forename, PRENOM = :surname, DATEDENAISSANCE = :birth_date, NUMERODETELEPHONE = :phone_number, STATUEFAMILIALE = :family_statue, NOMBREDENFANT = :number_children, POSTE = :post, DATEDEMBAUCHE = :hiring_date WHERE IDENTIFIANT = :id");
    QString id_string=QString::number(id);
    query.bindValue(":id", id_string);
    query.bindValue(":password", mot_de_passe);
    query.bindValue(":forename", nom);
    query.bindValue(":surname", prenom);
    query.bindValue(":birth_date", date_de_naissance);
    query.bindValue(":phone_number", num_telephone);
    query.bindValue(":family_statue", statue_familiale);
    query.bindValue(":number_children", nbre_enfant);
    query.bindValue(":post", poste);
    query.bindValue(":hiring_date", date_d_embauche);

    return query.exec();

}
