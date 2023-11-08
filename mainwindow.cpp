#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QString>
//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->cd->setValidator (new QIntValidator(0, 999, this));
     ui->tab_client->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_le_ajouter_clicked()
{

    int code_fiscale=ui->cd->text().toInt();
    QString mail=ui->le_mail->text();
     QString adresse=ui->le_adresse->text();
      QString date_1er_contact=ui->le_date_1er_contact->text();
      Client C(code_fiscale,mail,date_1er_contact,adresse);
      bool test=C.ajouter();
      QMessageBox msgBox;
      if(test){
          msgBox.setText("Ajout avec success.");
       ui->tab_client->setModel(C.afficher());}
      else
          msgBox.setText("Echec d'ajout");
      msgBox.exec();


}

void MainWindow::on_pb_supprimer_clicked()
{
    Client C; C.setcode_fiscale(ui->le_supp_code->text().toInt());
    bool test=C.supprimer(C.getcode_fiscale());
    QMessageBox msgBox;
    if(test){
        msgBox.setText("Suppression avec success.");
        ui->tab_client->setModel(C.afficher());}
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{

    int code_fiscale=ui->cd->text().toInt();
    QString mail=ui->le_mail->text();
     QString adresse=ui->le_adresse->text();
      QString date_1er_contact=ui->le_date_1er_contact->text();

       Client C(code_fiscale,mail,date_1er_contact,adresse);
       bool test=C.modifier();
       if (test){
           ui->tab_client->setModel(C.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée \n"),QMessageBox::Cancel);
       }
       else QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Modification non effectuée\n"),QMessageBox::Cancel);


}

void MainWindow::on_pushButton_clicked()
{
    QString email = ui->le_email->text();

        // Créez un objet Client et appelez la méthode de recherche
        Client C ;
                C= C.rechercherParMail(email);

        // Vérifiez si le client a été trouvé
        if (C.getcode_fiscale() != 0) {
            // Le client a été trouvé, affichez les détails du client
            ui->le_code->setText(QString::number(C.getcode_fiscale()));
            ui->le_ad->setText(C.getmail());
            ui->le_date->setText(C.getdate_1er_contact());
            ui->le_add->setText(C.getadresse());
        } else {
            // Le client n'a pas été trouvé, effacez les champs ou affichez un message d'erreur
            // Par exemple :
            ui->le_code->clear();
            ui->le_ad->clear();
            ui->le_date->clear();
            ui->le_add->clear();
            QMessageBox::critical(this, "Erreur", "Aucun client trouvé avec cette adresse e-mail.");
        }
}
