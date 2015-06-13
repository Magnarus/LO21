#ifndef ACTIVITEMANAGER
#define ACTIVITEMANAGER
#include "tmanager.h"
#include "ajouteuractivite.h"

#include<iostream>
/**
 * \class       ActiviteManager activitemanager.h "headers/activitemanager.h"
 * \author      NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ActiviteManager
 * \extends     TManager<Activite*>
 * \details     Cette classe définit le manager de programmation
 *              Les Manager sont des singletons qui gèrent le cycle de vie et l'accès au type associé.
 */
class ActiviteManager : public TManager<Activite*>
{
    ActiviteManager(const ActiviteManager&);
    ActiviteManager& operator=(const ActiviteManager&);
    ActiviteManager();
protected:
public:
    virtual void afficher()const {std::cout << "Je suis un manager d'activité\n";}
    static TManager<Activite *> *getInstance();
};

#endif // ACTIVITEMANAGER

