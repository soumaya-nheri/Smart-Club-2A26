#ifndef PLANNING_H
#define PLANNING_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

class planning
{
public:
    planning();
    planning (int,int, QString, QString);
    int getid_planning();
    int getnb_heures();
    QString getcours();
    QString getjours_feriers();




    void setid_planning(int);
    void setnb_heures(int);
    void setcours(QString);
    void setjours_feriers(QString);



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    bool modifier(int,int,QString,QString );
    ~planning(){};


 private:
    int id_planning, nb_heures;
   QString cours,jours_feriers;
};






#endif // PLANNING_H

