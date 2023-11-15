#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QString>
#include <QMessageBox>
#include <QDate>
#include <QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tap_produit->setModel(p.afficher());
    ui->lineEdit_code->setValidator(new QRegExpValidator(QRegExp("\\d+"),this));
    ui->lineEdit_date_3->setValidator(new QRegExpValidator(QRegExp("\\d+"),this));
    ui->lineEdit_date_4->setValidator(new QRegExpValidator(QRegExp("\\d+"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_valider_clicked()
{

    QString type=ui->lineEdit_type->text();
    QDate dater=ui->lineEdit_date->date();
    int id=ui->lineEdit_code->text().toInt();
    int quantity=ui->lineEdit_date_3->text().toInt();
    int prix=ui->lineEdit_date_4->text().toInt();
    Produit p(type,dater,id,quantity,prix);
    bool test=p.ajouter();
    QMessageBox msgBox;
    if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n""click cancel to exit ."),QMessageBox::Cancel);
            ui->tap_produit->setModel(p.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
            QObject::tr("ajout non effectue\n""click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    Produit p1;
    p1.setid(ui->lineEdit_code_supp->text().toInt());
    bool test=p1.supprimer(p1.getid());
    if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("suppression effectue\n""click cancel to exit ."),QMessageBox::Cancel);
            ui->tap_produit->setModel(p.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
            QObject::tr("suppression non effectue\n""click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_valider_2_clicked()
{
    QString type=ui->lineEdit_type->text();
    QDate dater=ui->lineEdit_date->date();
    int id=ui->lineEdit_code->text().toInt();
    int quantity=ui->lineEdit_date_3->text().toInt();
    int prix=ui->lineEdit_date_4->text().toInt();
    Produit p(type,dater,id,quantity,prix);
    bool test=p.modifier(id);
    QMessageBox msgBox;
    if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("update effectue\n""click cancel to exit ."),QMessageBox::Cancel);
            ui->tap_produit->setModel(p.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
            QObject::tr("update non effectue\n""click cancel to exit ."),QMessageBox::Cancel);
}


void MainWindow::on_valider_3_clicked()
{

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM produit ORDER BY id");
        ui->tap_produit->setModel(model);

                QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("update effectue\n""click cancel to exit ."),QMessageBox::Cancel);

    }

}


void MainWindow::on_pb_chercher_2_clicked()
{
    QString type = ui->lineEdit_code_supp_4->text();

    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM produit WHERE type = '" + type + "'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dater"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantity"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    ui->tap_produit->setModel(model);

    qDebug() << model->rowCount();
    QMessageBox::information(nullptr,QObject::tr("OK"),
        QObject::tr("update effectue\n""click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_pb_chercher_3_clicked()
{
    QSqlQuery query("SELECT type, AVG(quantity) AS moyenne_quantity, MIN(quantity) AS min_quantity, MAX(quantity) AS max_quantity FROM produit GROUP BY type");

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);

    ui->tap_produit->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantité moyenne"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité minimale"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité maximale"));
    QMessageBox::information(nullptr, QObject::tr("statistiques"),
                             QObject::tr("statistiques affichées\nclick cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_valider_4_clicked()
{
    Produit p;
        p.exportToPDF();
}

void MainWindow::on_valider_5_clicked()
{

}
