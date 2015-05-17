#include "ajouteurtachecomposite.h"
#include "ajouteurtacheunitaire.h"
#include "tachemanager.h"

int main()
{
    QString titre = "God save the Queen";
    QDate dispo, deadline;
    QTime dur(12,0);
    bool ok = true;
    TManager<Tache*,Ajouteur<Tache*>*>* m = TacheManager::getInstance();
    AjouteurTacheUnitaire* atu = dynamic_cast<AjouteurTacheUnitaire*>(m->getAjouteur("UNITAIRE"));
    atu->ajout(1,titre,dispo,deadline,dur,m,ok);
    std::cout << "nombre de taches : " << m->nbItem() << std::endl;
    return 0;
}
