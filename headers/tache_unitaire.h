#ifndef TACHE_UNITAIRE_H
#define TACHE_UNITAIRE_H
#include"tache.h"
#include<QTime>
class Tache_Unitaire : public Tache
{
    static const QTime* MAXNONPREEMPTIVE;
    bool estPreemptive;
public:
    Tache_Unitaire(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur,bool preemptive):
        Tache(id,titre,dispo,deadline,dur),estPreemptive(preemptive)
    {}
    inline bool preemptive()const {return estPreemptive;}
    inline void setPreemptive(bool p){estPreemptive = p;}
    inline virtual void afficher()const override {std::cout << "je suis une tâche unitaire\n";}

};

#endif // TACHE_UNITAIRE_H
