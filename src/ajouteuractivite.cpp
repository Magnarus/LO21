#include "headers/ajouteuractivite.h"

Activite* AjouteurActivite::construire(QMap<QString,QVariant>& params)const throw(AgendaException)
{
    int id;
    QDate date;
    QTime duree;
    QString nom;
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    if(verifTypes(params.keys()))
    {
        id = params["id"].toInt();
        date = params["date"].toDate();
        duree = params["duree"].toTime();
        nom = params["nom"].toString();
    }
    else throw AgendaException("Paramètre passés invalides");

    return new Activite(id,date,duree,nom);
}
