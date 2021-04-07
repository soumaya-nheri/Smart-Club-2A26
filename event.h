#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

class event
{
public:
    event();
    event (int, QString, QString, QString, QString, QString, int, int, int, int );
    int getid();
    QString getCategorie();
    QString getnom();
    QString getdescription();
    QString getdate();
    QString getresultat();
    int getnb_participant();
    int getnb_cheval();
    int getnb_coach();
    int getnb_spectacle();

    void setid(int);
    void setCategorie(QString);
    void setnom(QString);
    void setdescription(QString);
    void setdate(QString);
    void setresultat(QString);
    void setnb_participant(int);
    void setnb_cheval(int);
    void setnb_spectacle(int);
    void setnb_coach(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    bool modifier(int, QString, QString, QString, QString, QString, int, int, int, int );
    ~event(){};


 private:
    int id, nb_participant, nb_cheval, nb_coach, nb_spectacle;
   QString categorie, nom, description, resultat, date;
};


#endif // EVENT_H
