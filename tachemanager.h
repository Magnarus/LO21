#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H
#include "tmanager.h"
#include "ajouteurtache.h"
#include<iostream>
class TacheManager : public TManager<Tache*,Ajouteur<Tache*>*>
{
public:
    TacheManager();
    virtual void afficher()const {std::cout << "Je suis un manager de tâches\n";}
    static TManager<Tache *, Ajouteur<Tache*> *> *getInstance();
};

#endif // TACHEMANAGER_H
