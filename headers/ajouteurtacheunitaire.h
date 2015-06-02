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
    virtual Tache* construire(std::map<QString,QVariant>& params)const = 0;
public:
    virtual void afficher()const =0;
    AjouteurTacheUnitaire():AjouteurTache()
    {
        types.insert("dur");
    }
    AjouteurTacheUnitaire(const AjouteurTacheUnitaire&);
    AjouteurTacheUnitaire& operator=(const AjouteurTacheUnitaire&);
};

#endif // AJOUTEURTACHEUNITAIRE_H
