#ifndef AJOUTEURTACHECOMPOSITE_H
#define AJOUTEURTACHECOMPOSITE_H
#include "ajouteurtache.h"
#include "tache_composite.h"
#include <QString>
#include <QDate>
#include <iostream>
#include "tachemanager.h"
/**
 * \class       AjouteurTacheComposite ajouteurtachecomposite.h "headers/ajouteurtachecomposite.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurTacheComposite
 * \extends     AjouteurTache
 * \details     Cette classe définit les ajouteurs de Tache_Composite
 *              Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *              Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *              avoir à tout recompiler.
 */
class AjouteurTacheComposite : public AjouteurTache
{
protected:
    virtual Tache* construire(QMap<QString,QVariant>& params)const throw(AgendaException) override;
    AjouteurTacheComposite(const AjouteurTacheComposite&);
    AjouteurTacheComposite& operator=(const AjouteurTacheComposite&);
public:
    virtual void afficher()const override{ std::cout << "Je suis un ajouteur de tache composite\n";}
    AjouteurTacheComposite():AjouteurTache()
    {}
};

#endif // AJOUTEURTACHECOMPOSITE_H
