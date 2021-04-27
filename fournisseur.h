#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class fournisseur
{
    public:
    fournisseur();
    fournisseur(int,int,QString,QString,QString,QString);
    int getid();
    int gettel();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getemail();

    void setid (int);
    void settel(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setemail(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(int);
    bool modifier(int,QString,int,int,int,QString,int);
    ~fournisseur(){};


private:
    int id,tel;
    QString nom,prenom,adresse,email;
};

#endif // FOURNISSEUR_H
