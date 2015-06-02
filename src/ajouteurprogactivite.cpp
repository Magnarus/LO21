#include "../headers/ajouteurprogactivite.h"
Programmation* AjouteurProgActivite::construire(std::map<QString,QVariant>& params)const
{
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    for(std::map<QString,QVariant>::const_iterator it = params.begin(); it!=params.end();++it)
    {
        std::cout << it->first.toStdString() << std::endl;
        if(types.find(it->first) == types.end())
        {
            throw AgendaException("Paramètre passé incorrect");
            break;
        }
    }
    //On récup les param de la prog
    int id = params["id"].toInt();
    QDate date(params["date"].toDate());
    QTime duree(params["dur"].toTime());
    Activite* act = params["programme"].value<Activite*>();

    return new ProgActivite(id,date,duree,act);
}

