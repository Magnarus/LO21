#ifndef TACHE_COMPOSITE_H
#define TACHE_COMPOSITE_H
#include "tache.h"
class Tache_Composite : public Tache
{
    QList<Tache*> sousTaches;
    bool estSousTache(int id);
    Tache_Composite(const Tache_Composite&);
    Tache_Composite& operator=(const Tache_Composite&);
public:
    Tache_Composite(const int id, const QString& titre, const QDate&
                    dispo, const QDate& deadline,const QList<Tache*>& st = QList<Tache*>()):
    Tache(id,titre,dispo,deadline),sousTaches(st)
    {}
    void ajouterSousTache(Tache *st);
    inline virtual void afficher()const override{std::cout << "Je suis une tâche composite\n";}
};

#endif // TACHE_COMPOSITE_H
