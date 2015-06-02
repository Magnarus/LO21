#include "../headers/progmanager.h"

ProgManager::ProgManager()
{
    AjouteurProgActivite* aa = new AjouteurProgActivite();
    AjouteurProgTUnit* aptu = new AjouteurProgTUnit();
    ajouteurs["ACTIVITE"] = aa;
    ajouteurs["UNITAIRE"] = aptu;
}
TManager<Programmation*> *ProgManager::getInstance(){
    if (handler.instance==0) handler.instance =new ProgManager;
    return handler.instance;
}
