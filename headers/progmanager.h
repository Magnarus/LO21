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
 * \details     Cette classe définit le manager de programmation
 *              Les Manager sont des singletons qui gèrent le cycle de vie et l'accès au type associé.
 */
class ProgManager : public TManager<Programmation*>
{
    /**
     * \brief ProgManager constructeur interdit
     */
    ProgManager(const ProgManager&);

    /**
     * \brief operator =
     * redéfinition d'opérateur interdite
     * \return le ProgManager créé
     */
    ProgManager& operator=(const ProgManager&);

    /**
     * \brief ProgManager
     * constructeur interdit, singleton
     */
    ProgManager();
public:
    /**
     * \brief afficher fonction de service redéfinie
     */
    virtual void afficher()const {std::cout << "Je suis un manager de tâches\n";}
    /**
     * \class       IteratorIntervale progmanager.h "headers/progmanager.h"
     * \author      DELAUNAY Grégory
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe IteratorIntervale
     * \details     Cette classe définit un iterateur d'interval
     *              il sert à récupérer toutes les programmations faites sur un interval donné
     */
    class IteratorIntervale
    {
        QVector<Programmation*> resultats; /** les programmations correspondantes*/
        QVector<Programmation*>::iterator itRes; /** l'itérateur sur les résultats*/
        QVector<Programmation*>::iterator research; /** l'itérateur sur les prog du progmanager */
        QVector<Programmation*>::iterator finResearch; /** l'itérateur limite sur les prog du progmanager */
        QDate debut; /** début de l'interval */
        QDate fin; /** fin de l'interval */
    public:
        /**
         * \brief IteratorIntervale constructeur
         * \param d date de début
         * \param f date de fin
         * \param di itérator sur le début de la recherche
         * \param fi itérator sur la fin de la recherche
         */
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
        /**
         * \brief valeur retourne le résultat en cours
         * \return
         */
        Programmation* valeur(){return *itRes;}

        /**
         * \brief courant
         * \return l'itérateur de résultat courant
         */
        QVector<Programmation*>::iterator& courant(){return itRes;}

        /**
         * \brief next
         * passe au résultat suivant
         */
        void next() { ++itRes;}
        /**
         * \brief end
         * \return un itérateur sur la fin des résultats
         */
        QVector<Programmation*>::iterator end(){return resultats.end();}
    };
    /**
     * \brief getIteratorIntervale
     * construit un itérateur sur un interval
     * \param d date de début d'interval
     * \param f date de fin d'intérval
     * \return l'itérateur construit
     */
    IteratorIntervale getIteratorIntervale(const QDate& d,const QDate& f)
    {return IteratorIntervale(d,f,managable.begin(),managable.end());}

    /**
     * \brief getInstance
     * \return le manager de programmation
     */
    static TManager<Programmation*> *getInstance();
};
#endif // PROGMANAGER_H
