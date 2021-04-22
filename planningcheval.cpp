#include "planningcheval.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

    planningCheval::planningCheval()
    {
    Id_cheval=0;
    Nom_activite="";
    date_activite="";
    duree="";
    Id_cavalier=0;

    }
    planningCheval::planningCheval(int Id_cheval,QString Nom_activite,QString date_activite,QString duree,int Id_cavalier)
    {
      this->Id_cheval=Id_cheval;
      this->Nom_activite=Nom_activite;
      this->date_activite=date_activite;
      this->duree=duree;
      this->Id_cavalier=Id_cavalier;

    }

    int planningCheval::get_Id_cheval(){return Id_cheval;}
    QString planningCheval::get_Nom_activite(){return  Nom_activite;}
    QString planningCheval::get_date_activite(){return date_activite;}
    QString planningCheval::get_duree(){return duree ;}
    int planningCheval::get_Id_cavalier(){return Id_cavalier;}


    bool planningCheval::ajouter()
    {
    QSqlQuery query;

    QString res= QString::number(Id_cheval);

    query.prepare("INSERT INTO cheval (Id_cheval,Nom_activite,date_activite,duree,Id_cavalier) "
                        "VALUES (:Id_cheval,:Nom_activite,:date_activite,:duree,:Id_cavalier)");

    query.bindValue(":Id_cheval",res);

    query.bindValue(":Id_cheval",Id_cheval);

    query.bindValue(":Nom_activite",Nom_activite);
    query.bindValue(":date_activite",date_activite);
    query.bindValue(":duree",duree);
    query.bindValue(":Id_cavalier",Id_cavalier);




    return    query.exec();
    }

    QSqlQueryModel * planningCheval::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from cheval");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_cheval"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_activite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_activite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Id_cavalier"));



        return model;
    }

    bool planningCheval::supprimer(int ID)
    {
        QSqlQuery query;

        QString res= QString::number(ID);

        query.prepare("Delete from cheval where ID= :Id_cheval");
        query.bindValue(":Id_cheval", res);

        return    query.exec();
    }




    bool planningCheval::modifier(int Id_cheval,QString Nom_activite,QString date_activite,QString duree,int Id_cavalier)
    { QSqlQuery query;
        QString res= QString::number(Id_cheval);
        QString res2= QString::number(Id_cavalier);

        query.prepare("update cheval set ID=:Id_cheval,NOM_ACTIVITE=:Nom_activite,DATE_ACTIVITE=:date_activite,DUREE=:duree,ID_CAVALIER=:Id_cavalier, where ID=:Id_cheval");
        query.bindValue(":Id_cheval",res);
        query.bindValue(":Nom_activite",Nom_activite);
        query.bindValue(":date_activite", date_activite);
        query.bindValue(":duree",duree);
        query.bindValue(":date_activite",res2);

        return    query.exec();

    }

