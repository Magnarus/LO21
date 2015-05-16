#ifndef PROJET_H
#define PROJET_H
#include<QDate>
#include<QString>
#include<vector>
#include"tache.h"
class Projet
{
    QDate dateDispo;
    QDate dateEcheance;
    QString titre;
    std::vector<Tache*> taches;
public:
    Projet();
    inline QDate getDateDispo()const{return dateDispo;}
    inline QDate getDateEcheance()const{return dateEcheance;}
    inline QString getTitre()const{return titre;}
    inline void setTitre(QString& t){titre=t;}
    inline void setDateDispo(QDate& d){dateDispo = d;}
    inline void setDateEcheance(QDate& d){dateEcheance = d;}
    Tache& getTache(int id);
    void ajouterTache(Tache* t);
};

#endif // PROJET_H
