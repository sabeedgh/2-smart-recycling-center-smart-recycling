#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employe.h"
#include"employe.cpp"
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>
#include<QDate>
#include<QIntValidator>
#include<QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>

#include <QPixmap>




#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>


#include "pdf.h"
#include "chart.h"
#include "csv.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->affichage->setModel(Emp.afficherEmployes());


    setChartView_Dep(ui->horizontalFrame);
    setChartView_Poste(ui->horizontalFrame_2);

    ui->pcin->setValidator(new QIntValidator(0,99999999,this));
    ui->phfixe->setValidator(new QIntValidator(0,99999,this));
    ui->phsupp->setValidator(new QIntValidator(0,99999,this));
    ui->pnumtel->setValidator(new QIntValidator(0,99999999,this));
    ui->psalaire->setValidator(new QIntValidator(0,99999999,this));
   // ui->modif->setValidator(new QIntValidator(0,99999999,this));
   // ui->mtel->setValidator(new QIntValidator(0,999999999,this));
  //  ui->msalaire->setValidator(new QIntValidator(0,99999999,this));
    ui->supp->setValidator(new QIntValidator(0,99999999,this));
    QPixmap pix("C:/Users/MSI/Desktop/LOGO/gemstonerecycle");
    ui->PICOOO->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));
}



void MainWindow::on_ajout_clicked()
{

    QString nompren=ui->pnom->text();
    QString mdp=ui->mdp->text();
    QString adresse_email=ui->padresse->text();
    int cin_emp = ui->pcin->text().toInt();
    int num_tel = ui->pnumtel->text().toInt();
    QDate date_derecru= ui->pdate->date();
    QString departement= ui->pdepartement->text();
    QString poste= ui->pposte->text();
    int salaire= ui->psalaire->text().toInt();
    int hfixe= ui->phfixe->text().toInt();
    int hsupp= ui->phsupp->text().toInt();

    bool cinValid = false;
        int cinValue = ui->pcin->text().toInt(&cinValid);
        if (!cinValid || ui->pcin->text().length() < 8)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un CIN valide (au moins 8 chiffres)."), QMessageBox::Cancel);
        return;
    }

        QSqlQueryModel *EmployeExistant = Emp.rechercheremp(cin_emp);
        if (EmployeExistant->rowCount() > 0)
     {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Le CIN de cet employé existe déjà."), QMessageBox::Cancel);
         delete EmployeExistant;
         return;
     }

     if (nompren.isEmpty() || !nompren.contains(QRegularExpression("^[a-zA-Z ]+$")))
     {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un nom et prénom correcte."), QMessageBox::Cancel);
                return;
            }
    /* if (mdp.isEmpty() || !mdp.contains(QRegularExpression("^[a-zA-Z0-9 +-]+@[a-zA-Z0-9  ]+\\.[a-zA-Z]{2,}$"))) {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un mot de passe valide."), QMessageBox::Cancel);
         return;
     }*/
     if (adresse_email.isEmpty() || !adresse_email.contains(QRegularExpression("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"))) {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer une adresse_Email valide."), QMessageBox::Cancel);
         return;
     }
     if (departement.isEmpty() || !departement.contains(QRegularExpression("^[a-zA-Z ]+$"))) {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un département valide."), QMessageBox::Cancel);
         return;
     }
     if (poste.isEmpty() || !poste.contains(QRegularExpression("^[a-zA-Z  ]+$"))) {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un poste valide."), QMessageBox::Cancel);
         return;
     }

     Employe Emp(nompren,mdp,adresse_email,cin_emp,num_tel,date_derecru,departement,poste,salaire,hfixe,hsupp);
     bool test = Emp.ajouter();

     if (test)
     {
         QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                                              QObject::tr("Ajout effectué.\n Cliquer Cancel pour sortir."), QMessageBox::Cancel);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de l'ajout .\n Cliquer Cancel pour sortir."), QMessageBox::Cancel);
     }
}




void MainWindow::on_afficher_clicked()
{
    Employe Emp ;
    ui->affichage->setModel(Emp.afficherEmployes());
    ui->selectii->setModel(Emp.afficherEmployes());

}

