#include "cheval.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
cheval::cheval()
{
    Id_cheval=0;
    nom="";
    genre="";
    date_de_naiss="";
    vaccins="";
    date_limite_vacc="";
    poids=0;
    race="";
    nationnalite="";
    num_box=0;
    type_act="";
}
cheval::cheval(int Id_cheval,QString nom,QString genre,QString date_de_naiss,QString vaccins,QString date_limite_vacc,int poids,QString race,QString nationnalite,int num_box,QString type_act )
{
      this->Id_cheval=Id_cheval;
      this->nom=nom;
      this->genre=genre;
      this->date_de_naiss=date_de_naiss;
      this->vaccins=vaccins;
      this->date_limite_vacc=date_limite_vacc;
      this->poids=poids;
      this->race=race;
      this->nationnalite=nationnalite;
      this->num_box=num_box;
      this->type_act=type_act;
}


bool cheval::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(Id_cheval);
    query.prepare("INSERT INTO cheval (Id_cheval,nom,genre,date_de_naiss,vaccins,date_limite_vacc,poids,race,nationnalite,num_box,type_act)"
                  "VALUES(:Id_cheval,:nom,:genre,:date_de_naiss,:vaccins,:date_limite_vacc,:poids,:race,:nationnalite,:num_box,:type_act) ")
    query.bindValue(":Id_cheval",res);

    query.bindValue(":Id_cheval",Id_cheval);
    query.bindValue(":nom",nom);
    query.bindValue(":genre",genre);
    query.bindValue(":date_de_naiss",date_de_naiss);
    query.bindValue(":vaccins",vaccins);
    query.bindValue(":date_limite_vacc",date_limite_vacc);
    query.bindValue(":poids",poids);
    query.bindValue(":race",race);
    query.bindValue(":nationnalite",nationnalite);
    query.bindValue(":num_box",num_box);
    query.bindValue(":type_act",type_act);


    return    query.exec();
}
QSqlQueryModel * cheval::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chval");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_cheval"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naiss"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("vaccins"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_limite_vacc"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("poids"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("race"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("nationnalite"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("num_box"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("type_act"));

    return model;
}
bool cheval::supprimer(int ID)
{
    QSqlQuery query;

    QString res= QString::number(ID);

    query.prepare("Delete from fournisseur where ID= :Id_cheval");
    query.bindValue(":Id_cheval", res);

    return    query.exec();
}
bool cheval::modifier(int Id_cheval,QString nom,QString genre,QString date_de_naiss,QString vaccins,QString date_limite_vacc,int poids,QString race,QString nationnalite,int num_box,QString type_act)
{ QSqlQuery query;
    QString res= QString::number(Id_cheval);

    query.prepare("update cheval set ID=:Id_cheval,NOM=:nom,GENRE=:genre,DATE_DE_NAISS=:date_de_naiss,VACCINS=:vaccins,DATE_LIMITE_VACC=:date_limite_vacc,POIDS=:poids,RACE=:race,NATIONNALITE=:nationnalite,NUM_BOX=:num_box,TYPE_ACT=:type_act where ID=:Id_cheval");
    query.bindValue(":Id_cheval",res);
    query.bindValue(":nom",nom);
    query.bindValue(":genre",genre);
    query.bindValue(":date_de_naiss", date_de_naiss);
    query.bindValue(":vaccins",vaccins);
    query.bindValue(":date_limite_vacc", date_limite_vacc);
    query.bindValue(":poids",poids);
    query.bindValue(":genre",genre);
    query.bindValue(":race", race);
    query.bindValue(":nationnalite",nationnalite);
    query.bindValue(":num_box", num_box);
    query.bindValue(":type_act", type_act);
    return    query.exec();

}

