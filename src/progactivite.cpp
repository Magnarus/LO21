#include "../headers/progactivite.h"
ProgActivite::ProgActivite(const int id, const QDate& d, const QTime& dur, Activite* p)throw(AgendaException)
    :Programmation(id,d,dur),programme(p)
{
   if(p->getDate() != d)
       throw AgendaException("L'activite ne peut pas être programmée avec ces dates !");
   if(p->getDuree() != dur)
       throw AgendaException("L'activite ne peut pas être programmée avec ces durées !");
   setType(PROGACTIVITE);
}

void ProgActivite::setDate(const QDate &d)throw(AgendaException)
{
    if(d > this->programme->getDate())
        throw AgendaException("Impossible de programmer une activite à une autre date que celle voulue");
    date=d;
}

void ProgActivite::setDuree(const QTime &d)throw(AgendaException)
{
    if(d > this->programme->getDuree())
        throw AgendaException("Impossible d'avoir une programmation plus longue que la durée de l'activite");
}
