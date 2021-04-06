#include "cavalier.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include<QObject>

Cavalier::Cavalier()
{
    ID=0 ;
    nom= "" ;
    prenom = "" ;
    dateN="";
    dateI="";
    type="";
    Email="";
    nomE="";
    num=0 ;
    maladie="" ;



}
Cavalier::Cavalier(int ID ,QString nom , QString prenom , QString dateN , QString dateI , QString type , QString Email , QString nomE ,int num , QString maladie )

{
   this->ID=ID ;
   this-> nom=nom ;
   this-> prenom = prenom;
   this-> dateN=dateN;
   this-> dateI=dateI;
   this-> type=type ;
   this-> Email=Email;
    this->nomE=nomE;
    this->num=num;
    this->maladie=maladie ;

}

int Cavalier::get_ID(){return ID ;}
QString Cavalier::get_nom(){return nom ; }
QString Cavalier::get_prenom(){return prenom  ; }
QString Cavalier::get_dateN(){return dateN ; }
QString Cavalier::get_dateI(){return dateI ; }
QString Cavalier::get_type(){return type ; }
QString Cavalier::get_Email(){return Email  ; }
QString Cavalier::get_nomE(){return nomE ; }
int Cavalier::get_num(){return num; }
QString Cavalier::get_maladie(){return maladie ;}

bool Cavalier::ajouter()
{
QSqlQuery query;

QString res= QString::number(ID);

query.prepare("INSERT INTO Cavalier (ID,nom,prenom,dateN,dateI,type, Email,nomE,num,maladie) "
                    "VALUES (:ID,:nom,:prenom,:dateN,:dateI,:type,:Email,:nomE,:num,:maladie)");

query.bindValue(":ID",res);

//query.bindValue(":ID",ID);

query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":dateN",dateN);
query.bindValue(":dateI",dateI);
query.bindValue(":type",type);
query.bindValue(":Email",Email);
query.bindValue(":nomE",nomE);
query.bindValue(":num",num);
query.bindValue(":maladie",maladie);
return    query.exec();
}
QSqlQueryModel * Cavalier::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Cavalier");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateI"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dateN"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("nomE"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("maladie"));
return model;
}
bool Cavalier::supprimer(int id)
{
    QSqlQuery query;

    QString res= QString::number(id);

    query.prepare("Delete from cavalier where id= :ID");
    query.bindValue(":ID", res);

    return    query.exec();
}


bool Cavalier::modifier(int ID,QString nom,QString prenom,QString dateN,QString dateI,QString type ,QString Email , QString nomE, int num , QString maladie  )
{
    QSqlQuery query;
    QString res= QString::number(ID);
    QString res2= QString::number(num);

    query.prepare("update Cavalier set Id=:ID,NOM=:nom,PRENOM=:prenom,DATEN=:dateN,DATEI=:dateI,TYPE=:type,email=:Email ,NOME=:nomE, NUM=:num ,MALADIE=:maladie  where Id=:ID");
    query.bindValue(":ID",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":dateN",dateN);
    query.bindValue(":dateI",dateI);
    query.bindValue(":type", type);
    query.bindValue(":Email", Email);
    query.bindValue(":nomE",nomE);
    query.bindValue(":num",res2);
    query.bindValue(":maladie",maladie);
    return    query.exec();

}






