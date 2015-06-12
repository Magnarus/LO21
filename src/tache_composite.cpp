#include "../headers/tache_composite.h"
#include<typeinfo>
#include<QDebug>
#include"../headers/tachemanager.h"
Tache_Composite::~Tache_Composite()
{
    QList<Tache*>::iterator it = sousTaches.begin();
    for(it;it!=sousTaches.end();++it)
        TacheManager::getInstance()->supprimerItem((*it)->getId());
}

bool Tache_Composite::estSousTache(int id)
{
    qDebug() << "Je rentre";
    bool ok=true;
    QList<Tache*>::iterator it = sousTaches.begin();
    while(it!=sousTaches.end() && ok)
    {
        qDebug() << "id testé " << (*it)->getId();
        ok = id!=(*it)->getId();
        ++it;
    }
    return !ok;
}

void Tache_Composite::ajouterSousTache(Tache *st)throw(AgendaException)
{
    int identifiant = st->getId();
    bool ok=true;
    if(!estSousTache(identifiant))
    {
        if(st->getType() == COMPOSITE)
        {
            try
            {
                Tache_Composite* test = dynamic_cast<Tache_Composite*>(st);
                ok = !test->estSousTache(id);
            }
            catch(std::bad_cast& e){throw AgendaException("Conversion impossible");}
        }
        if(ok && st->getEcheance() <= getEcheance())
        {
            sousTaches.push_back(st);
        }
        else if(ok) throw AgendaException("Les dates ne correspondent pas");
        else throw AgendaException("Impossible d'être sous tâches mutuelles");
    }
    else throw AgendaException("Sous tâche déjà existante");
}

bool Tache_Composite::supprimerSousTache(int id)
{
    qDebug() << "rentré dans supprimer sous taches";
    qDebug() << "id à l'intérieur de la fonction " << id;
    bool dedans = false;
    QList<Tache*>::iterator it = sousTaches.begin();
    while(it!=sousTaches.end() && !dedans)
    {
        qDebug() << "id testé" << (*it)->getId();
        dedans= (*it)->getId() == id;
        qDebug() << "dedans ?" << dedans;
        if(dedans)
        {
            sousTaches.erase(it);
            qDebug() << "Tache bien supprimée ! ";
        }
        ++it;
    }

    return dedans;
}

bool Tache_Composite::estSousTacheRec(unsigned int id) const{
    bool ok=true;
    QList<Tache*>::const_iterator it = sousTaches.begin();
    while(it!=sousTaches.end() && ok)
    {
        //qDebug() << "id testé " << (*it)->getId();
        ok = id!=(*it)->getId();
        if(ok && (*it)->getType()==typeTache::COMPOSITE){ //Si la tache n'est pas celle recherchée et qu'en plus c'est une tâche composite, on cherche parmis ses sous-tâches
            ok=!(dynamic_cast<Tache_Composite*>(*it))->estSousTacheRec(id);
        }
        ++it;
    }
    return !ok;
}
