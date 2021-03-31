#ifndef PLANNING_CAVALIER_H
#define PLANNING_CAVALIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"mainwindow.h"

class planning_cavalier
{
public:
    planning_cavalier();
   planning_cavalier(int,int,QString,int,int,int, int );
    int getid_cavalier() ;
    int getid_planning ();
    QString gethoraire ();
    int  getappreciation ();
    int getid_coach();
    int getid_cheval() ;
    int getid_evenement() ;

    void setid_cavalier(int);

    void setid_planning(int);
    void sethoraire(QString);
    void setappreciation(int);
    void setid_coach(int);
    void setid_cheval(int);
    void setid_evenement(int);
    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int,int,QString,int,int,int, int );


private :

int id_cavalier ,id_planning,appreciation ,id_coach , id_cheval , id_evenement ;
QString horaire;

};

#endif // PLANNING_CAVALIER_H
