#ifndef CHEVAL_H
#define CHEVAL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class cheval
{
public:
    cheval();
    cheval(int,QString,QString,QString,QString,QString,int,QString,QString,int,QString);
    int get_Id_cheval();
    QString get_nom();
    QString get_genre();
    QString get_date_de_naiss();
    QString get_vaccins();
    QString get_date_limite_vacc();
    int get_poids();
    QString get_race();
    QString get_nationnalite();
    int get_num_box();
    QString get_type_act();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,QString,int,QString,QString,int,QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier();
    QSqlQueryModel * trie();
private:
    QString nom,genre,date_de_naiss,vaccins,date_limite_vacc,race,nationnalite,type_act;
    int Id_cheval,poids,num_box;



};

#endif // CHEVAL_H
