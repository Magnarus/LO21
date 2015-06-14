#ifndef PROJET_H
#define PROJET_H
#include<QDate>
#include<QString>
#include<QList>
#include"tache.h"
#include"tache_composite.h"
#include "agendaexception.h"
/**
 * \class       Projet projet.h "headers/projet.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Projet
 * \details     Le projet est un ensemble de tâches qui doivent être commencé à partir d'une date
 *              et terminés avant une autre
 */
class Projet
{
    int id; /** id du projet*/
    QDate dateDispo; /** date de disponibilité du projet */
    QDate dateEcheance; /** date d'échéance du projet */
    QString titre; /** titre du projet */
    QList<Tache*> taches; /** tâches associées au projet */

    /**
     * \brief Projet
     * constructeur par recopie interdit
     */
    Projet(const Projet&);

    /**
     * \brief operator =
     * copie par opérateur interdit
     * \return la copie du projet passé en paramètre
     */
    Projet& operator=(const Projet&);
public:
    /**
     * \brief Projet
     * constructeur
     * \param id
     * id du projet
     * \param t
     * titre du projet
     * \param dispo
     * date de disponibilité du projet
     * \param echeance
     * date d'échéance du projet
     */
    Projet(int id,QString& t, QDate& dispo, QDate& echeance);

    ~Projet();
    /**
     * \brief getId
     * accesseur sur l'id du projet
     * \return l'id du projet
     */
    inline const int getId()const {return id;}
    /**
     * \brief getDateDispo
     * accesseur sur la datedispo du projet
     * \return la date de disponibilité du projet
     */
    inline const QDate& getDateDispo()const{return dateDispo;}

    /**
     * \brief getDateEcheance
     * accesseur sur la date d'échéance du projet
     * \return la date d'échéance du projet
     */
    inline const QDate& getDateEcheance()const{return dateEcheance;}

    /**
     * \brief getTitre
     * accesseur sur le titre du projet
     * \return le titre du projet
     */
    inline const QString& getTitre()const{return titre;}

    /**
     * \brief setTitre
     * mutateur sur le titre du projet
     * \param t
     * le nouveau titre
     */
    inline void setTitre(QString& t){titre=t;}

    /**
     * \brief setDateDispo
     * mutateur sur la date de disponibilité du projet
     * \param d
     * la nouvelle date
     */
    void setDateDispo(QDate& d)throw(AgendaException);

    /**
     * \brief setDateEcheance
     * mutateur sur la date d'échéance du projet
     * \param d
     * la nouvelle echeance
     */
    void setDateEcheance(QDate& d)throw(AgendaException);

    /**
     * \brief getNbTaches
     * \return le nombre de tâches associées au projet
     */
    inline const int getNbTaches()const{return taches.size();}

    /**
     * \brief getTache
     * accesseur sur une tâche d'id connu
     * \param id
     * l'id de la tâche à récupérer
     * \return la tâche associée à l'id, null si elle n'existe pas.
     */
    Tache* getTache(int id);

    /**
     * \brief getTacheParCompteur
     * accesseur sur la tâche i
     * \param i
     * la position de la tâche à récupérer
     * \return la tâche i
     */
    inline Tache* getTacheParCompteur(int i){return taches[i];}

    /**
     * \brief aTache
     * vérifie si la tâche d'id passé est liée au projet
     * \param id
     * l'id de la tâche à chercher
     * \return vrai si oui, faux sinon
     */
    bool aTache(int id);
    /**
     * \brief estTacheRec
     * vérifie si la tâche est récursive
     * \param id
     * id de la tâche
     * \return vrai si oui, faux sinon
     */
    bool estTacheRec(int id);

    /**
     * \brief ajouterTache
     * ajoute la tâche passée en paramètre au projet
     * \param t
     * la tâche à ajouter
     */
    void ajouterTache(Tache* t)throw(AgendaException);

    /**
     * \brief supprSiDedans
     * supprime la tâche d'id passé si elle est liée au projet
     * \param id
     * id de la tâche à supprimer
     * \return vrai si supprimée, faux sinon
     */
    bool supprSiDedans(int id);

