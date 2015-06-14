#ifndef ACTIVITEMANAGER
#define ACTIVITEMANAGER
#include "tmanager.h"
#include "ajouteuractivite.h"

#include<iostream>
/**
 * \class       ActiviteManager activitemanager.h "headers/activitemanager.h"
 * \author      NEVEUX Anaïs et DELAUNAY Gregory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ActiviteManager
 * \extends     TManager<Activite*>
 * \details     Cette classe définit le manager d'activités
 *              Les Manager sont des singletons qui gèrent le cycle de vie et l'accès au type associé.
 */
class ActiviteManager : public TManager<Activite*>
{
    /**
     * \brief ActiviteManager constructeur par recopie privé
     * Comme la classe est un singleton, le constructeur par recopie est privé
     */
    ActiviteManager(const ActiviteManager&);
    /**
     * \brief operator =
     * Opérateur = privé
     * \return
     */
    ActiviteManager& operator=(const ActiviteManager&);
    /**
     * \brief ActiviteManager
     * Constructeur privé
     */
    ActiviteManager();
protected:
public:
    /**
     * \brief afficher service redéfinie
     */
    virtual void afficher()const {std::cout << "Je suis un manager d'activité\n";}
    /**
     * \brief getInstance
     * \return le manager d'activité
     */
    static TManager<Activite *> *getInstance();
};

#endif // ACTIVITEMANAGER

