#include "ajouteurtachecomposite.h"
#include "ajouteurtacheunitaire.h"
#include "tachemanager.h"

int main()
{
    AjouteurTache* atu = new AjouteurTacheUnitaire();
    TacheManager::getInstance()->addAjouteur("UNITAIRE",atu);
    QString titre = "God save the Queen";
    QDate dispo, deadline;
    QTime dur(12,0);
    bool ok;
    TacheManager::getInstance()->getAjouteur("UNITAIRE")->afficher();

    return 0;
}
