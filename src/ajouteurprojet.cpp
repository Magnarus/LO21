#include "../headers/ajouteurprojet.h"

Projet *AjouteurProjet::construire(QMap<QString, QVariant> &params)const
{
    int id;
    QString titre;
    QDate dispo;
    QDate echeance;
    //On vérifie que les paramètres passés correspondent bien à un projet
    if(verifTypes(params.keys()))
    {
        //On récup les param de la tâche
        id = params["id"].toInt();
        titre = params["titre"].toString();
        dispo = params["dispo"].toDate();
        echeance = params["echeance"].toDate();
    }
    else throw AgendaException("Paramètre passés incorrects");
    return new Projet(id,titre,dispo,echeance);
}
