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
    int get_id_cavalier() ;
    int get_id_planning ();
    QString get_horaire ();
    int  get_appreciation ();
    int get_id_coach();
    int get_id_cheval() ;
    int get_id_evenement() ;




    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int,int,QString,int,int,int, int );


private :

int id_cavalier ,id_planning,appreciation ,id_coach , id_cheval , id_evenement ;
QString horaire;

};

#endif // PLANNING_CAVALIER_H
