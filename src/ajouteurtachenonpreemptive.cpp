#include "../headers/ajouteurtachenonpreemptive.h"
Tache* AjouteurTacheNonPreemptive::construire(QMap<QString,QVariant>& params)const throw(AgendaException)
{
    int id;
    QString titre;
    QDate dispo;
    QDate deadline;
    QTime duree;
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    if(verifTypes(params.keys()))
    {
        //On récup les param de la tâche
        id = params["id"].toInt();
        titre = params["titre"].toString();
        dispo = params["dispo"].toDate();
        deadline = params["deadline"].toDate();
        duree = params["dur"].toTime();
    }
    else throw AgendaException("Paramètre passés invalides");

    return new TacheNonPreemptive(id,titre,dispo,deadline,duree);
}
