#ifndef TACHENONPREEMPTIVE_H
#define TACHENONPREEMPTIVE_H
#include "tache_unitaire.h"

class TacheNonPreemptive : public Tache_Unitaire
{
    static const QTime* MAXNONPREEMPTIVE;
    TacheNonPreemptive(const TacheNonPreemptive&);
    TacheNonPreemptive& operator=(const TacheNonPreemptive&);
public:
    TacheNonPreemptive(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur):
        Tache_Unitaire(id,titre,dispo,deadline,dur)
    {
        if(dur.hour()> MAXNONPREEMPTIVE->hour());
        //Throw Exception("Une tâche non préemptive ne peut pas durer plus de 12h")
    }
    inline virtual void afficher()const override { std::cout << "Je suis une tâche non préemptive\n";}
};

#endif // TACHENONPREEMPTIVE_H
