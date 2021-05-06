#ifndef STOCK_H
#define STOCK_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>



class Equipement
{
public:
    Equipement();
    Equipement(int,int,int,QDate,QDate,QString,QString);
    int getid();
    int getquantite();
    QDate getdate();
    QDate getdeadline();
    int getprix();
    QString gettype();
    QString getetat();

    void setquantite (int);
    void setdate(QDate);
    void setdeadline(QDate);
    void setprix(int);
    void settype(QString);
    void setetat(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_tri() ;
    bool supprimer(int);
    QSqlQueryModel * rechercher(int);
    bool modifier(int,int,int,QDate,QDate,QString,QString );
    ~Equipement(){};


private:
    int id,quantite,prix;
    QDate date,deadline;
    QString type,etat;
};
class equipementh
{
public:
       equipementh() ;
       equipementh(QString,QString,QString) ;
       QString get_nom();
       QString get_datee();
       QString get_fn();
       QSqlQueryModel * afficherhis() ;

       bool ajoutehis();
       bool modifierhis() ;
private:

    QString nom,datee,fn ;
};

#endif // STOCK_H
