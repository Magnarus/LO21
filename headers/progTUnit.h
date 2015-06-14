#ifndef PROGTUNIT_H
#define PROGTUNIT_H
#include "programmation.h"
#include "tache_unitaire.h"
#include "tachemanager.h"
/**
 * \class       ProgTUnit progtunit.h "headers/progtunit.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ProgTUnit
 * \details     Cette classe est la représentation d'une programmation
 * portant sur une tâche unitaire.
 */
class ProgTUnit : public Programmation
{
    Tache_Unitaire* programme; /** la tache programmée */
    /**
     * \brief ProgTUnit
     * constructeur par recopie interdit
     */
    ProgTUnit(const ProgTUnit&);
    /**
     * \brief operator =
     * recopie via opérateur interdit
     * \return la copie de ProgTUnit
     */
    ProgTUnit& operator=(const ProgTUnit&);
public:
    ~ProgTUnit();
    /**
     * \brief ProgTUnit
     * constructeur
     * \param id id de la programmation
     * \param d date de la programmation
     * \param dur durée de la programmation
     * \param h horaire de la programmation
     * \param p tache unitaire programmée
     */
    ProgTUnit(const int id, const QDate& d, const QTime& dur,const QTime& h, Tache_Unitaire* p)throw(AgendaException);

    /**
     * \brief setDate
     * mutateur sur la date
     * \param d nouvelle date
     */
    void setDate(const QDate &d) throw(AgendaException) override;

    /**
     * \brief setDuree
     * mutateur sur la durée
     * \param d nouvelle durée
     */
    void setDuree(const QTime &d)throw(AgendaException) override;

    /**
     * \brief estProg
     * vérifie si la tache passée est la tache programmée
     * \return vrai si oui, faux sinon
     */
    bool estProg(const Tache_Unitaire*);

    /**
     * \brief getProgramme
     * accesseur sur la tâche unitaire programmée
     * \return la tâche unitaire programmée
     */
    const inline Tache_Unitaire* getProgramme()const {return programme;}

    /**
     * \brief setProgramme
     * mutateur sur la tache programmée
     * \param t la nouvelle tâche
     */
    inline void setProgramme(Tache_Unitaire* t){programme = t;}

    /**
     * \brief afficher
     * fonction de service
     */
    inline void afficher(){ std::cout << "Je suis une programmation de tâche unitaire\n";}
};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(ProgTUnit*)

#endif // PROGTUNIT_H
