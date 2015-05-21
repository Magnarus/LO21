#include "ajouteurtacheunitaire.h"
#include "ajouteurtachecomposite.h"
TacheManager::TacheManager()
{
    AjouteurTacheUnitaire* atu = new AjouteurTacheUnitaire();
    AjouteurTacheComposite* atc = new AjouteurTacheComposite();
    ajouteurs["UNITAIRE"] = atu;
    ajouteurs["COMPOSITE"] = atc;
}
TManager<Tache*> *TacheManager::getInstance(){
    if (handler.instance==0) handler.instance =new TacheManager;
    return handler.instance;
}
