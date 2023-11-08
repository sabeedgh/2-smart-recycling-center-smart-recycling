#ifndef EMPLOYE_H
//#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>
#include<QString>
//
class Employe
{
public:
    Employe();
    Employe(int,int,int,QString ,QString,QString,QString,QString,QString,QString);
    QString getnom();
    QString getprenom();
    QString getstatue_familiale();
    QString getmot_de_passe();
    QString getdate_de_naissance();
    QString getposte();
    QString getdate_d_embauche();
    int getid();
    int getnum_telephone();
    int getnbre_enfant();
    void setnom (QString);
    void setprenom (QString);
    void setstatue_familiale (QString);
    void setmot_de_passe (QString);
    void setdate_de_naissance (QString);
    void setposte (QString);
    void setdate_d_embauche (QString);
    void setid (int);
    void setnum_telephone (int);
    void setnbre_enfant (int);
    bool ajouter ();
    QSqlQueryModel*   afficher();
    bool supprimer (int);
    bool modifier();

private :
    int id,num_telephone,nbre_enfant;
    QString nom,prenom,statue_familiale,mot_de_passe,date_de_naissance,poste,date_d_embauche;

};

#endif // EMPLOYE_H
