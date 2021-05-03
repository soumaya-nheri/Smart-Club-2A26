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
                  "VALUES(:Id_cheval,:nom,:genre,:date_de_naiss,:vaccins,:date_limite_vacc,:poids,:race,:nationnalite,:num_box,:type_act) ");
    query.bindValue(":Id_cheval",res);

    query.bindValue(":Id_cheval",res);
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
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CHEVAL");
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

    query.prepare("Delete from CHEVAL where Id_cheval=:ID");
    query.bindValue(":ID", res);

    return    query.exec();
}


bool cheval::modifier(int Id_cheval,int num_box)
{
    QSqlQuery query;
        QString res= QString::number(Id_cheval);
        QString res2= QString::number(num_box);


             query.prepare("UPDATE CHEVAL set ID_CHEVAL=:Id_cheval,NUM_BOX=:num_box   where ID_CHEVAL=:Id_cheval ");
             query.bindValue(":Id_cheval", res);
             query.bindValue(":num_box", res2);



            return    query.exec();


}
QSqlQueryModel * cheval::rechercher(QString N )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM CHEVAL WHERE ID_CHEVAL ='"+N+"' ;");
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
    return model ;
}
QSqlQueryModel * cheval::recherche(QString Z )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM CHEVAL WHERE NOM ='"+Z+"' ;");
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
    return model ;
}
QSqlQueryModel * cheval::trier()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM CHEVAL ORDER BY DATE_DE_NAISS DESC");
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

   /*QSqlQuery *query=new QSqlQuery;
   query->prepare("select * FROM CHEVAL ORDER BY DATE_DE_NAISS DESC") ;
   query->exec() ;
   model->setQuery(*query) ;*/


    return model;
}

QSqlQueryModel * cheval::trie()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM CHEVAL ORDER BY NUM_BOX asc");
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
QSqlQueryModel * cheval::trie2()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM CHEVAL ORDER BY NOM asc");
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
