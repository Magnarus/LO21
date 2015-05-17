#ifndef AJOUTEUR_H
#define AJOUTEUR_H
#include <iostream>
#include "tmanager.h"
template<typename U>
class Ajouteur
{
protected:
    Ajouteur(){}
    Ajouteur(const Ajouteur&);
    Ajouteur& operator=(const Ajouteur&);
protected:
    void ajouter(TManager<U,Ajouteur*>* m,U u)const
    {
        m->addItem(u);
    }
public:
    virtual void afficher()const = 0;
};

#endif // AJOUTEUR_H
