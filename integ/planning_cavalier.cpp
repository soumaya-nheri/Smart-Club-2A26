
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include<QObject>
#include "planning_cavalier.h"
#include"QPinchGesture";
#include<QUrlQuery>

planning_cavalier::planning_cavalier()
{   id_cavalier=0 ;
    id_planning=0;
     horaire ="";
     appreciation=0;
    id_coach=0;
    id_cheval=0;
    id_planning=0;

}
planning_cavalier::planning_cavalier(int id_cavalier , int id_planning , QString horaire,int appreciation ,  int id_coach ,int id_cheval ,int id_evenement)
{
    this->id_cavalier=id_cavalier ;
    this->id_planning=id_planning ;
    this->horaire=horaire;
    this->appreciation=appreciation ;
    this->id_coach=id_coach ;
    this->id_cheval=id_cheval;
    this->id_evenement=id_evenement ;


}
int planning_cavalier::get_id_cavalier(){return id_cavalier ;}
int planning_cavalier::get_id_planning(){return id_planning ;}
QString planning_cavalier::get_horaire(){return horaire ; }
int planning_cavalier::get_appreciation(){return appreciation ;}
int planning_cavalier::get_id_coach(){return id_coach ;}
int planning_cavalier::get_id_cheval(){return id_cheval ;}
int planning_cavalier::get_id_evenement(){return id_evenement ;}

bool planning_cavalier::ajouter()
{
    QSqlQuery query;

    QString res= QString::number(id_cavalier);

    query.prepare("INSERT INTO planning_cavalier (id_cavalier,id_planning,horaire,appreciation,id_coach,id_cheval, id_evenement) "
                        "VALUES (:id_cavalier,:id_planning,:horaire,:appreciation,:id_coach,:id_cheval,:id_evenement)");

    query.bindValue(":id_cavalier",res);

    //query.bindValue(":ID",ID);

    query.bindValue(":id_planning",id_planning);
    query.bindValue(":horaire",horaire);
    query.bindValue(":appreciation",appreciation);
    query.bindValue(":id_coach",id_coach);
    query.bindValue(":id_cheval",id_cheval);
    query.bindValue(":id_evenement",id_evenement);

    return    query.exec();
}
QSqlQueryModel *planning_cavalier ::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from planning_cavalier");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cavalier"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_planning"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("appreciation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_coach"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_cheval"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_evenement"));

    return model;
}
bool planning_cavalier::supprimer(int id_planning)
{
    QSqlQuery query;

    QString res= QString::number(id_planning);

    query.prepare("Delete from planning_cavalier where id_planning= :id_planning");
    query.bindValue(":id_planning", res);

    return    query.exec();
}


bool planning_cavalier::modifier(int id_cavalier , int id_planning , QString horaire,int appreciation ,  int id_coach ,int id_cheval ,int id_evenement )
{
    QSqlQuery query;
    QString res= QString::number(id_cavalier);
    QString res2= QString::number(id_planning);
    QString res3= QString::number(appreciation);
    QString res4= QString::number(id_coach);
    QString res5= QString::number(id_cheval);
    QString res6= QString::number(id_evenement);


    query.prepare("update planning_cavalier set ID_CAVALIER=:id_cavalier,ID_PLANNING=:id_planning,HORAIRE=:horaire,APPRECIATION=:appreciation,ID_COACH=:id_coach,ID_CHEVAL=:id_cheval,ID_EVENEMENT=:id_evenement  where ID_PLANNING=:id_planning");
    query.bindValue(":id_cavalier",res);
    query.bindValue(":id_planning",res2);
    query.bindValue(":horaire",horaire);
    query.bindValue(":appreciation",res3);
    query.bindValue(":id_coach",res4);
    query.bindValue(":id_cheval", res5);
    query.bindValue(":id_evenement", res6);

    return    query.exec();

}

QSqlQueryModel * planning_cavalier::rechercher(QString N )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM planning_cavalier  WHERE id_planning ='"+N+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cavalier"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_planning"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("appreciation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_coach"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_cheval"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_evenement"));

    return model ;
}
QSqlQueryModel * planning_cavalier::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM planning_cavalier ORDER BY horaire asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cavalier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_planning"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("appreciation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_coach"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_cheval"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_evenement"));

    return model;
}
QSqlQueryModel * planning_cavalier::trie_coach()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM planning_cavalier ORDER BY id_coach asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cavalier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_planning"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("appreciation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_coach"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_cheval"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_evenement"));

    return model;
}

QSqlQueryModel * planning_cavalier::trie_horraire()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM planning_cavalier ORDER BY horaire asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cavalier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_planning"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("appreciation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_coach"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_cheval"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_evenement"));

    return model;
}
