#ifndef AJOUTEURTACHEUNITAIRE_H
#define AJOUTEURTACHEUNITAIRE_H
#include "ajouteurtache.h"
#include "tache_unitaire.h"
#include "tachemanager.h"
#include <QString>
#include <QDate>
class AjouteurTacheUnitaire : public AjouteurTache
{
    friend class TacheManager;
protected:
    AjouteurTacheUnitaire(){}
    AjouteurTacheUnitaire(const AjouteurTacheUnitaire&);
    AjouteurTacheUnitaire& operator=(const AjouteurTacheUnitaire&);
public:
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    void ajout(const int id, const QString& titre, const QDate&
                dispo, const QDate& deadline, const QTime& dur,
                TManager<Tache*,Ajouteur<Tache*>*>* m,bool preemptive)
    {
        Tache* tu = new Tache_Unitaire(id,titre,dispo,deadline,dur,preemptive);
        ajouter(m,tu);
    }
};

#endif // AJOUTEURTACHEUNITAIRE_H
