#ifndef TACHENONPREEMPTIVE_H
#define TACHENONPREEMPTIVE_H
#include "tache_unitaire.h"
/**
 * \class       TacheNonPreemptive tachenonpreemptive.h "headers/tachenonpreemptive.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache non Preemptive
 * \details     Une tâche Unitaire non Preemptive est un évènement qui doit être réalisé durant un interval de dates donné.
 *              Elle doit être programmée du début à la fin et ne peut pas durer plus de 12h
 */
class TacheNonPreemptive : public Tache_Unitaire
{

    static const QTime* MAXNONPREEMPTIVE; /** durée max d'une tâche non préemptive */

    /**
     * \brief TacheNonPreemptive
     * constructeur par recopie interdit
     */
    TacheNonPreemptive(const TacheNonPreemptive&);
    /**
     * \brief operator =
     * recopie par opérateur interdite
     * \return
     */
    TacheNonPreemptive& operator=(const TacheNonPreemptive&);
public:
    /**
     * \brief TacheNonPreemptive
     * constructeur
     * \param id
     * id de la tâche
     * \param titre
     * titre de la tâche
     * \param dispo
     * disponibilité de la tâche
     * \param deadline
     * échéance de la tâche
     * \param dur
     * durée de la tâche
     */
    TacheNonPreemptive(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur)throw(AgendaException):
        Tache_Unitaire(id,titre,dispo,deadline,dur)
    {
        if((dur.hour()> MAXNONPREEMPTIVE->hour()) || (dur.hour() == MAXNONPREEMPTIVE->hour() && dur.minute() >0))
            throw AgendaException("Une tâche non préemptive ne peut pas durer plus de 12h");
        setType(NON_PREEMPTIVE);
    }

    /**
     * \brief afficher
     * fonction de service
     */
    inline virtual void afficher()const override { std::cout << "Je suis une tâche non préemptive\n";}
    /**
     * \brief setDuree
     * mutateur sur la durée
     * \param d
     * nouvelle durée
     */
    void setDuree(QTime& d)throw(AgendaException)
    { if(d.hour()> MAXNONPREEMPTIVE->hour())throw AgendaException("Une tâche non préemptive ne peut pas durer plus de 12h");}
};

#endif // TACHENONPREEMPTIVE_H
