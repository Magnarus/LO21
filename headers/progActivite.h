#ifndef PROGACTIVITE_H
#define PROGACTIVITE_H
#include "programmation.h"
#include "activite.h"
class ProgActivite : public Programmation
{
    Activite* programme;
public:
    ProgActivite(const int id, const QDate& d, const QTime& dur, Activite* p):Programmation(id,d,dur),programme(p){}
    const inline Activite* getProgramme(){return programme;}
    inline void setProgramme(Activite* t){programme = t;}
    inline void afficher(){ std::cout << "Je suis une programmation d'activité \n";}
};
#endif // PROGACTIVITE_H
