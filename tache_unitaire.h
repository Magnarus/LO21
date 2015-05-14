#ifndef TACHE_UNITAIRE_H
#define TACHE_UNITAIRE_H
#include"tache.h"
#include<QTime>
class Tache_Unitaire : public Tache
{
    static const QTime* MAXNONPREEMPTIVE;
    bool estPreemptive;
public:
    Tache_Unitaire(const QString& id, const QDate&
                   dispo, const QDate& deadline, const QTime& dur,bool preemptive):
        Tache(id,dispo,deadline,dur),estPreemptive(preemptive)
    {}
    virtual void afficher(){}

};

#endif // TACHE_UNITAIRE_H
