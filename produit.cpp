#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QTextDocument>
#include <QTextCursor>
#include <QPrinter>
#include <QFileDialog>
Produit::Produit()
{

    type="";
    dater=QDate();
    quantity=0;
    prix=0;
    id=0;
}
Produit::Produit(QString type,QDate dater,int id,int quantity,int prix)
{
    this->type=type;
    this->id=id;
    this->dater=dater;
    this->quantity=quantity;
    this->prix=prix;
}
QString Produit::gettype()
{
    return type;
}
QDate Produit::getdater()
{
    return dater;
}
int Produit::getid(){
return id;
}
int Produit::getquantity()
{
    return quantity;
}
int Produit::getprix()
{
    return prix;
}
void Produit::settype(QString type)
{this->type=type;}

void Produit::setdater(QDate dater)
{this->dater=dater;}
void Produit::setid(int id)
{this->id=id;}
void Produit::setquantity(int quantity)
{this->quantity=quantity;}
void Produit::setprix(int prix)
{this->prix=prix;}
bool Produit::ajouter()
{

 QSqlQuery query;
 QString res=QString::number(id);
 QString res1=QString::number(quantity);
 QString res2=QString::number(prix);
               query.prepare("insert into produit(id,type,dater,quantity,prix)" "values ( :id, :type, :dater,  :quantity, :prix)");
               query.bindValue(":id",res);
               query.bindValue(":type",type);
               query.bindValue(":dater",dater);
               query.bindValue(":quantity",res1);
               query.bindValue(":prix",res2);
              return query.exec();

}
QSqlQueryModel * Produit::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* from produit ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("dater"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantity"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

return model;
}


bool Produit::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);
query.prepare("delete from produit where ID=:id");
query.bindValue(0,id);
return query.exec();
}

bool Produit::modifier(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(quantity);
    QString res2=QString::number(prix);
    query.prepare("UPDATE Produit SET type=:type , dater= :dater , quantity= :quantity, prix= :prix WHERE id=:id");

    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":dater",dater);
    query.bindValue(":quantity",res1);
    query.bindValue(":prix",res2);
    return query.exec();
}
void Produit::exportToPDF() {

    QTextDocument document;

    document.setDefaultStyleSheet("h1 { text-align: center; }");
    QTextCursor cursor(&document);
    cursor.insertHtml("<h1>Liste des Produits</h1>");

    QSqlQueryModel* model = afficher();
    QString htmlTable = "<table border='1'>";
    for (int row = 0; row < model->rowCount(); ++row) {
        htmlTable += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            htmlTable += "<td>" + model->data(model->index(row, col)).toString() + "</td>";
        }
        htmlTable += "</tr>";
    }
    htmlTable += "</table>";


    cursor.insertHtml(htmlTable);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) {
        return;
    }
    printer.setOutputFileName(fileName);
    document.print(&printer);
}
