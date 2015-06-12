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
 * \author      DELAUNAY Grégory
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
    int id;
    QString titre;
    QList<Tache*> precedence;
    QDate dateDispo;
    QDate dateEcheance;
    Etats etat;
    typeTache typeT;

    Tache(const Tache&);
    Tache& operator=(const Tache&);
public:
    Tache();
    Tache(const int id, const QString& titre, const QDate&
          dispo, const QDate& deadline)
         :id(id),titre(titre),dateDispo(dispo),dateEcheance(deadline),typeT(TACHE)
    {    if(dispo > deadline)throw AgendaException("Une tache doit se finir après avoir commencé !");
    }
    inline int getId()const { return id;}
    inline QString& getTitre() {return titre;}
    inline const QString& getTitre()const{return titre;}
    inline const QDate& getDateDispo()const {return dateDispo;}
    inline const QDate& getEcheance()const {return dateEcheance;}
    inline const Etats getEtat()const {return etat;}
    inline const QString getRealTypeName()const { return QString(typeid(this).name());}
    inline const typeTache getType()const { return typeT;}
    const QString getTypeToQString()const;
    inline void setTitre(QString& t){titre=t;}
    void setDateDispo(QDate& d);
    void setEcheance(QDate& d);
    inline void setEtat(Etats e){etat = e;}
    inline void setType(typeTache t){typeT = t;}
    bool estPredecence(int id);
    Tache* getPrecedence(int id);
    void ajouterPrecedence(Tache* pred)throw(AgendaException);
    void supprimerPrecedence(int id);
    bool precedencesFinies();
    virtual void afficher()const = 0;

    class Iterator
    {
        QList<Tache*>::iterator itCour;
    public:
        Iterator(QList<Tache*>::iterator i){itCour = i;}
        Tache* valeur(){return *itCour;}
        QList<Tache*>::iterator& courant(){return itCour;}
        void next(){++itCour;}
    };
    Iterator getIterator(){return Iterator(precedence.begin());}
    typename QList<Tache*>::iterator end(){return precedence.end();}

    class constIterator
    {
        QList<Tache*>::const_iterator itCour;
    public:
        constIterator(QList<Tache*>::const_iterator i){itCour = i;}
        const Tache* valeur(){return *itCour;}
        QList<Tache*>::const_iterator& courant(){return itCour;}
        void next(){++itCour;}
    };
    constIterator getIterator()const{return constIterator(precedence.begin());}
    typename QList<Tache*>::const_iterator end()const{return precedence.end();}

};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Tache*)
#endif // TACHE_H
