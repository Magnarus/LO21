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
/**
 * \class       Tache tache.h "headers/tache.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache
 * \details     Une tâche est un évènement qui doit être réalisé durant un interval de dates donné.
 */
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

    bool estPredecence(int id);
    Tache(const Tache&);
    Tache& operator=(const Tache&);
public:
    Tache();
    Tache(const int id, const QString& titre, const QDate&
          dispo, const QDate& deadline)
         :id(id),titre(titre),dateDispo(dispo),dateEcheance(deadline),typeT(TACHE)
    {}
    inline int getId()const { return id;}
    inline const QString& getTitre()const {return titre;}
    inline const QDate& getDateDispo()const {return dateDispo;}
    inline const QDate& getEcheance()const {return dateEcheance;}
    inline const Etats getEtat()const {return etat;}
    inline const QString getRealTypeName()const { return QString(typeid(this).name());}
    inline const typeTache getType()const { return typeT;}

    inline void setTitre(QString& t){titre=t;}
    inline void setDateDispo(QDate& d){dateDispo =d;}
    inline void setEcheance(QDate& d){dateEcheance=d;}
    inline void setEtat(Etats e){etat = e;}
    inline void setType(typeTache t){typeT = t;}

    Tache* getPrecedence(int id);
    void ajouterPrecedence(Tache* pred)throw(AgendaException);
    virtual void afficher()const = 0;
};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Tache*)
#endif // TACHE_H
