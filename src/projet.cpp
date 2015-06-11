#include "../headers/projet.h"
#include<QDebug>
#include"../headers/tachemanager.h"
Projet::Projet(int id, QString &t, QDate &dispo, QDate &echeance):id(id),titre(t),dateDispo(dispo),dateEcheance(echeance)
{
    if(dispo > echeance)throw AgendaException("Un projet doit se finir après avoir commencé !");
}
Projet::~Projet()
{
    QList<Tache*>::iterator it = taches.begin();
    for(it;it!=taches.end();++it)
        TacheManager::getInstance()->supprimerItem((*it)->getId());
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

void Projet::ajouterTache(Tache *t)throw(AgendaException)
{
    //On vérifie qu'on ajoute une tache non présente dans le projet
    int id = t->getId();
    qDebug() << "id de la tache a ajouter" << id;
    QList<Tache*>::iterator it = taches.begin();
    bool ok=true;
    while(it!=taches.end() && ok)
    {
        qDebug() << "id testé " << (*it)->getId();
        ok = id!=(*it)->getId();
        ++it;
    }
    if(ok) ok = t->getDateDispo() >= this->dateDispo && t->getEcheance() <= this->dateEcheance;
    else throw AgendaException("La tâche est déjà dans le projet");
    if(ok) taches.push_back(t);
    else throw AgendaException("La tâche a des dates incompatibles avec le projet");
}

bool Projet::supprSiDedans(int id)
{
    QList<Tache*>::iterator it = taches.begin();
    bool dedans = false;
    while(it != taches.end() && !dedans)
    {
        dedans = ((*it)->getId() == id);
        if(dedans)
        {
           taches.erase(it);
        }
        ++it;
    }
    return dedans;
    qDebug() << "je ressors";
}
