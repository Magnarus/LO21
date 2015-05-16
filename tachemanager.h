#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H
#include "tmanager.h"
#include "ajouteurtache.h"
#include<iostream>
class TacheManager : public TManager<Tache,AjouteurTache>
{
public:
    TacheManager();
    virtual void afficher()const {std::cout << "Je suis un manager de tâches\n";}
};

#endif // TACHEMANAGER_H
