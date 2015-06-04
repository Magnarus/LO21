#ifndef TACHEPREEMPTIVE_H
#define TACHEPREEMPTIVE_H
#include "tache_unitaire.h"
/**
 * \class       TachePreemptive tachepreemptive.h "headers/tachenonpreemptive.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache non Preemptive
 * \extends     Tache_Unitaire
 * \details     Une tâche Unitaire Preemptive est un évènement qui doit être réalisé durant un interval de dates donné.
 *              Elle peut être programmée en plusieurs parties.
 */
class TachePreemptive : public Tache_Unitaire
{
    TachePreemptive(const TachePreemptive&);
    TachePreemptive& operator=(const TachePreemptive&);
public:
    TachePreemptive(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur):
        Tache_Unitaire(id,titre,dispo,deadline,dur)
    {}
    inline virtual void afficher()const override { std::cout << "Je suis une tâche préemptive\n";}
};

#endif // TACHEPREEMPTIVE_H
