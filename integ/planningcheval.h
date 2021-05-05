#ifndef PLANNINGCHEVAL_H
#define PLANNINGCHEVAL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class planningCheval
{public:
    planningCheval();
    planningCheval(int,QString,QString,QString,int);

    int get_Id_cheval();
    QString get_Nom_activite();
    QString get_date_activite();
    QString get_duree();
    int get_Id_cavalier();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString);
     QSqlQueryModel * tri();
     QSqlQueryModel *triePlanningChev();
     QSqlQueryModel *tri3();


private:
    QString Nom_activite,date_activite,duree;
    int Id_cheval,Id_cavalier;
};

#endif // PLANNINGCHEVAL_H

