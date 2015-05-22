#ifndef AJOUTEUR_H
#define AJOUTEUR_H
#include <iostream>
#include <set>
#include "tmanager.h"
template<typename U>
class Ajouteur
{
    friend class TManager<U>; // Pour que seuls les manager puissent créer des objets (principe du Manager ! )
protected:
    std::set<QString> types; //Sert à indiquer les champs requis dans l'ajouteur
protected:
    virtual U construire(std::map<QString,QVariant>& params)const = 0;
public:
    virtual void afficher()const = 0;
    Ajouteur(){}
    Ajouteur(const Ajouteur&);
    Ajouteur& operator=(const Ajouteur&);
};

#endif // AJOUTEUR_H
