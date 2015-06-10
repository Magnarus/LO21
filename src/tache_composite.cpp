#include "../headers/tache_composite.h"
#include<typeinfo>
#include<QDebug>
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
