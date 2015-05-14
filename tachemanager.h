#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H
#include "tache.h"
#include "tmanager.h"
#include<QDate>
#include<QTime>
class TacheManager : public TManager<Tache>
{
public:
    void ajouterTacheUnitaire(const QString& id, const QDate&
                              dispo, const QDate& deadline, const QTime& dur,bool preemptive);
    void ajouterTacheComposite(const QString& id, const QDate&
                               dispo, const QDate& deadline, const QTime& dur,const std::vector<Tache*>& st = std::vector<Tache*>());
    TacheManager();
};

#endif // TACHEMANAGER_H
