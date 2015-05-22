#ifndef AJOUTEURPROJET_H
#define AJOUTEURPROJET_H

#include "ajouteur.h"
#include "projet.h"
class AjouteurProjet : public Ajouteur<Projet*>
{
protected:
    virtual Projet* construire(std::map<QString,QVariant>& params)const;
public:
    virtual void afficher()const {std::cout << "je suis un ajouteur de projet\n";}
    AjouteurProjet(const AjouteurProjet&){}
    AjouteurProjet& operator=(const AjouteurProjet&){}
    AjouteurProjet():Ajouteur()
    {
        types.insert("titre");
        types.insert("dispo");
        types.insert("echeance");
    }
};

#endif // AJOUTEURPROJET_H
