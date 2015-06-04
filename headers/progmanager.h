#ifndef PROGMANAGER_H
#define PROGMANAGER_H
#include "tmanager.h"
#include "ajouteurprogactivite.h"
#include "ajouteurprogtunit.h"
#include<iostream>
/**
 * \class       ProgManager progmanager.h "headers/progmanager.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ProgManager
 * \extends     TManager<Programmation*>
 * \details     Cette classe définit le manager de programmation
 *              Les Manager sont des singletons qui gèrent le cycle de vie et l'accès au type associé.
 */
class ProgManager : public TManager<Programmation*>
{
    ProgManager(const ProgManager&);
    ProgManager& operator=(const ProgManager&);
    ProgManager();
public:
    virtual void afficher()const {std::cout << "Je suis un manager de tâches\n";}
    static TManager<Programmation*> *getInstance();
};
#endif // PROGMANAGER_H
