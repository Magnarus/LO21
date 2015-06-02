#include "../headers/ajouteurtachecomposite.h"
Tache* AjouteurTacheComposite::construire(std::map<QString,QVariant>& params)const
{
    bool aSousTaches = false;
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    for(std::map<QString,QVariant>::const_iterator it = params.begin(); it!=params.end();++it)
    {
        if(types.find(it->first) == types.end())
        {
            if (it->first == "list")
            {
                aSousTaches = true;
            }
            else
            {
                throw AgendaException("Paramètre passé incorrect");
            }
        }
    }
    //On récup les param de la tâches.
    int id = params["id"].toInt();
    QString titre = params["titre"].toString();
    QDate dispo(params["dispo"].toDate());
    QDate deadline(params["deadline"].toDate());
    if(aSousTaches)
    {
        QList<Tache*> list = params["list"].value<QList<Tache*> >();
        return new Tache_Composite(id,titre,dispo,deadline,list);
    }
    return new Tache_Composite(id,titre,dispo,deadline);
}

