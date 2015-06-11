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
 * \extends     TManager<Tache*>
 * \details     Cette classe définit le manager de tache
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
    class IteratorTypeT
    {
        QVector<Tache*> resultats;
        QVector<Tache*>::iterator itRes;
        QVector<Tache*>::iterator research;
        QVector<Tache*>::iterator finResearch;
        typeTache type;
    public:
        IteratorTypeT(typeTache t,
                          QVector<Tache*>::iterator di,
                          QVector<Tache*>::iterator fi):
            type(t),research(di),finResearch(fi)
        {
            while(research != finResearch)
            {
                if((*research)->getType() == type)
                    resultats.push_back((*research));
                ++research;
            }
            itRes = resultats.begin();
        }
        Tache* valeur(){return *itRes;}
        QVector<Tache*>::iterator& courant(){return itRes;}
        void next() { ++itRes;}
        QVector<Tache*>::iterator fin(){return resultats.end();}
    };

    IteratorTypeT getIteratorTypeT(const typeTache t)
    {return IteratorTypeT(t,managable.begin(),managable.end());}
};

#endif // TACHEMANAGER_H
