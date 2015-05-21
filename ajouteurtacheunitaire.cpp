#include "ajouteurtacheunitaire.h"
Tache* AjouteurTacheUnitaire::construire(std::map<QString,QVariant>& params)const
{
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    for(std::map<QString,QVariant>::const_iterator it = params.begin(); it!=params.end();++it)
    {
        std::cout << it->first.toStdString() << std::endl;
        if(types.find(it->first) == types.end())
        {
            //Throw exception plus tard
            std::cout << "Mauvais paramètre passé\n";
            break;
        }
    }
    //On récup les param de la tâche
    int id = params["id"].toInt();
    QString titre = params["titre"].toString();
    QDate dispo(params["dispo"].toDate());
    QDate deadline(params["deadline"].toDate());
    QTime duree(params["dur"].toTime());
    bool preempt = params["list"].toBool();

    return new Tache_Unitaire(id,titre,dispo,deadline,duree,preempt);
}

