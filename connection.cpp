#include "connection.h"

connection::connection()
{

}

bool connection::ouvrirconnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("yoser");//inserer nom de l'utilisateur
db.setPassword("1111");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

else throw QString ("erreur"+test);



    return  test;
}
void connection::fermerconnexion()
{db.close();

}
