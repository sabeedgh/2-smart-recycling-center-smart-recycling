#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_num_telephone->setValidator(new QIntValidator(100, 9999999, this));
    ui->le_nbre_enfant->setValidator(new QIntValidator(100, 9999999, this));
    ui->tab_employe->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    int num_telephone=ui->le_num_telephone->text().toInt();
    int nbre_enfant=ui->le_nbre_enfant->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString statue_familiale=ui->le_statue_familiale->text();
    QString mot_de_passe=ui->le_mot_de_passe->text();
    QString date_de_naissance=ui->le_date_de_naissance->text();
    QString poste=ui->le_poste->text();
    QString date_d_embauche=ui->le_date_d_embauche->text();
    Employe E (id,num_telephone,nbre_enfant ,nom,prenom,statue_familiale,mot_de_passe,date_de_naissance,poste,date_d_embauche);
    bool test=E.ajouter();
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("Ajout avec succes");
     ui->tab_employe ->setModel(E.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Employe E1 ;
    E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("Sup avec succes");
     ui->tab_employe ->setModel(E.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    int num_telephone=ui->le_num_telephone->text().toInt();
    int nbre_enfant=ui->le_nbre_enfant->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString statue_familiale=ui->le_statue_familiale->text();
    QString mot_de_passe=ui->le_mot_de_passe->text();
    QString date_de_naissance=ui->le_date_de_naissance->text();
    QString poste=ui->le_poste->text();
    QString date_d_embauche=ui->le_date_d_embauche->text();

      Employe E (id,num_telephone,nbre_enfant ,nom,prenom,statue_familiale,mot_de_passe,date_de_naissance,poste,date_d_embauche);
        bool test=E.modifier();
       if (test){
           ui->tab_employe ->setModel(E.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée \n"),QMessageBox::Cancel);
       }
       else QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Modification non effectuée\n"),QMessageBox::Cancel);
}
