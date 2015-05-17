#ifndef AJOUTEURTACHE_H
#define AJOUTEURTACHE_H
#include "ajouteur.h"
#include "tache.h"
class AjouteurTache : public Ajouteur<Tache*>
{
    friend class TacheManager;
protected:
    AjouteurTache():Ajouteur(){}
    AjouteurTache(const AjouteurTache&);
    AjouteurTache& operator=(const AjouteurTache&);
public:
    virtual void afficher()const = 0;
};

#endif // AJOUTEURTACHE_H
