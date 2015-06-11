#include "../headers/projetmanager.h"

ProjetManager::ProjetManager()
{
    AjouteurProjet* ap = new AjouteurProjet();
    cles.insert("PROJET");
    ajouteurs["PROJET"] = ap;
}
TManager<Projet*> *ProjetManager::getInstance(){
    if (handler.instance==0) handler.instance =new ProjetManager;
    return handler.instance;
}

Projet* ProjetManager::getProjetTache(int id)
{
    Projet* p;
    bool dedans = false;
    QVector<Projet*>::iterator it = managable.begin();
    while(it != managable.end() && !dedans)
    {
        dedans = (*it)->aTache(id);
        if(dedans)
        {
            p = *it;
        }
    }
    return p;
}
