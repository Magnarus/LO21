#ifndef TMANAGER_H
#define TMANAGER_H
#include<QVector>
#include<QString>
#include<QVariant>
#include<QMap>
#include<QSet>
#include<QDate>
#include "agendaexception.h"
//Interdépendance => Forward declaration !
template<typename U>
class Ajouteur;
template<typename T>
/**
 * \class       TManager tmanager.h "headers/tmanager.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe manager
 *
 * \details     Cette classe définit les manager génériques
 *              Les manager sont des objets singleton qui servent à gerer le cycle et l'utilisation des types associés.
 */
class TManager
{

protected:
    QVector<T> managable; /** L'ensemble des objets du Manager*/
    QMap<QString, Ajouteur<T>*> ajouteurs; /** objets permettant de construire les objets stockés dans le manager */
    QSet<QString> cles; /** types d'ajouteurs autorisés */
    int idDispo; /** prochain id disponible pour construction */

    /**
     * \brief addItem
     * ajoute un item
     * \param i
     * objet à ajouter
     */
    const void addItem(T i){managable.push_back(i); idDispo++;}

    /**
     * \brief TManager
     * constructeur de recopie interdit
     * \param t
     */
    TManager(TManager* t);

    /**
     * \brief operator =
     * recopie par opérateur interdite
     * \param t
     * \return
     */
    TManager& operator=(TManager* t);
    TManager(size_t capacity=0):idDispo(1)
    {
        if(capacity > 0) managable.reserve(capacity);
    }
    TManager(const TManager&);
    TManager& operator=(const TManager&);
    /**
     * \struct      HandlerTM tmanager.h "headers/tmanager.h"
     * \author      DELAUNAY Grégory
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente l'handler
     *
     * \details     cette structure permet de faire en sorte que les manager soient des singletons
     */
    struct HandlerTM{
            TManager<T>* instance; /** l'instance singleton*/
            /**
             * \brief HandlerTM
             * constructeur
             */
            HandlerTM():instance(0){}
            // destructeur appelé à la fin du programme
            ~HandlerTM(){ if (instance) delete instance; }
    };
    static HandlerTM handler; /** instance de l'handler */

public:
    /**
     * \brief getItem
     * accesseur sur l'item stocké
     * \param id
     * id de l'item à récupérer
     * \return référence sur l'item
     */
    T& getItem(const int id)
    {
        typename QVector<T>::iterator it = managable.begin();
        while(it!=managable.end() && id!=(*it)->getId())
            ++it;
        return *it;
    }

    /**
     * \brief getItem
     * accesseur sur l'item stocké
     * \param id
     * id de l'item à récupérer
     * \return référence constante sur l'item
     */
    const T& getItem(const int id) const
    {
            typename QVector<T>::const_iterator it = managable.cbegin();
            while(it!=managable.cend() && id!=(*it)->getTitre())
                ++it;
            return *it;
    }
    /**
     * \brief getDernierItem
     * \return le dernier item ajouté
     */
    T getDernierItem()const {return managable.last();}

    /**
     * \brief afficher
     * fonction de service pour générer l'abstraction
     */
    virtual void afficher()const = 0;

    /**
     * \brief libererInstance
     */
    static void libererInstance();

    /**
     * \brief getIdDispo
     * \return l'id disponible
     */
    const int getIdDispo()const {return idDispo;}
    /**
     * \brief nbItem
     * \return le nombre d'item stocké
     */
    inline int nbItem()const {return managable.size();}

    /**
     * \brief nbAjouteurs
     * \return le nombre d'ajouteurs
     */
    inline int nbAjouteurs()const {return ajouteurs.size();}

    /**
     * \brief ajouterItem
     * ajoute un item
     * \param AjouteurType
     * type d'ajouteur à utiliser
     * \param params
     * liste des paramètres
     * \return l'id du nouvel item
     */
    inline int ajouterItem(const QString& AjouteurType, QMap<QString,QVariant>& params)
    {
        if(cles.find(AjouteurType) == cles.end()) throw AgendaException("Impossible d'utiliser cet ajouteur : il n'existe pas");
        params["id"] = idDispo;
        this->addItem(ajouteurs[AjouteurType]->construire(params));
        return idDispo-1;
    }

