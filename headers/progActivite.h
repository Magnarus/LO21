#ifndef PROGACTIVITE_H
#define PROGACTIVITE_H
#include "programmation.h"
#include "activite.h"
class ProgActivite : public Programmation
{
    Activite* programme;
public:
    const inline Activite* getProgramme(){return programme;}
    inline void setProgramme(Activite* t){programme = t;}
    inline void afficher(){ std::cout << "Je suis une programmation d'activité \n";}
};
#endif // PROGACTIVITE_H
