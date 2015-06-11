#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include "tmanager.h"
#include "ajouteurprojet.h"
#include<iostream>
/**
 * \class       ProjetManager ProjetManager.h "headers/projetmanager.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ProjetManager
 * \extends     TManager<Programmation*>
 * \details     Cette classe définit le manager de programmation
 *              Les Manager sont des singletons qui gèrent le cycle de vie et l'accès au type associé.
 */
class ProjetManager : public TManager<Projet*>
{
    ProjetManager(const ProjetManager&);
    ProjetManager& operator=(const ProjetManager&);
    ProjetManager();
protected:
public:
    virtual void afficher()const {std::cout << "Je suis un manager de projets\n";}
    static TManager<Projet *> *getInstance();
    Projet* getProjetTache(int id);
};

#endif // PROJETMANAGER_H
