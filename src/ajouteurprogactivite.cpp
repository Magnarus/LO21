#include "../headers/ajouteurprogactivite.h"
Programmation* AjouteurProgActivite::construire(QMap<QString, QVariant> &params)const throw(AgendaException)
{
    int id;
    QDate date;
    QTime duree,horaire;
    Activite* act;
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    if(verifTypes(params.keys()))
    {
        //On récup les param de la prog
        id = params["id"].toInt();
        date = params["date"].toDate();
        duree = params["duree"].toTime();
        horaire = params["horaires"].toTime();
        act = params["programme"].value<Activite*>();
    }
    else throw AgendaException("les paramètres passés ne correspondent pas");
    return new ProgActivite(id,date,duree,horaire,act);
}

