#include "event.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
event::event()
{
id=0; categorie=" "; nom=" "; description=" "; date=" "; resultat=" ";
nb_participant=0; nb_coach=0; nb_cheval=0; nb_spectacle=0;
}
 event::event(int id, QString Categorie, QString nom,QString description ,  QString date, QString resultat , int nb_participant, int nb_cheval, int nb_coach, int nb_spectacle )
 {this->id=id,this->categorie=Categorie, this->nom=nom, this->description=description, this->date=date, this->resultat=resultat, this->nb_participant=nb_participant, this->nb_cheval=nb_cheval, this->nb_coach=nb_coach, this->nb_spectacle=nb_spectacle; }
 int event::getid(){return id;}
 QString event::getCategorie(){return categorie;}
 QString event::getnom(){return nom;}
 QString event::getdescription(){return description;}
 QString event::getdate(){return date;}
 QString event::getresultat(){return resultat;}
 int event::getnb_participant(){return nb_participant;}
 int event::getnb_cheval(){return nb_cheval;}
 int event::getnb_coach(){return nb_coach;}
 int event::getnb_spectacle(){return nb_spectacle;}

 void event::setid(int id){this->id=id;}
 void event::setCategorie(QString categorie){this->categorie=categorie;}
 void event::setnom(QString nom){this->nom=nom;}
 void event::setdescription(QString description){this->description=description;}
 void event::setdate(QString date){this->date=date;}
 void event::setresultat(QString resultat){this->resultat=resultat;}
 void event::setnb_participant(int nb_participant){this->nb_participant=nb_participant;}
 void event::setnb_cheval(int nb_cheval){ this->nb_cheval=nb_cheval;}
 void event::setnb_spectacle(int nb_coach){this->nb_coach=nb_coach;}
 void event::setnb_coach(int nb_spectacle){this->nb_spectacle=nb_spectacle;}
 bool event::ajouter()
 {
     QSqlQuery query;
    QString id_string= QString::number(id);
    QString participant_string= QString::number(nb_participant);
    QString cheval_string= QString::number(nb_cheval);
    QString coach_string= QString::number(nb_coach);
    QString spectacle_string= QString::number(nb_spectacle);
          query.prepare("INSERT INTO event(id, categorie,date_event, nb_participant, nb_cheval, nb_coach, nb_spectacle, nom, description,  resultat) "
                        "VALUES (:id, :categorie, :date, :nb_participant, :nb_cheval, :nb_coach, :nb_spectacle, :nom, :description ,:resultat)");
          query.bindValue(":id", id_string);
          query.bindValue(":categorie",categorie);
          query.bindValue(":date",date);
          query.bindValue(":nb_participant",participant_string);
          query.bindValue(":nb_cheval",cheval_string);
          query.bindValue(":nb_coach",coach_string);
          query.bindValue(":nb_spectacle",spectacle_string);
          query.bindValue(":nom",nom);
          query.bindValue(":description",description);
          query.bindValue(":resultat",resultat);
          return query.exec();


}
 QSqlQueryModel * event::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from event");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("categorie "));
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("date"));
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("nb_participant"));
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("nb_cheval"));
 model->setHeaderData(0,Qt::Horizontal, QObject::tr("nb_coach"));
 model->setHeaderData(0,Qt::Horizontal, QObject::tr("nb_spectacle"));
 model->setHeaderData(0,Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(0,Qt::Horizontal, QObject::tr("description"));
 model->setHeaderData(0,Qt::Horizontal, QObject::tr("resultat"));

     return model;
 }
 bool event::modifier(int id, QString categorie, QString nom,QString description ,  QString date, QString resultat , int nb_participant, int nb_cheval, int nb_coach, int nb_spectacle)
 {
     QSqlQuery query;
     query.prepare("UPDATE event SET id= :id,categorie= :categorie,date_event= :date_event,nb_participant= :nb_participant,nb_cheval= :nb_cheval,nb_coach= :nb_coach,nb_spectacle= :nb_spectacle,nom= :nom,description= :description, resultat= :resultat  WHERE id= :id ");
     query.bindValue(":id",id);
     query.bindValue(":categorie",categorie);
     query.bindValue(":date",date);
     query.bindValue(":nb_participant",nb_participant);
     query.bindValue(":nb_cheval",nb_cheval);
     query.bindValue(":nb_coach",nb_coach);
     query.bindValue(":nb_spectacle",nb_spectacle);
     query.bindValue(":nom",nom);
     query.bindValue(":description",description);
     query.bindValue(":resultat",resultat);
     return query.exec();
 }
 bool event::supprimer(int id)
 {
 QSqlQuery query;
 QString res= QString::number(id);
 query.prepare("Delete from event where ID = :id ");
 query.bindValue(":id", res);
 return    query.exec();
 }

 QSqlQueryModel * event::rechercher(QString categorie)
 {

     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("Select * from event where categorie=:categorie");
     query.bindValue(":categorie",categorie);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("categorie"));

         return model;
    }
