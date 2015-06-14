#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H
#include "tmanager.h"
#include "ajouteurtache.h"
#include<QDebug>
#include<iostream>
/**
 * \class       TacheManager tachemanager.h "headers/tachemanager.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe TacheManager
 * \details     Cette classe définit le manager de tache
 *              Les Manager sont des singletons qui gèrent le cycle de vie et l'accès au type associé.
 */
class TacheManager : public TManager<Tache*>
{
    /**
     * \brief TacheManager
     * constructeur par recopie interdit
     */
    TacheManager(const TacheManager&);
    /**
     * \brief operator =
     * recopie par opérateur interdite
     * \return copie du paramètre passé
     */
    TacheManager& operator=(const TacheManager&);
    /**
     * \brief TacheManager
     * constructeur interdit, car singleton
     */
    TacheManager();
protected:
public:
    /**
     * \brief afficher
     * fonction de service
     */
    virtual void afficher()const {std::cout << "Je suis un manager de tâches\n";}

    /**
     * \brief getInstance
     * \return le manager de tâches
     */
    static TManager<Tache *> *getInstance();

    /**
     * \class       IteratorTypeT tachemanager.h "headers/tachemnager.h"
     * \author      DELAUNAY Grégory
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe IteratorTypeT
     * \details     permet de parcourir l'ensemble des tâches d'un type donné
     */
    class IteratorTypeT
    {
        QVector<Tache*> resultats; /** résultats */
        QVector<Tache*>::iterator itRes; /** itérateur sur les résultats */
        QVector<Tache*>::iterator research; /** itérateur de recherche */
        QVector<Tache*>::iterator finResearch; /** itérateur de fin de recherche */
        typeTache type; /** type à rechercher */
    public:
        /**
         * \brief IteratorTypeT
         * constructeur
         * \param t
         * type à rechercher
         * \param di
         * début de recherche
         * \param fi
         * fin de recherche
         */
        IteratorTypeT(typeTache t,
                          QVector<Tache*>::iterator di,
                          QVector<Tache*>::iterator fi):
            type(t),research(di),finResearch(fi)
        {
            while(research != finResearch)
            {
                if(type == UNITAIRE)
                {
                    if((*research)->getType() == type || (*research)->getType() == PREEMPTIVE || (*research)->getType() == NON_PREEMPTIVE)
                        resultats.push_back((*research));
                }
                else
                {
                    if((*research)->getType() == type)
                        resultats.push_back((*research));
                }
                ++research;
            }
            itRes = resultats.begin();
        }

        /**
         * \brief valeur
         * \return valeur de l'itérateur de résultat
         */
        Tache* valeur(){return *itRes;}

        /**
         * \brief courant
         * \return itérateur de résultat courant
         */
        QVector<Tache*>::iterator& courant(){return itRes;}

        /**
         * \brief next
         * Fais avancer l'itérateur de résultat
         */
        void next() { ++itRes;}

        /**
         * \brief fin
         * \return l'itérateur de fin des résultats
         */
        QVector<Tache*>::iterator fin(){return resultats.end();}
    };
    /**
     * \brief getIteratorTypeT
     * retourne l'itérateur construit
     * \param t
     * type de tâche à chercher
     * \return l'itérateur construit
     */
    IteratorTypeT getIteratorTypeT(const typeTache t)
    {return IteratorTypeT(t,managable.begin(),managable.end());}
};

#endif // TACHEMANAGER_H
