#include "../headers/ajouteurtachepreemptive.h"
#include "../headers/ajouteurtachenonpreemptive.h"
#include "../headers/ajouteurtachecomposite.h"
TacheManager::TacheManager()
{
    AjouteurTachePreemptive* atp = new AjouteurTachePreemptive();
    AjouteurTacheNonPreemptive* atnp = new AjouteurTacheNonPreemptive();
    AjouteurTacheComposite* atc = new AjouteurTacheComposite();
    ajouteurs["PREEMPTIVE"] = atp;
    ajouteurs["NON_PREEMPTIVE"] = atnp;
    ajouteurs["COMPOSITE"] = atc;
}
TManager<Tache*> *TacheManager::getInstance(){
    if (handler.instance==0) handler.instance =new TacheManager;
    return handler.instance;
}
