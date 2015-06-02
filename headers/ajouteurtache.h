#ifndef AJOUTEURTACHE_H
#define AJOUTEURTACHE_H
#include "ajouteur.h"
#include "tache.h"
Q_DECLARE_METATYPE( QList<Tache*> ) // Sert à indiquer au QVariant que ce type existe
class AjouteurTache : public Ajouteur<Tache*>
{
protected:
    virtual Tache* construire(QMap<QString,QVariant>& params)const = 0;
    AjouteurTache(const AjouteurTache&);
    AjouteurTache& operator=(const AjouteurTache&);
public:
    virtual void afficher()const = 0;
    AjouteurTache():Ajouteur()
    {
        types.insert("id");
        types.insert("titre");
        types.insert("dispo");
        types.insert("deadline");
    }
};

#endif // AJOUTEURTACHE_H
