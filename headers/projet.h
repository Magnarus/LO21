#ifndef PROJET_H
#define PROJET_H
#include<QDate>
#include<QString>
#include<QList>
#include"tache.h"
#include "agendaexception.h"
/**
 * \class       Projet projet.h "headers/projet.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Projet
 * \details     Le projet est un ensemble de tâches qui doivent être commencé à partir d'une date
 *              et terminés avant une autre
 */
class Projet
{
    int id;
    QDate dateDispo;
    QDate dateEcheance;
    QString titre;
    QList<Tache*> taches;
    Projet(const Projet&);
    Projet& operator=(const Projet&);
public:
    Projet(int id,QString& t, QDate& dispo, QDate& echeance);
    ~Projet();
    inline const int getId()const {return id;}
    inline const QDate& getDateDispo()const{return dateDispo;}
    inline const QDate& getDateEcheance()const{return dateEcheance;}
    inline const QString& getTitre()const{return titre;}
    inline void setTitre(QString& t){titre=t;}
    void setDateDispo(QDate& d)throw(AgendaException);
    void setDateEcheance(QDate& d)throw(AgendaException);
    inline const int getNbTaches()const{return taches.size();}
    Tache* getTache(int id);
    inline Tache* getTacheParCompteur(int i){return taches[i];}
    bool aTache(int id);
    void ajouterTache(Tache* t)throw(AgendaException);
    bool supprSiDedans(int id);
    class Iterator
    {
        QList<Tache*>::iterator itCour;
    public:
        Iterator(QList<Tache*>::iterator i){itCour = i;}
        Tache* valeur(){return *itCour;}
        QList<Tache*>::iterator& courant(){return itCour;}
        void next(){++itCour;}
    };
    Iterator getIterator(){return Iterator(taches.begin());}
    QList<Tache*>::iterator end(){return taches.end();}

    class IteratorDate
    {
        QList<Tache*>::iterator itCour;
        QList<Tache*> result;
    public:
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
        Tache* valeur(){return *itCour;}
        typename QList<Tache*>::iterator& courant(){return itCour;}
        void next(){++itCour;}
        QList<Tache*>::iterator end(){return result.end();}
    };
    IteratorDate getIteratorDate(const QDate& d, const QDate& f)
    {
        return IteratorDate(taches.begin(),taches.end(),d,f);
    }
};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Projet*)
#endif // PROJET_H
