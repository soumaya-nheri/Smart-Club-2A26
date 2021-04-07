#include "participant.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>

participant::participant()
{
    id_participant=0;
    nom=" ";
    prenom=" ";
    cin=0;
    id_event=0;
}
participant::participant(int id_participant, QString nom,QString prenom ,int cin, int id_event)
{this->id_participant=id_participant,this->nom=nom, this->prenom=prenom, this->cin=cin, this->id_event=id_event; }
int participant::getid_participant(){return id_participant;}
QString participant::getnom(){return nom;}
QString participant::getprenom(){return prenom;}
int participant::getcin(){return cin;}
int participant::getid_event(){return id_event;}


void participant::setid_participant(int id_participant){this->id_participant=id_participant;}
void participant::setnom(QString nom){this->nom=nom;}
void participant::setprenom(QString prenom){this->prenom=prenom;}
void participant::setcin(int cin){this->cin=cin;}
void participant::setid_event(int id_event){ this->id_event=id_event;}
bool participant::ajouter()
{
    QSqlQuery query;
   QString id_string= QString::number(id_participant);
   QString cin_string= QString::number(cin);
   QString id2= QString::number(id_event);

         query.prepare("INSERT INTO participant(id_participant,nom,prenom,cin,id_event) "
                       "VALUES (:id_participant, :nom, :prenom, :cin, :id_event)");
         query.bindValue(":id_participant", id_string);
         query.bindValue(":nom",nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":cin",cin_string);
         query.bindValue(":id_event",id2);

         return query.exec();


}
QSqlQueryModel * participant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from participant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_participant"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_event"));


    return model;
}
bool participant::supprimer(int id_participant)
{
QSqlQuery query;
QString res= QString::number(id_participant);
query.prepare("Delete from participant where ID = :id_participant ");
query.bindValue(":id_participant", res);
return    query.exec();
}


bool participant ::modifier(int,QString,QString,int,int )
{
    QSqlQuery query;
    query.prepare("UPDATE participant SET nom= :nom,prenom=:prenom,cin = :cin,id_event= :id_event  WHERE id_participant= :id_participant ");
    query.bindValue(":id_participant",id_participant);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":cin",cin);
     query.bindValue(":id_event",id_event);


    return    query.exec();
}

