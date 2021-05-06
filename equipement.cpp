#include "equipement.h"
#include <QDebug>
#include "connection.h"
#include <QSqlQuery>
#include <QDateEdit>
Equipement::Equipement()
{   id=0;
    quantite=0;
    prix=0;
    type="";
    etat="";
}
Equipement::Equipement(int id,int prix,int quantite, QDate date,QDate deadline , QString etat , QString type )
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
QDate Equipement::getdate(){return  date;}
QDate Equipement::getdeadline(){return deadline;}
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
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_arrivee"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("deadline"));
model->setHeaderData(5,Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(6,Qt::Horizontal, QObject::tr("prix"));

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
bool Equipement ::modifier(int id,int prix,int quantite, QDate date,QDate deadline , QString etat,QString type)
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
equipementh::equipementh()
{
nom="";
datee="";
fn="";
}
equipementh::equipementh(QString nom,QString datee,QString fn)
{
    this->nom=nom;
    this->datee=datee;
    this->fn=fn ;
}
QString equipementh::get_datee(){return  datee;}
QString equipementh::get_fn(){return  fn;}
QString equipementh::get_nom(){return  nom;}
bool equipementh::ajoutehis()
{
    QSqlQuery query;
    query.prepare("INSERT INTO historique (NOM, DATEE, FN) "
                  "VALUES (:nom, :datee, :fn)");
    query.bindValue(":nom", nom);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
bool equipementh::modifierhis()
{
    QSqlQuery query;
    query.prepare("UPDATE historique SET datee='"+datee+"',fn='"+fn+"' where nom='"+nom+"' ");
    query.bindValue(":nom",nom);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}

QSqlQueryModel * equipementh::afficherhis()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from historique");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("fonction "));
        return model;

}
QSqlQueryModel * Equipement::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from equipement order by ID_PRODUIT desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

    return model;
}




