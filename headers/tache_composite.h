#ifndef TACHE_COMPOSITE_H
#define TACHE_COMPOSITE_H
#include "tache.h"
/**
 * \class       Tache_Composite tache_composite.h "headers/tache_composite.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache_Composite
 * \extends     Tache
 * \details     Une tâche composite est un ensemble de tâche qui doit être réalisé dans un interval de dates données.
 */
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
    void ajouterSousTache(Tache *st)throw(AgendaException);
    inline virtual void afficher()const override{std::cout << "Je suis une tâche composite\n";}
};

#endif // TACHE_COMPOSITE_H
