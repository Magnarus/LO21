#include "../headers/tache_composite.h"
#include<typeinfo>
bool Tache_Composite::estSousTache(int id)
{
    bool ok;
    QList<Tache*>::iterator it = sousTaches.begin();
    while(it!=sousTaches.end() && ok)
    {
        ok = id!=(*it)->getId();
        ++it;
    }
    return !ok;
}

void Tache_Composite::ajouterSousTache(Tache *st)
{
    int identifiant = st->getId();
    bool ok;
    if(!estSousTache(identifiant))
    {
        if(typeid(st).name() == "Tache_Composite")
        {
            ok = !dynamic_cast<Tache_Composite*>(st)->estSousTache(this->id);
        }
        if(ok && st->getEcheance() <= getEcheance())
        {
            sousTaches.push_back(st);
        }
    }
}
