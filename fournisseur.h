#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
class fournisseur
{
    public:
    fournisseur();
    fournisseur(int, int,QString,QString,QString);
     int getid();
     int gettel();
    QString getnom();
    QString getprenom();
    QString getemail();

    void setid ( int);
    void settel(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer( int);
    QSqlQueryModel * rechercher( int);
    bool modifier( int, int,QString,QString,QString);
    ~fournisseur(){};


private:
     int id,tel;
    QString nom,prenom,email;
};

#endif // FOURNISSEUR_H
