#include "../headers/ajouteurprojet.h"

Projet *AjouteurProjet::construire(std::map<QString,QVariant>& params)const
{
    //On vérifie que les paramètres passés correspondent bien à un projet
    for(std::map<QString,QVariant>::const_iterator it = params.begin(); it!=params.end();++it)
    {
        std::cout << it->first.toStdString() << std::endl;
        if(types.find(it->first) == types.end())
        {
            throw AgendaException("Paramètre passé incorrect");
        }
    }
    //On récup les param de la tâche
    int id = params["id"].toInt();
    QString titre = params["titre"].toString();
    QDate dispo(params["dispo"].toDate());
    QDate echeance(params["echeance"].toDate());

    return new Projet(id,titre,dispo,echeance);
}
