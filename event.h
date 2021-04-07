#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QDate>



class event
{
public:
    void setcategorie(QString n);
    void setdate_event(QDate n);
    void setnb_participant(QString n);
    QString get_categorie();
    QDate get_date_event();
    QString get_nb_participant();

    event();

private:
    QString categorie,nb_participant;
    QDate date_event;

};

#endif // EVENT_H
