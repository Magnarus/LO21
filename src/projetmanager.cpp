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
