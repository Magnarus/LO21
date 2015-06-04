#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include "tmanager.h"
#include "ajouteurprojet.h"
#include<iostream>
class ProjetManager : public TManager<Projet*>
{
    ProjetManager(const ProjetManager&);
    ProjetManager& operator=(const ProjetManager&);
public:
    ProjetManager();
    virtual void afficher()const {std::cout << "Je suis un manager de projets\n";}
    static TManager<Projet *> *getInstance();
};

#endif // PROJETMANAGER_H
