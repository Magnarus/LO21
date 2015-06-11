#include "../headers/tache.h"

Tache* Tache::getPrecedence(int id)
{
    QList<Tache*>::iterator it = precedence.begin();
    while(it!=precedence.end() && id!=(*it)->getId())
        ++it;
    return *it;
}

bool Tache::estPredecence(int id)
{
    bool ok=false;
    QList<Tache*>::iterator it = this->precedence.begin();
    while(it!=precedence.end() && !ok)
    {
        ok = (id ==(*it)->getId());
        ++it;
    }
    return ok;
}

void Tache::ajouterPrecedence(Tache *pred)throw(AgendaException)
{
    int id = pred->getId();
    if(!this->estPredecence(id))
       if(!pred->estPredecence(this->id))
           precedence.push_back(pred);
       else throw AgendaException("Impossible d'avoir des précédences mutuelles");
    else throw AgendaException("Précédence déjà existante");

}

const QString Tache::getTypeToQString()const
{
    QString resultat;
    switch(typeT)
    {
        case TACHE:
            resultat = "TACHE";
            break;
        case UNITAIRE:
            resultat = "UNITAIRE";
            break;
        case COMPOSITE:
            resultat = "COMPOSITE";
            break;
        case PREEMPTIVE:
            resultat = "UNITAIRE PREEMPTIVE";
            break;
        default:
            resultat = "UNITAIRE NON PREEMPTIVE";
    }
    return resultat;
}
