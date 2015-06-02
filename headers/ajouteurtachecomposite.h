#ifndef AJOUTEURTACHECOMPOSITE_H
#define AJOUTEURTACHECOMPOSITE_H
#include "ajouteurtache.h"
#include "tache_composite.h"
#include <QString>
#include <QDate>
#include <iostream>
#include "tachemanager.h"
class AjouteurTacheComposite : public AjouteurTache
{
protected:
    virtual Tache* construire(QMap<QString,QVariant>& params)const override;
    AjouteurTacheComposite(const AjouteurTacheComposite&);
    AjouteurTacheComposite& operator=(const AjouteurTacheComposite&);
public:
    virtual void afficher()const override{ std::cout << "Je suis un ajouteur de tache composite\n";}
    AjouteurTacheComposite():AjouteurTache()
    {}
};

#endif // AJOUTEURTACHECOMPOSITE_H
