#include "crud.h"
#include "main.cpp"

Crud::Crud(){}
QSqlDatabase db;
bool Crud::createcrud()
{

   db = QSqlDatabase::addDatabase("QODBC");
   bool test=false ;
   db.setDatabase("");


}
void Crud::closecrud(){db.close();}
