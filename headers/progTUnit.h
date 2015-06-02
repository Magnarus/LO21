#ifndef PROGTUNIT_H
#define PROGTUNIT_H
#include "programmation.h"
#include "tache_unitaire.h"
class ProgTUnit : public Programmation
{
    Tache_Unitaire* programme;
public:
    ProgTUnit(const int id, const QDate& d, const QTime& dur, Tache_Unitaire* p):Programmation(id,d,dur),programme(p){}
    const inline Tache_Unitaire* getProgramme(){return programme;}
    inline void setProgramme(Tache_Unitaire* t){programme = t;}
    inline void afficher(){ std::cout << "Je suis une programmation de tâche unitaire\n";}
};

#endif // PROGTUNIT_H
