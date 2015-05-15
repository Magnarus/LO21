#ifndef AJOUTEURTACHEUNITAIRE_H
#define AJOUTEURTACHEUNITAIRE_H
#include "ajouteur.h"
#include "tache_unitaire.h"
#include <QString>
#include <QDate>
class AjouteurTacheUnitaire : public Ajouteur
{
public:
    AjouteurTacheUnitaire();
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    void ajout(std::vector<Tache*>& conteneur,const int id, const QString& titre, const QDate&
                            dispo, const QDate& deadline, const QTime& dur,bool preemptive);
};

#endif // AJOUTEURTACHEUNITAIRE_H
