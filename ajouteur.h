#ifndef AJOUTEUR_H
#define AJOUTEUR_H
#include <iostream>
#include "tmanager.h"
template<typename T>
class Ajouteur
{
public:
    Ajouteur(){}
    virtual void afficher()const = 0;
    void ajouter(T u)const
    {
        TManager<T,Ajouteur*>::getInstance()->addItem(&u);
    }
};

#endif // AJOUTEUR_H
