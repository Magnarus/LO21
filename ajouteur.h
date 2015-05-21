#ifndef AJOUTEUR_H
#define AJOUTEUR_H
#include <iostream>
#include "tmanager.h"
template<typename U>
class Ajouteur
{
    friend class TManager<U>; // Pour que seuls les manager puissent créer des objets (principe du Manager ! )
protected:
    Ajouteur(){}
    Ajouteur(const Ajouteur&);
    Ajouteur& operator=(const Ajouteur&);
protected:
    virtual U construire(std::map<QString,QVariant>& params)const = 0;
public:
    virtual void afficher()const = 0;
};

#endif // AJOUTEUR_H
