#ifndef CAVALIER_H
#define CAVALIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"mainwindow.h"
#include "QDate"
class Cavalier
{
public:
    Cavalier();
    Cavalier(int,QString,QString,QString,QString,QString, QString, QString ,int ,QString );
    int get_ID() ;
    QString get_nom ();
    QString get_prenom ();
    QString  get_dateN ();
    QString get_dateI();
    QString get_type() ;
    QString get_Email() ;
    QString get_nomE();
   int get_num() ;
    QString  get_maladie() ;
    




    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int,QString,QString,QString,QString,QString, QString, QString ,int ,QString );

private :

int ID ,num ;
QString nom , prenom, dateN,dateI,type , Email , nomE , maladie ;

};

#endif // CAVALIER_H
