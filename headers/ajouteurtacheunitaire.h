#ifndef AJOUTEURTACHEUNITAIRE_H
#define AJOUTEURTACHEUNITAIRE_H
#include "ajouteurtache.h"
#include "tache_unitaire.h"
#include "tachemanager.h"
#include <QString>
#include <QDate>
class AjouteurTacheUnitaire : public AjouteurTache
{
protected:
    virtual Tache* construire(std::map<QString,QVariant>& params)const override;
public:
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    AjouteurTacheUnitaire():AjouteurTache()
    {
        types.insert("dur");
        types.insert("preempt");
    }
    AjouteurTacheUnitaire(const AjouteurTacheUnitaire&);
    AjouteurTacheUnitaire& operator=(const AjouteurTacheUnitaire&);
};

#endif // AJOUTEURTACHEUNITAIRE_H
