#ifndef TACHEPREEMPTIVE_H
#define TACHEPREEMPTIVE_H
#include "tache_unitaire.h"

class TachePreemptive : public Tache_Unitaire
{
public:
    TachePreemptive(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur):
        Tache_Unitaire(id,titre,dispo,deadline,dur)
    {}
    inline virtual void afficher()const override { std::cout << "Je suis une tâche préemptive\n";}
};

#endif // TACHEPREEMPTIVE_H
