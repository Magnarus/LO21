#ifndef TACHE_COMPOSITE_H
#define TACHE_COMPOSITE_H
#include "tache.h"
/**
 * \class       Tache_Composite tache_composite.h "headers/tache_composite.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache_Composite
 * \details     Une tâche composite est un ensemble de tâche qui doit être réalisé dans un interval de dates données.
 */
class Tache_Composite : public Tache
{
    QList<Tache*> sousTaches; /** sous tâches */

    /**
     * \brief estSousTache
     * vérifie si la tâche d'id passé est sous tâche
     * \param id
     * id de la tâche à tester
     * \return vrai si oui, faux sinon
     */
    bool estSousTache(int id);

    /**
     * \brief Tache_Composite
     * constructeur par recopie interdit
     */
    Tache_Composite(const Tache_Composite&);

    /**
     * \brief operator =
     * recopie par opérateur interdite
     * \return copie de la tâche passée
     */
    Tache_Composite& operator=(const Tache_Composite&);

public:
    /**
     * \brief Tache_Composite
     * constructeur
     * \param id
     * id de la tâche
     * \param titre
     * titre de la tâche
     * \param dispo
     * date dispo de la tâche
     * \param deadline
     * date d'échéance de la tâche
     * \param st
     * sous-tâches sil y en a
     */
    Tache_Composite(const int id, const QString& titre, const QDate&
                    dispo, const QDate& deadline, const QList<Tache*>& st = QList<Tache*>()):
        Tache(id,titre,dispo,deadline),sousTaches(st)
    {
        setType(COMPOSITE);
    }
    ~Tache_Composite();
    /**
     * \brief ajouterSousTache
     * ajoute une tâche en sous tâche si elle n'y est pas déjà et s'il n'y a pas d'inclusion mutuelle
     * \param st
     * la tâche à ajouter
     */
    void ajouterSousTache(Tache *st)throw(AgendaException);

    /**
     * \brief supprimerSousTache
     * supprime la sous tâche d'id passé
     * \param id
     * id de la tâche à supprimer
     * \return vrai si réussi, faux sinon
     */
    bool supprimerSousTache(int id);

    /**
     * \brief getNbSousTaches
     * \return le nombre de sous tâches
     */
    int getNbSousTaches()const{return sousTaches.size();}

    /**
     * \brief getSousTache
     * récupère la sous tâche d'indice i
     * \param i
     * l'indice
     * \return la tâche
     */
    inline Tache* getSousTache(int i){return sousTaches[i];}

    /**
     * \brief afficher
     * fonction de service
     */
    inline virtual void afficher()const override{std::cout << "Je suis une tâche composite\n";}



    /**
     * \class       Iterator tache_composite.h "headers/tache_composite.h"
     * \author      DELAUNAY Grégory et NEVEUX Anaïs
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe Iterator
     * \details     permet de parcourir l'ensemble des tâches liées à un projet
     */
    class Iterator
    {
        typename QList<Tache*>::iterator itCour; /** l'itérateur courant */
    public:
        /**
         * \brief Iterator
         * constructeur
         * \param i
         * début d'itération
         */
        Iterator(typename QList<Tache*>::iterator i){itCour = i;}

        /**
         * \brief valeur
         * \return valeur de l'itérateur courant
         */
        Tache* valeur(){return *itCour;}

        /**
         * \brief courant
         * \return l'itérateur courant
         */
        typename QList<Tache*>::iterator& courant(){return itCour;}

        /**
         * \brief next
         * avance l'itérateur d'une case
         */
        void next(){++itCour;}
    };
    /**
     * \brief getIterator
     * \return l'itérateur construit
     */
    Iterator getIterator(){return Iterator(sousTaches.begin());}

    /**
     * \brief end
     * \return l'itérateur de fin
     */
    QList<Tache*>::iterator end(){return sousTaches.end();}

    /**
     * \class       constIterator tache_composite.h "headers/tache_composite.h"
     * \author      NEVEUX Anaïs et DELAUNAY Gregory
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe constIterator
     * \details     permet de parcourir l'ensemble des tâches sans pouvoir les modifier
     */
    class constIterator
    {
        typename QList<Tache*>::const_iterator itCour; /** iterateur courant*/
    public:
        /**
         * \brief constIterator
         * constructeur
         * \param i
         * début d'itération
         */
        constIterator(typename QList<Tache*>::const_iterator i){itCour = i;}

        /**
         * \brief valeur
         * \return la valeur de l'itérateur courant
         */
        const Tache* valeur(){return *itCour;}

        /**
         * \brief courant
         * \return l'itérateur courant
         */
        typename QList<Tache*>::const_iterator& courant(){return itCour;}

        /**
         * \brief next
         * fais avancer l'itérateur courant
         */
        void next(){++itCour;}
    };
    /**
     * \brief getIterator
     * \return l'itérateur construit
     */
    constIterator getIterator()const{return constIterator(sousTaches.begin());}

    /**
     * \brief end
     * \return l'itérateur de fin
     */
    QList<Tache*>::const_iterator end()const{return sousTaches.end();}

    /**
     * \brief estSousTacheRec
     * vérifie la récursivité
     * \param id
     * \return vrai si oui, faux sinon
     */
    bool estSousTacheRec(unsigned int id)const;
};
// ... ainsi que le type pointeur vers Tache_Composite
Q_DECLARE_METATYPE(Tache_Composite*)
#endif // TACHE_COMPOSITE_H
