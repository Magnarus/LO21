#include "../headers/progTUnit.h"
ProgTUnit::ProgTUnit(const int id, const QDate& d, const QTime& dur, const QTime &h, Tache_Unitaire* p)throw(AgendaException)
    :Programmation(id,d,dur,h),programme(p)
{
    setType(PROGTACHE);
    QDate currDate = QDate::currentDate();
    QTime currTime = QTime::currentTime();
    if(d < p->getDateDispo() || d > p->getEcheance() || dur > p->getDuree())
        throw AgendaException("Dates incompatibles avec la tâche");
    if(d.day() < currDate.day())
        throw AgendaException("Une programmation ne peut pas commencer dans le passé !1");
    if(d.day() == currDate.day() && h.hour() < currTime.hour())
        throw AgendaException("Une programmation ne peut pas commencer dans le passé !2");
}

void ProgTUnit::setDate(const QDate &d)throw(AgendaException)
{
    if(d < this->programme->getDateDispo()|| d > this->programme->getEcheance())
        throw AgendaException("Impossible de programmer une activite à une autre date que celle voulue");
    date=d;
}
ProgTUnit::~ProgTUnit()
{
    TacheManager::getInstance()->supprimerItem(programme->getId());
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
