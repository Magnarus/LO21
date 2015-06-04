#ifndef PROJET_H
#define PROJET_H
#include<QDate>
#include<QString>
#include<QList>
#include"tache.h"
#include "agendaexception.h"
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
    inline const int getId()const {return id;}
    inline const QDate& getDateDispo()const{return dateDispo;}
    inline const QDate& getDateEcheance()const{return dateEcheance;}
    inline const QString& getTitre()const{return titre;}
    inline void setTitre(QString& t){titre=t;}
    inline void setDateDispo(QDate& d){dateDispo = d;}
    inline void setDateEcheance(QDate& d){dateEcheance = d;}
    Tache& getTache(int id);
    void ajouterTache(Tache* t);
};

#endif // PROJET_H
