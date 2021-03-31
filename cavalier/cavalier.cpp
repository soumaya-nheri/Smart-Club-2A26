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

int Cavalier::getID(){return ID ;}
QString Cavalier::getnom(){return nom ; }
QString Cavalier::getprenom(){return prenom  ; }
QString Cavalier::getdateN(){return dateN ; }
QString Cavalier::getdateI(){return dateI ; }
QString Cavalier::gettype(){return type ; }
QString Cavalier::getEmail(){return Email  ; }
QString Cavalier::getnomE(){return nomE ; }
int Cavalier::getnum(){return num; }
QString Cavalier::getmaladie(){return maladie ;}
void Cavalier::setID(int ID){this->ID =ID;}
void Cavalier::setnom(QString nom) {this->nom=nom ; }
void Cavalier:: setprenom(QString prenom){this->prenom=prenom ; }
void Cavalier::setdateN(QString dateN){this->dateN=dateN ; }
void Cavalier::setdateI(QString dateI){this->dateI=dateI ; }
void Cavalier::settype(QString type){this->type=type ; }
void Cavalier::setEmail(QString Email){this->Email=Email ; }
void Cavalier::setnomE(QString nomE){this->nomE=nomE ; }
void Cavalier::setnum(int num){this->num=num ; }
void Cavalier::setmaladie(QString maladie){this->maladie=maladie ; }

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
bool Cavalier::supprimer(int Id_2)
{
    QSqlQuery query;

    QString res= QString::number(Id_2);

    query.prepare("Delete from cavalier where Id_2= :ID");
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
    query.bindValue(":num",res2);
    query.bindValue(":maladie",maladie);
    return    query.exec();

}