void MainWindow::on_supprimer_clicked()
{
    Employe Emp;
    Emp.setCin(ui->supp->text().toInt());

    QSqlQueryModel *EmployeExistant = Emp.rechercheremp(ui->supp->text().toInt());
        if (EmployeExistant->rowCount() == 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'employé avec ce CIN n'existe pas."), QMessageBox::Cancel);
            delete EmployeExistant;
            return;
        }
    bool test=Emp.supprimer(Emp.getCin());

    if (test)
    {
            QMessageBox::information(nullptr, QObject::tr("SUCCES"), QObject::tr("Suppression effectuée"),
                                     QMessageBox::Ok);
            ui->affichage->setModel(Emp.afficherEmployes());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"), QObject::tr("Suppression échouée"),
                                 QMessageBox::Cancel);
    }
}


void MainWindow::on_modifier_clicked()
{

    QString nompren=ui->pnom->text();
    QString mdp=ui->mdp->text();
    QString adresse_email=ui->padresse->text();
    int cin_emp=ui->pcin->text().toInt();
    int num_tel=ui->pnumtel->text().toInt();
    QDate date_derecru=ui->pdate->date();
    QString departement=ui->pdepartement->text();
    QString poste=ui->pposte->text();
    int salaire=ui->psalaire->text().toInt();
    int hfixe=ui->phfixe->text().toInt();
    int hsupp=ui->phsupp->text().toInt();

    Employe Emp(nompren,mdp,adresse_email,cin_emp,num_tel,date_derecru,departement,poste,salaire,hfixe,hsupp);

     bool test=Emp.modifier();
    if(test)
    {
            QMessageBox::information(nullptr, QObject::tr("OUI"),
                        QObject::tr("Modification accomplie\n"
                                    "Cliquer Cancel pour sortir."), QMessageBox::Cancel);

    }
        else
            { QMessageBox::critical(nullptr, QObject::tr("NON"),
                        QObject::tr("Modification inaccopmlie.\n"
                                    "Cliquer Cancel pour sortir."), QMessageBox::Cancel);

    }

}




void MainWindow::on_trier_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT * from EMPLOYEE ORDER BY ";

    switch (ui->comboBox_2->currentIndex()) {
    case NOM:
        query += "NOMPREN";
        break;
    case DEPARTEMENT:
        query += "DEPARTEMENT";
        break;
    case POSTE:
        query += "POSTE";
        break;
    case SALAIRE:
        query += "SALAIRE";
        break;
    }

    query += ui->rechText->text();
    model->setQuery(query);
    ui->affichage->setModel(model);

}

void MainWindow::on_chercher_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT * from EMPLOYEE WHERE ";

    switch (ui->comboBox->currentIndex()) {
    case NOM:
        query += "NOMPREN='";
        break;
    case DEPARTEMENT:
        query += "DEPARTEMENT='";
        break;
    case POSTE:
        query += "POSTE='";
        break;
    }

    query += ui->rechText->text() + "'";
    model->setQuery(query);
    ui->affichage->setModel(model);
}


void MainWindow::on_PDF_clicked()
{
    exportTableViewToPDF(ui->affichage);
}

void MainWindow::on_pushButton_8_clicked()
{
    exportCSV();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_selectii_currentIndexChanged(QString pcin)
{

      /*QString*/ pcin = ui->selectii->currentText();
        //ui->lineEdit_setId->setReadOnly(true);

            QSqlQuery query;
            query.prepare("SELECT * FROM EMPLOYEE WHERE CIN_EMP='" + pcin + "'");

            if(query.exec())
            {
                while(query.next())
                {
                    ui->pcin->setText(query.value(0).toString());
                    ui->pnom->setText(query.value(1).toString());
                    ui->padresse->setText(query.value(2).toString());
                    ui->pdepartement->setText(query.value(3).toString());
                    ui->pposte->setText(query.value(4).toString());
                    ui->pnumtel->setText(query.value(5).toString());
                    ui->pdate->setDate(query.value(6).toDate());

                    ui->psalaire->setText(query.value(7).toString());

                    ui->mdp->setText(query.value(8).toString());

                    ui->phfixe->setText(query.value(9).toString());
                    ui->phsupp->setText(query.value(10).toString());




                    //QString type = query.value(1).toString().trimmed();  // it removes the trailing spaces
                   /* qDebug() << "Type: " << type;  // print out the type value

                    if (type == "Carton") {
                        ui->r_carton->setChecked(true);
                    } else if (type == "Plastique") {
                        ui->r_plastique->setChecked(true);
                    } else if (type == "Verre") {
                        ui->r_verre->setChecked(true);
                    }*/ // hetha tafih


                }
            }

}