    /**
     * \class       Iterator projet.h "headers/projet.h"
     * \author      DELAUNAY Grégory
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe Iterator
     * \details     permet de parcourir l'ensemble des tâches liées à un projet
     */
    class Iterator
    {
        QList<Tache*>::iterator itCour; /** itérateur sur la tâche courante */
    public:
        /**
         * \brief Iterator
         * constructeur
         * \param i
         * début de l'itération
         */
        Iterator(QList<Tache*>::iterator i){itCour = i;}

        /**
         * \brief valeur
         * tache associée à l'itérateur courant
         * \return la tâche associée
         */
        Tache* valeur(){return *itCour;}

        /**
         * \brief courant
         * \return l'itérateur courant
         */
        QList<Tache*>::iterator& courant(){return itCour;}
        /**
         * \brief next
         * passe à la valeur suivante
         */
        void next(){++itCour;}
    };
    /**
     * \brief getIterator
     * construit un iterateur et le retourne
     * \return itérateur
     */
    Iterator getIterator(){return Iterator(taches.begin());}

    /**
     * \brief end
     * la fin d'itération
     * \return itérateur sur la fin d'itération
     */
    QList<Tache*>::iterator end(){return taches.end();}

    /**
     * \class       IteratorDate projet.h "headers/projet.h"
     * \author      DELAUNAY Grégory
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe IteratorDate
     * \details     permet de parcourir l'ensemble des tâches liées à un projet sur un interval
     * de temps donné.
     */
    class IteratorDate
    {
        QList<Tache*>::iterator itCour; /** itérateur courant */
        QList<Tache*> result; /** liste des tâches correspondantes*/
    public:
        /**
         * \brief IteratorDate
         * constructeur
         * \param it
         * début de recherche
         * \param fin
         * fin de recherche
         * \param dispo
         * date de début
         * \param echeance
         * date de fin
         */
        IteratorDate(QList<Tache*>::iterator it,QList<Tache*>::iterator fin,
                     const QDate& dispo, const QDate& echeance)
        {
            for(it;it != fin;++it)
            {
                if((*it)->getDateDispo() >= dispo && (*it)->getEcheance() <= echeance)
                    result.push_back(*it);
            }
            itCour = result.begin();
        }

        /**
         * \brief valeur
         * \return la valeur courante
         */
        Tache* valeur(){return *itCour;}

        /**
         * \brief courant
         * \return l'itérateur courant
         */
        typename QList<Tache*>::iterator& courant(){return itCour;}

        /**
         * \brief next
         * passe au résultat suivant
         */
        void next(){++itCour;}

        /**
         * \brief end
         * \return la fin d'itération
         */
        QList<Tache*>::iterator end(){return result.end();}
    };

    /**
     * \brief getIteratorDate
     * \param d
     * date de début de recherche
     * \param f
     * date de fin de recherche
     * \return l'iterateur construit
     */
    IteratorDate getIteratorDate(const QDate& d, const QDate& f)
    {
        return IteratorDate(taches.begin(),taches.end(),d,f);
    }

    /**
     * \class       constIterator projet.h "headers/projet.h"
     * \author      NEVEUX Anaïs
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe constIterator
     * \details     permet de parcourir l'ensemble des tâches sans pouvoir les modifier
     */
    class constIterator
    {
        QList<Tache*>::const_iterator itCour; /** itérateur courant*/
    public:
        /**
         * \brief constIterator
         * constructeur
         * \param i
         * début de recherche
         */
        constIterator(QList<Tache*>::const_iterator i){itCour = i;}

        /**
         * \brief valeur
         * \return la valeur courante
         */
        const Tache* valeur(){return *itCour;}
        /**
         * \brief courant
         * \return iterateur courant
         */
        QList<Tache*>::const_iterator& courant(){return itCour;}
        /**
         * \brief next
         * passe à l'itérateur suivant
         */
        void next(){++itCour;}
    };
    /**
     * \brief getIterator
     * \return l'itérateur construit
     */
    constIterator getIterator()const{return constIterator(taches.begin());}

    /**
     * \brief end
     * \return le dernier itérateur
     */
    QList<Tache*>::const_iterator end()const{return taches.end();}
};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Projet*)
#endif // PROJET_H
