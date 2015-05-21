#ifndef AJOUTEURTACHECOMPOSITE_H
#define AJOUTEURTACHECOMPOSITE_H
#include "ajouteurtache.h"
#include "tache_composite.h"
#include <QString>
#include <QDate>
#include <iostream>
#include "tachemanager.h"
Q_DECLARE_METATYPE( QList<Tache*> ) // Sert à indiquer au QVariant que ce type existe
class AjouteurTacheComposite : public AjouteurTache
{
protected:
    AjouteurTacheComposite(const AjouteurTacheComposite&);
    AjouteurTacheComposite& operator=(const AjouteurTacheComposite&);
    virtual Tache* construire(std::map<QString,QVariant>& params)const override;

public:
    virtual void afficher()const override{ std::cout << "Je suis un ajouteur de tache composite\n";}
    AjouteurTacheComposite():AjouteurTache()
    {
        types.insert("list");
    }
};

#endif // AJOUTEURTACHECOMPOSITE_H
