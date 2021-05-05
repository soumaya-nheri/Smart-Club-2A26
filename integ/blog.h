#ifndef BLOG_H
#define BLOG_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"mainwindow.h"
#include "QDate"


class blog
{public:
    blog();
    blog(int,QString);
    int get_ID_blog() ;
    QString get_text ();






    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int,QString );
        QSqlQueryModel * tri();


private :

int ID_blog ;
QString text ;

};

#endif // BLOG_H
