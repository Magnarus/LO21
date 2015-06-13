#include "../headers/activitemanager.h"
#include "../headers/ajouteuractivite.h"
ActiviteManager::ActiviteManager()
{
    AjouteurActivite* aa = new AjouteurActivite();
    cles.insert("ACTIVITE");
    ajouteurs["ACTIVITE"] = aa;
}
TManager<Activite*> *ActiviteManager::getInstance(){
    if (handler.instance==0) handler.instance =new ActiviteManager;
    return handler.instance;
}
