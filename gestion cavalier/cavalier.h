#ifndef CAVALIER_H
#define CAVALIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"mainwindow.h"


class Cavalier
{
public:
    Cavalier();
    Cavalier(int,QString,QString,QString,QString,QString, QString, QString ,int ,QString );
    int getID() ;
    QString getnom ();
    QString getprenom ();
    QString  getdateN ();
    QString getdateI();
    QString gettype() ;
    QString getEmail() ;
    QString getnomE();
   int getnum() ;
    QString  getmaladie() ;
    void setID(int);
    void setnom(QString);
    void setprenom(QString);
    void setdateN(QString);
    void setdateI(QString);
    void settype(QString);
    void setEmail(QString);
    void setnomE(QString);
    void setnum(int);
    void setmaladie(QString);





    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int,QString,QString,QString,QString,QString, QString, QString ,int ,QString );

private :

int ID ,num ;
QString nom , prenom ,dateN , dateI , type , Email , nomE , maladie ;
};

#endif // CAVALIER_H
