#include "event.h"

event::event()
{
    categorie="";
    date_event="";
    nb_participant="";

}
void event::setcategorie(QString n){categorie=n;}
void event::setdate_event(QDate n){date_event=n;}
void event::setnb_participant(QString n){nb_participant=n;}
QString  event::get_categorie(){return categorie;}
QDate event::get_date_event(){return date_event;}
QString event::get_nb_participant(){return nb_participant;}
