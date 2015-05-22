#ifndef TACHE_COMPOSITE_H
#define TACHE_COMPOSITE_H
#include "tache.h"
class Tache_Composite : public Tache
{
    QList<Tache*> sousTaches;
    bool estSousTache(int id);
public:
    Tache_Composite(const int id, const QString& titre, const QDate&
                    dispo, const QDate& deadline, const QTime& dur,const QList<Tache*>& st = QList<Tache*>()):
    Tache(id,titre,dispo,deadline,dur),sousTaches(st)
    {}
    void ajouterSousTache(Tache *st);
    inline virtual void afficher()const override{std::cout << "Je suis une tâche composite\n";}
};

#endif // TACHE_COMPOSITE_H
