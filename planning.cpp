#include "planning.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>

planning::planning()
{
   id_planning=0;
    nb_heures=0;
    cours=" ";
    jours_feriers=" ";

}
planning::planning(int id_planning,int nb_heures, QString cours,QString jours_feriers)
{this->id_planning=id_planning,this->nb_heures=nb_heures, this->cours=cours, this->jours_feriers=jours_feriers; }
int planning::getid_planning(){return id_planning;}
int planning::getnb_heures(){return nb_heures;}
QString planning::getcours(){return cours;}
QString planning::getjours_feriers(){return jours_feriers;}




void planning::setid_planning(int id_planning){this->id_planning=id_planning;}
void planning::setnb_heures(int nb_heures){this->nb_heures=nb_heures;}
void planning::setcours(QString cours){this->cours=cours;}
void planning::setjours_feriers(QString jours_feriers){this->jours_feriers=jours_feriers;}


bool planning::ajouter()
{
    QSqlQuery query;
   QString id_plan= QString::number(id_planning);
   QString nbh= QString::number(nb_heures);


         query.prepare("INSERT INTO planning(id_planning,nb_heures,cours,jours_feriers) "
                       "VALUES (:id_planning, :nb_heures, :cours, :jours_feriers)");
         query.bindValue(":id_planning", id_plan);
         query.bindValue(":nb_heures",nbh);
         query.bindValue(":cours",cours);
         query.bindValue(":jours_feriers",jours_feriers);


         return query.exec();


}
QSqlQueryModel * planning::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from planning");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_planning"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_heures "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("cours"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("jours_feriers"));



    return model;
}

bool planning::supprimer(int id_planning)
{
QSqlQuery query;
QString res= QString::number(id_planning);
query.prepare("Delete from planning where id_planning = :id_planning ");
query.bindValue(":id_planning", res);
return    query.exec();
}

bool planning::modifier(int id_planning ,int nb_heures,QString cours,QString jours_feriers)
{
    QSqlQuery query;
    query.prepare("UPDATE planning SET id_planning= :id_planning,nb_heures= :nb_heures,cours= :cours,jours_feriers= :jours_feriers WHERE id_planning= :id_planning ");
    query.bindValue(":id_planning", id_planning);
    query.bindValue(":nb_heures", nb_heures);
    query.bindValue(":cours", cours);
    query.bindValue(":jours_feriers", jours_feriers);


    return    query.exec();
}
