#ifndef PROGACTIVITE_H
#define PROGACTIVITE_H
#include "programmation.h"
#include "activite.h"
#include "activitemanager.h"
/**
 * \class       ProgActivite progactivite.h "headers/progactivite.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ProgActivite
 * \details     Cette classe est la représentation d'une programmation sur une activité.
 */
class ProgActivite : public Programmation
{
    Activite* programme; /** l'activité programmée */

    /**
     * \brief ProgActivite
     *
     * constructeur interdit
     */
    ProgActivite(const ProgActivite&);

    /**
     * \brief operator =
     *
     * opérateur interdit
     * \return  référence sur une activité
     */
    ProgActivite& operator=(const ProgActivite&);
public:
    virtual ~ProgActivite();
    /**
     * \brief ProgActivite constructeur
     * \param id
     * id de la programmation
     * \param d
     * date de la programmation
     * \param dur
     * durée de la programmation
     * \param h
     * horaire de début de la programmation
     * \param p
     * activité programmée
     */
    ProgActivite(const int id, const QDate& d, const QTime& dur, const QTime& h, Activite* p) throw(AgendaException);

    /**
     * \brief getProgramme
     * \return \e Activite* l'activité programmée
     */
    inline const Activite* getProgramme()const{return programme;}

    /**
     * \brief setDate change la date de la programmation si possible
     * \param d la nouvelle date
     */
    void setDate(const QDate& d)throw(AgendaException) override;

    /**
     * \brief setDuree change la durée de la programmation si possible
     * \param d la nouvelle durée
     */
    void setDuree(const QTime &d)throw(AgendaException) override;

    /**
     * \brief setProgramme change l'activité programmée
     * \param t la nouvelle activité
     */
    inline void setProgramme(Activite* t){programme = t;}

    /**
     * \brief afficher fonction de service à implémenter car présente dans classe abstraite mère
     */
    inline void afficher(){ std::cout << "Je suis une programmation d'activité \n";}
};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(ProgActivite*)
#endif // PROGACTIVITE_H

