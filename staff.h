#ifndef STAFF_H
#define STAFF_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPaintEvent>

class Staff
{
public:
    Staff();

    Staff(int,QString,QString,QString,QString,QString,QString,QString,QString,int,int);
    int getid();
    QString getnom();
    QString getprenom();
    QString getdate_naiss();
    QString getadresse();
    QString getemail();
    QString gettype();
    QString getactivite();
    QString getdiplome();
    int getsalaire();
    int getnumero();

    void setid(int);
    void setnom (QString);
    void setprenom(QString);
    void setdate_naiss(QString);
    void setadresse(QString);
    void setemail(QString);
    void settype(QString);
    void setactivite(QString);
    void setdiplome(QString);
    void setsalaire(int);
    void setnumero(int);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,QString,QString,QString,QString,int,int);
    //bool modifier(int,QString,QString,QString,QString,QString,int);
  //  bool modifier();
    QSqlQueryModel * rechercher(int);
    QSqlQueryModel * afficher_tri();




private:
    int id,salaire,numero;
    QString nom,prenom,date_naiss,adresse,email,type,activite,diplome;
};



#endif // STAFF_H
