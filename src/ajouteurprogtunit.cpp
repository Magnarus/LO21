#include "../headers/ajouteurprogtunit.h"
Programmation* AjouteurProgTUnit::construire(std::map<QString,QVariant>& params)const
{
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    for(std::map<QString,QVariant>::const_iterator it = params.begin(); it!=params.end();++it)
    {
        std::cout << it->first.toStdString() << std::endl;
        if(types.find(it->first) == types.end())
        {
            throw AgendaException("Paramètre passé incorrect");
        }
    }
    //On récup les param de la prog
    int id = params["id"].toInt();
    QDate date(params["date"].toDate());
    QTime duree(params["dur"].toTime());
    Tache_Unitaire* tu = params["programme"].value<Tache_Unitaire*>();

    return new ProgTUnit(id,date,duree,tu);
}
