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
    Tache *getTache(int id);
    bool estTache(int id);
    void ajouterTache(Tache* t)throw(AgendaException);
};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Projet*)
#endif // PROJET_H
