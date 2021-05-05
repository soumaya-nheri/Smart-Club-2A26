#ifndef BOUTIQUE_H
#define BOUTIQUE_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QByteArray>
#include "mainwindow.h"
class Boutique
{
public:
    Boutique();
    Boutique (int ,int);
    int getRef();
    int getQte();

    bool ajouter();

        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int ,int);


 private:
        int Ref , Qte;

};

#endif // BOUTIQUE_H
