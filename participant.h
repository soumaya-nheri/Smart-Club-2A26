#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>


class participant
{
public:
    participant();
    participant (int, QString, QString, int, int );
    int getid_participant();
    QString getnom();
    QString getprenom();
    int getcin();
    int getid_event();


    void setid_participant(int);
    void setnom(QString);
    void setprenom(QString);
    void setcin(int);
    void setid_event(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(int);
    bool modifier(int, QString, QString, int, int  );
    ~participant(){};

 private:
    int id_participant,cin,id_event;
   QString nom,prenom;

};

#endif // PARTICIPANT_H
