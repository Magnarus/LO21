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
    class IteratorIntervale
    {
        QVector<Programmation*> resultats;
        QVector<Programmation*>::iterator itRes;
        QVector<Programmation*>::iterator research;
        QVector<Programmation*>::iterator finResearch;
        QDate debut;
        QDate fin;
    public:
        IteratorIntervale(const QDate& d,const QDate& f,
                          QVector<Programmation*>::iterator di,
                          QVector<Programmation*>::iterator fi):
            debut(d),fin(f),research(di),finResearch(fi)
        {
            while(research != finResearch)
            {
                if((*research)->getDate() >= debut && (*research)->getDate() <= fin)
                    resultats.push_back((*research));
                ++research;
            }
            itRes = resultats.begin();
        }
        Programmation* valeur(){return *itRes;}
        QVector<Programmation*>::iterator& courant(){return itRes;}
        void next() { ++itRes;}
        QVector<Programmation*>::iterator end(){return resultats.end();}
    };
    IteratorIntervale getIterator(const QDate& d,const QDate& f)
    {return IteratorIntervale(d,f,managable.begin(),managable.end());}

    static TManager<Programmation*> *getInstance();
};
#endif // PROGMANAGER_H
