#include "../headers/progtunit.h"
ProgTUnit::ProgTUnit(const int id, const QDate& d, const QTime& dur, Tache_Unitaire* p):Programmation(id,d,dur),programme(p)
{
    if(d < p->getDateDispo() || d > p->getEcheance() || dur > p->getDuree())
        throw AgendaException("Dates incompatibles avec la tâche");
}

void ProgTUnit::setDate(QDate &d)
{
    if(d < this->programme->getDateDispo()|| d > this->programme->getEcheance())
        throw AgendaException("Impossible de programmer une activite à une autre date que celle voulue");
    date=d;
}

void ProgTUnit::setDuree(QTime &d)
{
    if(d > this->programme->getDuree())
        throw AgendaException("Impossible d'avoir une programmation plus longue que la durée de l'activite");
}
