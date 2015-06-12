#include "../headers/progTUnit.h"
ProgTUnit::ProgTUnit(const int id, const QDate& d, const QTime& dur, Tache_Unitaire* p)throw(AgendaException)
    :Programmation(id,d,dur),programme(p)
{
    setType(PROGTACHE);
    if(d < p->getDateDispo() || d > p->getEcheance() || dur > p->getDuree())
        throw AgendaException("Dates incompatibles avec la tâche");
}

void ProgTUnit::setDate(const QDate &d)throw(AgendaException)
{
    if(d < this->programme->getDateDispo()|| d > this->programme->getEcheance())
        throw AgendaException("Impossible de programmer une activite à une autre date que celle voulue");
    date=d;
}

void ProgTUnit::setDuree(const QTime &d)throw(AgendaException)
{
    if(d > this->programme->getDuree())
        throw AgendaException("Impossible d'avoir une programmation plus longue que la durée de l'activite");
}

bool ProgTUnit::estProg(const Tache_Unitaire* t)
{
    return programme->getId() == t->getId();
}
