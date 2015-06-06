#include "../headers/ajouteurprogactivite.h"
Programmation* AjouteurProgActivite::construire(QMap<QString, QVariant> &params)const
{
    int id;
    QDate date;
    QTime duree;
    Activite* act;
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    if(verifTypes(params.keys()))
    {
        //On récup les param de la prog
        id = params["id"].toInt();
        date = params["date"].toDate();
        duree = params["duree"].toTime();
        act = params["programme"].value<Activite*>();
    }
    else throw AgendaException("les paramètres passés ne correspondent pas");
    return new ProgActivite(id,date,duree,act);
}

