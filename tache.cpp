#include "tache.h"

Tache* Tache::getPrecedence(int id)
{
    std::vector<Tache*>::iterator it = precedence.begin();
    while(it!=precedence.end() && id!=(*it)->getId())
        ++it;
    return *it;
}

bool Tache::estPredecence(int id)
{
    bool ok;
    std::vector<Tache*>::iterator it = this->precedence.begin();
    while(it!=precedence.end() && ok)
    {
        ok = id!=(*it)->getId();
        ++it;
    }
    return !ok;
}

void Tache::ajouterPrecedence(Tache *pred)
{
    int id = pred->getId();
    if(!this->estPredecence(id))
       if(!pred->estPredecence(this->id))
           precedence.push_back(pred);

}
