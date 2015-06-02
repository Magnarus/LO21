#include "../headers/progactivite.h"
ProgActivite::ProgActivite(const int id, const QDate& d, const QTime& dur, Activite* p):Programmation(id,d,dur),programme(p)
{
   if(p->getDate() != this->getDate() || p->getDuree() != this->getDuree())
       throw AgendaException("L'activite ne peut pas être programmée avec ces paramètres !");
}

void ProgActivite::setDate(QDate &d)
{
    if(d > this->programme->getDate())
        throw AgendaException("Impossible de programmer une activite à une autre date que celle voulue");
    date=d;
}

void ProgActivite::setDuree(QTime &d)
{
    if(d > this->programme->getDuree())
        throw AgendaException("Impossible d'avoir une programmation plus longue que la durée de l'activite");
}
