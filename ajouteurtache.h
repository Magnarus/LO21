#ifndef AJOUTEURTACHE_H
#define AJOUTEURTACHE_H
#include "ajouteur.h"
#include "tache.h"
class AjouteurTache : public Ajouteur<Tache*>
{
public:
    AjouteurTache(){}
    virtual void afficher()const = 0;
};

#endif // AJOUTEURTACHE_H
