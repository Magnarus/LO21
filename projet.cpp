#include "projet.h"

Projet::Projet()
{
}

Tache& Projet::getTache(int id)
{
    std::vector<Tache*>::iterator it = taches.begin();
    while(it!=taches.end() && id!=(*it)->getId())
        ++it;
    return **it;
}

void Projet::ajouterTache(Tache *t)
{
    //On vérifie que la tâche n'existe pas.
    //TODO : créer un compteur d'instance pour id automatique et virer le test
    //Mais flemme ce soir.
    int id = t->getId();
    std::vector<Tache*>::iterator it = taches.begin();
    bool ok;
    while(it!=taches.end() && ok)
    {
        ok = id!=(*it)->getId();
        ++it;
    }
    if(ok) taches.push_back(t);
}
