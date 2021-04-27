#ifndef STOCK_H
#define STOCK_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Equipement
{
public:
    Equipement();
    Equipement(int,int,int,int,int,QString,QString);
    int getid();
    int getquantite();
    int getdate();
    int getdeadline();
    int getprix();
    QString gettype();
    QString getetat();

    void setquantite (int);
    void setdate(int);
    void setdeadline(int);
    void setprix(int);
    void settype(QString);
    void setetat(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(int);
    bool modifier(int,int,int,int,int,QString,QString );
    ~Equipement(){};


private:
    int id,quantite,date,deadline,prix;
    QString type,etat;
};

#endif // STOCK_H