    /**
     * \brief ajouterAjouteur
     * ajoute un ajouteur
     * \param ajouteurType
     * type du nouvel ajouteur
     * \param a
     * ajouteur à ajouter
     */
    inline void ajouterAjouteur(const QString ajouteurType, Ajouteur<T>* a)
    {
        ajouteurs[ajouteurType] = a;
        cles.insert(ajouteurType);
    }

    /**
     * \brief supprimerItem
     * supprime l'item d'id passé
     * \param id
     * id de l'item à supprimer
     * \return vrai si réussi, faux sinon
     */
    inline bool supprimerItem(int id)
    {
        typename QVector<T>::iterator it = managable.begin();
        while(it!=managable.end() && id!=(*it)->getId())
            ++it;
        if(it == managable.end())
            return false;
        else
        {
            delete (*it);
            managable.erase(it);
        }
        return true;
    }

    /**
     * \class       Iterator tmanager.h "headers/tmanager.h"
     * \author      DELAUNAY Grégory et NEVEUX Anaïs
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe Iterator
     * \details     permet de parcourir l'ensemble des tâches liées à un projet
     */
    class Iterator
    {
        typename QVector<T>::iterator itCour; /** itérateur courant */
    public:
        /**
         * \brief Iterator
         * constructeur
         * \param i
         * début d'itération
         */
        Iterator(typename QVector<T>::iterator i){itCour = i;}

        /**
         * \brief valeur
         * \return valeur de l'itérateur
         */
        T valeur(){return *itCour;}

        /**
         * \brief courant
         * \return l'itérateur
         */
        typename QVector<T>::iterator& courant(){return itCour;}

        /**
         * \brief next
         * fais avancer l'itérateur
         */
        void next(){++itCour;}
    };

    /**
     * \brief getIterator
     * \return l'itérateur construit
     */
    Iterator getIterator(){return Iterator(managable.begin());}

    /**
     * \brief end
     * \return l'itérateur de fin
     */
    typename QVector<T>::iterator end(){return managable.end();}

    /**
     * \class       IteratorDate tmanager.h "headers/tmanager.h"
     * \author      DELAUNAY Grégory
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe IteratorDate
     * \details     permet de parcourir l'ensemble des tâches liées à un tmanager sur un interval
     * de temps donné.
     */
    class IteratorDate
    {
        QVector<T> resultats; /** resultats */
        typename QVector<T>::iterator itRes; /** itérateur sur les résultats */
        QDate dispo; /** date de début */
        QDate echeance; /** date de fin */
    public:
        /**
         * \brief IteratorDate
         * constructeur
         * \param d
         * date de début
         * \param e
         * date de fin
         */
        IteratorDate(QDate& d, QDate& e = QDate()):dispo(d),echeance(e)
        {
           typename QVector<T>::iterator it = managable.begin();
            //S'il n'y a pas d'échéance mais une date simple
            if(echeance.isNull())
            {
                while(it != managable.end())
                {
                    if((*it)->getDate() == dispo)
                        resultats.push_back((*it));
                    ++it;
                }
            }
            else // Il y a bien une dispo et une echeance
            {
                while(it!= managable.end())
                {
                    if((*it)->getDateDispo() >= dispo && (*it)->getEcheance() <= echeance)
                        resultats.push_back((*it));
                    ++it;
                }
            }
            itRes = resultats.begin();
        }
    public:
        /**
         * \brief valeur
         * \return la valeur de l'itérateur
         */
        T valeur(){return *itRes;}

        /**
         * \brief courant
         * \return l'itérateur courant
         */
        typename QVector<T>::iterator& courant(){return itRes;}

        /**
         * \brief end
         * \return l'itérateur de fin
         */
        typename QVector<T>::iterator& end(){return resultats.end();}

        /**
         * \brief next
         * Fais avancer l'itérateur
         */
        void next() { ++itRes;}
    };

    /**
     * \brief getIteratorDate
     * \param d
     * date de début
     * \param e
     * date de fin
     * \return l'itérateur construit
     */
    IteratorDate getIteratorDate(QDate& d, QDate &e = QDate()){return IteratorDate(d,e);}
};

//Initialisation du Handler Statique
template<typename T>
typename TManager<T>::HandlerTM TManager<T>::handler=TManager<T>::HandlerTM();

template<typename T>
void TManager<T>::libererInstance(){
    if (handler.instance!=0) delete handler.instance;
    handler.instance=0;
}
/*#include "tmanager.tpl"*/ ///On verra plus tard.
#endif // TMANAGER_H
