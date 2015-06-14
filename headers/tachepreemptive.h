#ifndef TACHEPREEMPTIVE_H
#define TACHEPREEMPTIVE_H
#include "tache_unitaire.h"
/**
 * \class       TachePreemptive tachepreemptive.h "headers/tachenonpreemptive.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache non Preemptive
 * \details     Une tâche Unitaire Preemptive est un évènement qui doit être réalisé durant un interval de dates donné.
 *              Elle peut être programmée en plusieurs parties.
 */
class TachePreemptive : public Tache_Unitaire
{
    /**
     * \brief TachePreemptive
     * constructeur par recopie interdit
     */
    TachePreemptive(const TachePreemptive&);
    /**
     * \brief operator =
     * recopie par opérateur interdite
     * \return copie du paramètre passé
     */
    TachePreemptive& operator=(const TachePreemptive&);
public:
    /**
     * \brief TachePreemptive
     * constructeur
     * \param id
     * id de la tâche
     * \param titre
     * titre de la tâche
     * \param dispo
     * date de dispo de la tâche
     * \param deadline
     * date d'échéance de la tâche
     * \param dur
     * durée de la tâche
     */
    TachePreemptive(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur):
        Tache_Unitaire(id,titre,dispo,deadline,dur)
    {
        setType(PREEMPTIVE);
    }

    /**
     * \brief afficher
     * fonction de service
     */
    inline virtual void afficher()const override { std::cout << "Je suis une tâche préemptive\n";}
};

#endif // TACHEPREEMPTIVE_H
