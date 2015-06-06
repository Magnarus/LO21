#include "../headers/ajouteurprogtunit.h"
Programmation* AjouteurProgTUnit::construire(QMap<QString,QVariant>& params)const throw(AgendaException)
{
    int id;
    QDate date;
    QTime duree;
    Tache_Unitaire* tu;
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    if(verifTypes(params.keys()))
    {
        id = params["id"].toInt();
        date = params["date"].toDate();
        duree = params["duree"].toTime();
        tu = params["programme"].value<Tache_Unitaire*>();
    }
    else throw AgendaException("Paramètre passés invalides");

    return new ProgTUnit(id,date,duree,tu);
}
