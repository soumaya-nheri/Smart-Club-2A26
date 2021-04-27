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
adresse="";


}
fournisseur::fournisseur(int id,int tel,QString email, QString nom, QString prenom, QString adresse)
{
    this->id=id;
    this->tel=tel;
    this->email=email;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
}
int fournisseur::getid(){return id;}
int fournisseur::gettel(){return  tel;}
QString fournisseur::getemail(){return  email;}
QString fournisseur::getnom(){return nom;}
QString fournisseur::getprenom(){return prenom;}
QString fournisseur::getadresse(){return adresse;}


bool fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO fournisseur (ID, EMAIL, NOM, PRENOM,  ADRESSE, TEL) "
                    "VALUES (:id, :email, :nom, :prenom, :adresse, :tel)");
query.bindValue(":id", res);
query.bindValue(":tel", tel);
query.bindValue(":email", email);
query.bindValue(":nom", nom);
query.bindValue(":prenom",prenom);
query.bindValue(":adresse", adresse);



return    query.exec();
}

QSqlQueryModel * fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("tel "));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

bool fournisseur::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from fournisseur where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * fournisseur::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from fournisseur where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
bool fournisseur ::modifier(int,QString,int,int,int,QString,int )
{
    QSqlQuery query;
    query.prepare("UPDATE fournisseur SET email= :email,nom=:nom,prenom =:prenom,adresse= :adresse   WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":email",email);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);


    return    query.exec();
}
