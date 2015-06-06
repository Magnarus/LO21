#ifndef PROGACTIVITE_H
#define PROGACTIVITE_H
#include "programmation.h"
#include "activite.h"
/**
 * \class       ProgActivite progactivite.h "headers/progactivite.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ProgActivite
 * \extends     Programmation
 */
class ProgActivite : public Programmation
{
    Activite* programme;
    ProgActivite(const ProgActivite&);
    ProgActivite& operator=(const ProgActivite&);
public:
    ProgActivite(const int id, const QDate& d, const QTime& dur, Activite* p) throw(AgendaException);
    inline const Activite* getProgramme()const{return programme;}
    void setDate(QDate& d)throw(AgendaException) override;
    void setDuree(QTime &d)throw(AgendaException) override;
    inline void setProgramme(Activite* t){programme = t;}
    inline void afficher(){ std::cout << "Je suis une programmation d'activité \n";}
};
#endif // PROGACTIVITE_H
