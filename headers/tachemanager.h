#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H
#include "tmanager.h"
#include "ajouteurtache.h"
#include<iostream>
/**
 * \class       TacheManager tachemanager.h "headers/tachemanager.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe TacheManager
 * \extends     TManager<Tache*>
 * \details     Cette classe définit le manager de programmation
 *              Les Manager sont des singletons qui gèrent le cycle de vie et l'accès au type associé.
 */
class TacheManager : public TManager<Tache*>
{
    TacheManager(const TacheManager&);
    TacheManager& operator=(const TacheManager&);
    TacheManager();
protected:
public:
    virtual void afficher()const {std::cout << "Je suis un manager de tâches\n";}
    static TManager<Tache *> *getInstance();
};

#endif // TACHEMANAGER_H
