#ifndef PROGTUNIT_H
#define PROGTUNIT_H
#include "programmation.h"
#include "tache_unitaire.h"
/**
 * \class       ProgTUnit progtunit.h "headers/progtunit.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ProgTUnit
 * \extends     Programmation
 */
class ProgTUnit : public Programmation
{
    Tache_Unitaire* programme;
    ProgTUnit(const ProgTUnit&);
    ProgTUnit& operator=(const ProgTUnit&);
public:
    ProgTUnit(const int id, const QDate& d, const QTime& dur, Tache_Unitaire* p)throw(AgendaException);
    void setDate(QDate &d) throw(AgendaException) override;
    void setDuree(QTime &d)throw(AgendaException) override;
    const inline Tache_Unitaire* getProgramme()const {return programme;}
    inline void setProgramme(Tache_Unitaire* t){programme = t;}
    inline void afficher(){ std::cout << "Je suis une programmation de tâche unitaire\n";}
};

#endif // PROGTUNIT_H
