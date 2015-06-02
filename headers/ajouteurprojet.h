#ifndef AJOUTEURPROJET_H
#define AJOUTEURPROJET_H
#include "ajouteur.h"
#include "projet.h"
class AjouteurProjet : public Ajouteur<Projet*>
{
protected:
    virtual Projet* construire(QMap<QString,QVariant>& params)const override;
    AjouteurProjet(const AjouteurProjet&);
    AjouteurProjet& operator=(const AjouteurProjet&);
public:
    virtual void afficher()const override {std::cout << "je suis un ajouteur de projet\n";}
    AjouteurProjet():Ajouteur()
    {
        types.insert("id");
        types.insert("titre");
        types.insert("dispo");
        types.insert("echeance");
    }
};

#endif // AJOUTEURPROJET_H
