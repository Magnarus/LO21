#include "../headers/progactivite.h"
ProgActivite::ProgActivite(const int id, const QDate& d, const QTime& dur, const QTime &h, Activite* p)throw(AgendaException)
    :Programmation(id,d,dur,h),programme(p)
{
   if(p->getDate() != d)
       throw AgendaException("L'activite ne peut pas être programmée avec ces dates !");
   if(p->getDuree() != dur)
       throw AgendaException("L'activite ne peut pas être programmée avec ces durées !");
   if(d < QDate::currentDate())
       throw AgendaException("Une programmation ne peut pas commencer dans le passé !");
   if(d == QDate::currentDate() && h < QTime::currentTime())
       throw AgendaException("Une programmation ne peut pas commencer dans le passé !");
   setType(PROGACTIVITE);
}

ProgActivite::~ProgActivite()
{
    ActiviteManager::getInstance()->supprimerItem(programme->getId());
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
