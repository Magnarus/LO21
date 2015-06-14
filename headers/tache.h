#ifndef TACHE_H
#define TACHE_H
#include<QString>
#include<QList>
#include<QDate>
#include<QTime>
#include<iostream>
#include<typeinfo>
#include "../headers/agendaexception.h"
#include "../headers/etats.h"
#include<QDebug>
/**
 * \class       Tache tache.h "headers/tache.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache
 * \details     Une tâche est un évènement qui doit être réalisé durant un interval de dates donné.
 */
class Projet;
class ProjetManager;
class Tache
{
protected:
    int id; /** id de la tâche */
    QString titre; /** titre de la tâche */
    QList<Tache*> precedence; /** liste des précédences de la tâche */
    QDate dateDispo; /** date de disponibilité de la tâche */
    QDate dateEcheance; /** date d'échéance de la tâche */
    Etats etat; /** etat de la tâche */
    typeTache typeT; /** type de tâche */

    /**
     * \brief Tache
     * constructeur par recopie interdit
     */
    Tache(const Tache&);
    /**
     * \brief operator =
     * recopie par opérateur interdit
     * \return la copie du paramètre passé
     */
    Tache& operator=(const Tache&);
public:
    /**
     * \brief Tache
     * constructeur par défaut
     */
    Tache();

    /**
     * \brief Tache
     * constructeur
     * \param id
     * id de la tâche
     * \param titre
     * titre de la tâche
     * \param dispo
     * date de disponibilité de la tâche
     * \param deadline
     * date d'échéance de la tâche
     */
    Tache(const int id, const QString& titre, const QDate&
          dispo, const QDate& deadline)
         :id(id),titre(titre),dateDispo(dispo),dateEcheance(deadline),typeT(TACHE)
    {    if(dispo > deadline)throw AgendaException("Une tache doit se finir après avoir commencé !");
    }

    /**
     * \brief getId
     * accesseur sur l'id
     * \return id
     */
    inline int getId()const { return id;}

    /**
     * \brief getTitre
     * accesseur sur le titre
     * \return titre
     */
    inline QString& getTitre() {return titre;}

    /**
     * \brief getTitre
     * accesseur sur le titre
     * \return titre constant
     */
    inline const QString& getTitre()const{return titre;}

    /**
     * \brief getDateDispo
     * accesseur sur la date dispo
     * \return date de disponibilité
     */
    inline const QDate& getDateDispo()const {return dateDispo;}

    /**
     * \brief getEcheance
     * accesseur sur la date d'échéance
     * \return date echeance
     */
    inline const QDate& getEcheance()const {return dateEcheance;}
    /**
     * \brief getEtat
     * accesseur sur l'état
     * \return etat
     */
    inline const Etats getEtat()const {return etat;}

    /**
     * \brief getRealTypeName
     * accesseur sur le type via fonction standart C++
     * \return type
     */
    inline const QString getRealTypeName()const { return QString(typeid(this).name());}
    /**
     * \brief getType
     * accesseur sur le type
     * \return type
     */
    inline const typeTache getType()const { return typeT;}

    /**
     * \brief getTypeToQString
     * accesseur sur le type en format chaine de caractère
     * \return nom du type
     */
    const QString getTypeToQString()const;

    /**
     * \brief setTitre
     * mutateur sur le titre
     * \param t nouveau titre
     */
    inline void setTitre(QString& t){titre=t;}

    /**
     * \brief setDateDispo
     * mutateur sur la date de disponibilité
     * \param d nouvelle date
     */
    void setDateDispo(QDate& d);

    /**
     * \brief setEcheance
     * mutateur sur la date d'échéance
     * \param d nouvelle date
     */
    void setEcheance(QDate& d);

    /**
     * \brief setEtat
     * mutateur sur l'état
     * \param e nouvel etat
     */
    inline void setEtat(Etats e){etat = e;}

    /**
     * \brief setType
     * mutateur sur le type
     * \param t nouveau type
     */
    inline void setType(typeTache t){typeT = t;}

    /**
     * \brief estPredecence
     * vérifie si la tâche d'id passé est précédence
     * \param id
     * id de la tâche testée
     * \return vrai si oui, faux sinon
     */
    bool estPredecence(int id);

    /**
     * \brief getPrecedence
     * recupère la précédence d'id passé
     * \param id
     * id de la tâche précédence
     * \return la tâche
     */
    Tache* getPrecedence(int id);
    /**
     * \brief ajouterPrecedence
     * ajoute la tâche passée en tant que précédence
     * \param pred
     * la nouvelle précédence
     */
    void ajouterPrecedence(Tache* pred)throw(AgendaException);
    /**
     * \brief supprimerPrecedence
     * supprime la précédence d'id passé
     * \param id
     * id de la tâche à délier
     */
    void supprimerPrecedence(int id);

    /**
     * \brief precedencesFinies
     * vérifie si toutes les précédences sont terminées
     * \return vrai si oui, faux sinon
     */
    bool precedencesFinies();
    virtual void afficher()const = 0;

    /**
     * \class       Iterator tache.h "headers/tache.h"
     * \author      DELAUNAY Grégory
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe Iterator
     * \details     permet de parcourir l'ensemble des tâches liées à une tâche
     */
    class Iterator
    {
        QList<Tache*>::iterator itCour; /** l'iterateur courant */
    public:
        /**
         * \brief Iterator
         * constructeur
         * \param i
         * début d'itération
         */
        Iterator(QList<Tache*>::iterator i){itCour = i;}
        /**
         * \brief valeur
         * \return la valeur de 'iterateur courant
         */
        Tache* valeur(){return *itCour;}
        /**
         * \brief courant
         * retourne l'iterateur courant
         * \return l'itérateur courant
         */
        QList<Tache*>::iterator& courant(){return itCour;}
        /**
         * \brief next
         * passe à la valeur d'arrêt
         */
        void next(){++itCour;}
    };
    /**
     * \brief getIterator
     * retourne l'itérateur construit
     * \return
     * l'Iterateur
     */
    Iterator getIterator(){return Iterator(precedence.begin());}
    typename QList<Tache*>::iterator end(){return precedence.end();}

    /**
     * \class       constIterator tache.h "headers/tache.h"
     * \author      NEVEUX Anaïs
     * \version     1.0
     * \date        04 juin 2015
     * \brief       Implémente la classe constIterator
     * \details     permet de parcourir l'ensemble des tâches sans pouvoir les modifier
     */
    class constIterator
    {
        QList<Tache*>::const_iterator itCour; /** l'itérateur courant */
    public:
        /**
         * \brief constIterator
         * constructeur
         * \param i
         * début d'itération
         */
        constIterator(QList<Tache*>::const_iterator i){itCour = i;}
        /**
         * \brief valeur
         * \return la valeur de l'itérateur courant
         */
        const Tache* valeur(){return *itCour;}
        /**
         * \brief courant
         * \return l'itérateur courant
         */
        QList<Tache*>::const_iterator& courant(){return itCour;}
        /**
         * \brief next
         * passe à l'itération d'après
         */
        void next(){++itCour;}
    };
    /**
     * \brief getIterator
     * \return retourne l'itérateur construit
     */
    constIterator getIterator()const{return constIterator(precedence.begin());}
    /**
     * \brief end
     * \return itérateur sur la fin d'itération
     */
    typename QList<Tache*>::const_iterator end()const{return precedence.end();}

};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Tache*)
#endif // TACHE_H
