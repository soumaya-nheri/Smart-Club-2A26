#include "fournisseur.h"
#include <QDebug>
#include "connection.h"
#include <QSqlQuery>
fournisseur::fournisseur()
{
id=0;
tel=0;
email="";
nom="";
prenom="";
}
fournisseur::fournisseur( int id, int tel,QString email, QString nom, QString prenom)
{
    this->id=id;
    this->tel=tel;
    this->email=email;
    this->nom=nom;
    this->prenom=prenom;
}
 int fournisseur::getid(){return id;}
 int fournisseur::gettel(){return  tel;}
QString fournisseur::getemail(){return  email;}
QString fournisseur::getnom(){return nom;}
QString fournisseur::getprenom(){return prenom;}


bool fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO fournisseur (ID, EMAIL, NOM, PRENOM, TEL) "
                    "VALUES (:id, :email, :nom, :prenom, :tel)");
query.bindValue(":id", res);
query.bindValue(":email", email);
query.bindValue(":nom", nom);
query.bindValue(":prenom",prenom);
query.bindValue(":tel", tel);
return    query.exec();
}

QSqlQueryModel * fournisseur::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
QString res= QString::number(id);
model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel "));



    return model;
}

bool fournisseur::supprimer( int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from fournisseur where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool fournisseur ::modifier(int id,int tel,QString email,QString nom,QString prenom )
{
    QSqlQuery query;
    query.prepare("UPDATE fournisseur SET id=:id, tel=:tel,email=:email,nom=:nom,prenom =:prenom  WHERE ID= :id ");
    query.bindValue(":id",id);
    query.bindValue(":email",email);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);

    return    query.exec();
}

