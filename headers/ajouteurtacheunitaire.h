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
    virtual Tache* construire(QMap<QString,QVariant>& params)const = 0;
    AjouteurTacheUnitaire(const AjouteurTacheUnitaire&);
    AjouteurTacheUnitaire& operator=(const AjouteurTacheUnitaire&);
public:
    virtual void afficher()const =0;
    AjouteurTacheUnitaire():AjouteurTache()
    {
        types.insert("dur");
    }
};

#endif // AJOUTEURTACHEUNITAIRE_H
