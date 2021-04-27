#include "equipement.h"
#include <QDebug>
#include "connection.h"
#include <QSqlQuery>


Equipement::Equipement()
{   id=0;
    quantite=0;
    date=0;
    deadline=0;
    prix=0;
    type="";
    etat="";
}
Equipement::Equipement(int id,int prix,int quantite, int date,int deadline , QString etat,QString type )
{
    this->id=id;
    this->quantite=quantite;
    this->type=type;
    this->date=date;
    this->deadline=deadline;
    this->etat=etat;
    this->prix=prix;
}
int Equipement::getid(){return id;}
int Equipement::getquantite(){return  quantite;}
QString Equipement::gettype(){return  type;}
int Equipement::getdate(){return  date;}
int Equipement::getdeadline(){return deadline;}
QString Equipement::getetat(){return etat;}
int Equipement::getprix(){return prix;}



bool Equipement::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Equipement (ID_PRODUIT, TYPE, QUANTITE, DATE_ARRIVEE,  DEADLINE, ETAT, PRIX) "
                    "VALUES (:id, :type, :quantite, :date, :deadline, :etat, :prix)");
query.bindValue(":id", res);
query.bindValue(":type", type);
query.bindValue(":quantite", quantite);
query.bindValue(":date", date);
query.bindValue(":deadline", deadline);
query.bindValue(":etat", etat);
query.bindValue(":prix", prix);



return    query.exec();
}

QSqlQueryModel * Equipement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Equipement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("prix "));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("deadline"));
model->setHeaderData(0,Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(0,Qt::Horizontal, QObject::tr("type"));

    return model;
}

bool Equipement::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from Equipement where ID_PRODUIT= :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * Equipement::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from Equipement where ID_PRODUIT =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
bool Equipement ::modifier(int id,int prix,int quantite, int date,int deadline , QString etat,QString type)
{
    QSqlQuery query;
    query.prepare("UPDATE Equipement SET id_produit=:id, prix = :prix,quantite = :quantite,date_arrivee=:date,deadline=:deadline,etat= :etat,type=:type  WHERE id_produit= :id ");
    query.bindValue(":id",id);
    query.bindValue(":prix",prix);
    query.bindValue(":quantite",quantite);
    query.bindValue(":date",date);
    query.bindValue(":deadline",deadline);
    query.bindValue(":etat",etat);
    query.bindValue(":type",type);



    return    query.exec();
}

