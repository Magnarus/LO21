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
 * \details     Cette classe définit le manager de programmation
 *              Les Manager sont des singletons qui gèrent le cycle de vie et l'accès au type associé.
 */
class ProjetManager : public TManager<Projet*>
{
    /**
     * \brief ProjetManager
     * constructeur par recopie interdit
     */
    ProjetManager(const ProjetManager&);

    /**
     * \brief operator =
     * copie par opérateur interdite
     * \return
     */
    ProjetManager& operator=(const ProjetManager&);

    /**
     * \brief ProjetManager
     * constructeur interdit car singleton
     */
    ProjetManager();
protected:
public:
    /**
     * \brief afficher
     * fonction de service
     */
    virtual void afficher()const {std::cout << "Je suis un manager de projets\n";}

    /**
     * \brief getInstance
     * \return le manager de projet
     */
    static TManager<Projet *> *getInstance();

    /**
     * \brief getProjetTache
     * cherche le projet associée à la tâche passée en paramètre
     * \param id
     * id de la tâche
     * \return le projet si trouvé, null sinon
     */
    Projet* getProjetTache(int id);
};

#endif // PROJETMANAGER_H
