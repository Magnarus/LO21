#ifndef AJOUTEURTACHE_H
#define AJOUTEURTACHE_H
#include "ajouteur.h"
#include "tache.h"
#include <set>
class AjouteurTache : public Ajouteur<Tache*>
{
protected:
    AjouteurTache():Ajouteur()
    {
        types.insert("id");
        types.insert("titre");
        types.insert("dispo");
        types.insert("deadline");
        types.insert("dur");
    }
    AjouteurTache(const AjouteurTache&);
    AjouteurTache& operator=(const AjouteurTache&);
    virtual Tache* construire(std::map<QString,QVariant>& params)const = 0;
    std::set<QString> types; //Sert à indiquer les champs requis dans l'ajouteur
public:
    virtual void afficher()const = 0;
};

#endif // AJOUTEURTACHE_H
