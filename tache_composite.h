#ifndef TACHE_COMPOSITE_H
#define TACHE_COMPOSITE_H
#include "tache.h"
class Tache_Composite : public Tache
{
    std::vector<Tache*> sousTaches;
public:
    Tache_Composite(const QString& id, const QDate&
                    dispo, const QDate& deadline, const QTime& dur,const std::vector<Tache*>& st = std::vector<Tache*>()):
    Tache(id,dispo,deadline,dur),sousTaches(st)
    {}
    void ajouterSousTache(Tache& st);
    virtual void afficher(){}
};

#endif // TACHE_COMPOSITE_H
