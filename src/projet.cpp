#include "../headers/projet.h"
Projet::Projet(int id, QString &t, QDate &dispo, QDate &echeance):id(id),titre(t),dateDispo(dispo),dateEcheance(echeance)
{
}

Tache* Projet::getTache(int id)
{
    QList<Tache*>::iterator it = taches.begin();
    while(it!=taches.end() && id!=(*it)->getId())
        ++it;
    return *it;
}

void Projet::setDateDispo(QDate &d)throw(AgendaException)
{
    QList<Tache*>::iterator it = taches.begin();
    bool ok;
    while(it!=taches.end() && ok)
    {
        ok = d >=(*it)->getDateDispo();
        ++it;
    }
    if(!ok)throw AgendaException("Impossible: des taches commencent plus tard que la nouvelle date");
    dateDispo = d;
}

void Projet::setDateEcheance(QDate &d)throw(AgendaException)
{
    QList<Tache*>::iterator it = taches.begin();
    bool ok;
    while(it!=taches.end() && ok)
    {
        ok = d <= (*it)->getEcheance();
        ++it;
    }
    if(!ok)throw AgendaException("Impossible: des taches terminent plus tôt que la nouvelle date");
    dateEcheance = d;
}

void Projet::ajouterTache(Tache *t)
{
    //On vérifie qu'on ajoute une tache non présente dans le projet
    int id = t->getId();
    QList<Tache*>::iterator it = taches.begin();
    bool ok;
    while(it!=taches.end() && ok)
    {
        ok = id!=(*it)->getId();
        ++it;
    }
    if(ok) ok = t->getDateDispo() >= this->dateDispo && t->getEcheance() <= this->dateEcheance;
    else throw AgendaException("La tâche est déjà dans le projet");
    if(ok) taches.push_back(t);
    else throw AgendaException("La tâche a des dates incompatibles avec le projet");
}
