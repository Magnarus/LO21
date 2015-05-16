#ifndef AJOUTEURTACHEUNITAIRE_H
#define AJOUTEURTACHEUNITAIRE_H
#include "ajouteurtache.h"
#include "tache_unitaire.h"
#include <QString>
#include <QDate>
class AjouteurTacheUnitaire : public AjouteurTache
{
public:
    AjouteurTacheUnitaire():AjouteurTache(){}
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    void ajout(const int id, const QString& titre, const QDate&
                dispo, const QDate& deadline, const QTime& dur,bool preemptive)
    {
        Tache* tu = new Tache_Unitaire(id,titre,dispo,deadline,dur,preemptive);
        ajouter(tu);
    }
};

#endif // AJOUTEURTACHEUNITAIRE_H
