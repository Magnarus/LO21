#ifndef PROGACTIVITE_H
#define PROGACTIVITE_H
#include "programmation.h"
#include "activite.h"
class ProgActivite : public Programmation
{
    Activite* programme;
    ProgActivite(const ProgActivite&);
    ProgActivite& operator=(const ProgActivite&);
public:
    ProgActivite(const int id, const QDate& d, const QTime& dur, Activite* p);
    inline const Activite* getProgramme()const{return programme;}
    void setDate(QDate& d)override;
    void setDuree(QTime &d)override;
    inline void setProgramme(Activite* t){programme = t;}
    inline void afficher(){ std::cout << "Je suis une programmation d'activité \n";}
};
#endif // PROGACTIVITE_H
