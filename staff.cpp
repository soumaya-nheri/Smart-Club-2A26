#include "staff.h"
#include <QDebug>
#include "connection.h"
#include <QSqlQuery>
#include <QDialog>


Staff::Staff()
{   id=0;
    nom="";
    prenom="";
    adresse="";
    date_naiss="";
    email="";
    type="";
    activite="";
    diplome="";
    numero=0;
    salaire=0;
}
Staff::Staff(int id,QString nom,QString prenom,QString date_naiss, QString adresse, QString email, QString type, QString activite , QString diplome , int numero, int salaire)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->date_naiss=date_naiss;
    this->email=email;
    this->type=type;
    this->activite=activite;
    this->diplome=diplome;
    this->numero=numero;
    this->salaire=salaire;

}
int Staff::getid(){return id;}
QString Staff::getnom(){return  nom;}
QString Staff::getprenom(){return  prenom;}
QString Staff::getadresse(){return  adresse;}
QString Staff::getdate_naiss(){return  date_naiss;}
QString Staff::getemail(){return  email;}
QString Staff::gettype(){return  type;}
QString Staff::getactivite(){return  activite;}
QString Staff::getdiplome(){return  diplome;}
int Staff::getnumero(){return  numero;}
int Staff::getsalaire(){return  salaire;}


bool Staff::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO STAFF (ID, NOM, PRENOM, NUMERO,DIPLOME,DATE_NAIS,ADRESSE,SALAIRE,EMAIL,ACTIVITE,TYPE) "
                    "VALUES (:id, :nom, :prenom, :numero, :diplome, :date_naiss, :adresse, :salaire, :email, :activite, :type)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":date_naiss", date_naiss);
query.bindValue(":email", email);
query.bindValue(":type", type);
query.bindValue(":activite", activite);
query.bindValue(":diplome", diplome);
query.bindValue(":numero", numero);
query.bindValue(":salaire", salaire);

return    query.exec();
}
QSqlQueryModel * Staff::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from STAFF");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Nais"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Activite"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Diplome"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numero"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Salaire"));
    return model;

}
bool Staff::modifier(int id ,QString nom,QString prenom,QString adresse,QString date_naiss,QString email,QString type,QString activite,QString diplome,int numero,int salaire)
{
    QSqlQuery query;
    query.prepare("UPDATE staff SET id= :id,nom= :nom,prenom= :prenom,adresse= :adresse,date_nais= :date_naiss,email= :email,type= :type,activite= :activite,diplome= :diplome, numero= :numero, salaire= :salaire  WHERE id= :id ");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":date_naiss", date_naiss);
    query.bindValue(":email", email);
    query.bindValue(":type", type);
    query.bindValue(":activite", activite);
    query.bindValue(":diplome", diplome);
    query.bindValue(":numero", numero);
    query.bindValue(":salaire", salaire);

    return    query.exec();
}
bool Staff::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from staff where ID = :id ");
query.bindValue(":id", id );
return    query.exec();
}

QSqlQueryModel * Staff::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from staff where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
QSqlQueryModel * Staff::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from staff order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

    return model;
}


