#include "boutique.h"

Boutique::Boutique()
{


}
Boutique::Boutique(int Ref ,int Qte)
{
    this-> Ref=Ref;
    this ->Qte=Qte;

}
int Boutique::getRef() {return Ref;}
int Boutique::getQte(){return Qte;}

bool Boutique::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(Ref);

    query.prepare("INSERT INTO Boutique (Ref,Qte) "
                        "VALUES (:Ref,:Qte)");

    query.bindValue(":Ref",res);
    query.bindValue(":Qte",Qte);

    return    query.exec();
}

QSqlQueryModel * Boutique::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Boutique");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Qte"));


return model;
}

bool Boutique::supprimer(int Ref)
{
    QSqlQuery query;

    QString res= QString::number(Ref);

    query.prepare("Delete from BOUTIQUE where Ref= :Ref");
    query.bindValue(":Ref", res);

    return    query.exec();
}


bool Boutique::modifier(int Ref,int Qte)
{
    QSqlQuery query;
    QString res= QString::number(Ref);
   QString res2= QString::number(Qte);

    query.prepare("update BOUTIQUE set Ref=:Ref,Qte=:Qte  where Ref=:Ref");
    query.bindValue(":Ref",res);
    query.bindValue(":Qte",res2);

    return    query.exec();

}
