#include "blog.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include<QObject>
blog::blog()
{ID_blog=0 ;
 text="";

}
blog::blog(int ID_blog, QString text)
{
    this->ID_blog=ID_blog;
    this->text=text ;

}
int blog::get_ID_blog(){return ID_blog ;}
QString blog::get_text(){return text ; }

bool blog::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(ID_blog);

    query.prepare("INSERT INTO BLOG (ID_blog,text) "
                        "VALUES (:ID_blog,:text)");

    query.bindValue(":ID_blog",res);
    query.bindValue(":text",text);

    return    query.exec();
}


QSqlQueryModel *  blog::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from blog");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_blog"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("text"));

return model;
}
bool blog::supprimer(int ID_blog)
{
    QSqlQuery query;

    QString res= QString::number(ID_blog);

    query.prepare("Delete from BLOG where ID_blog= :ID_blog");
    query.bindValue(":ID_blog", res);

    return    query.exec();
}
bool blog::modifier(int ID_blog,QString text )
{
    QSqlQuery query;
    QString res= QString::number(ID_blog);


    query.prepare("update BLOG set ID_blog=:ID_blog,text=:text  where ID_blog=:ID_blog");
    query.bindValue(":ID_blog",res);
    query.bindValue(":text",text);

    return    query.exec();


}
QSqlQueryModel * blog::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM BLOG ORDER BY ID_BLOG asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_blog"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("text"));


    return model;
}
