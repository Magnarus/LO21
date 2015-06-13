#include "headers/ProgrammationProjetExport.h"

const QString ProgrammationProjetExport::generateFilename(){
    return ProgrammationExport::generateFilename()+"projet_"+projet->getTitre();
}

QVector<Programmation*> ProgrammationProjetExport::findElements(){
    QVector<Programmation*> result;
    ProgTUnit* ptu;
    for(ProgManager::Iterator it=ProgManager::getInstance()->getIterator();it.courant()!=ProgManager::getInstance()->end();it.next()){
        if(it.valeur()->getType()==typeProg::PROGTACHE){
            ptu=dynamic_cast<ProgTUnit*>(it.valeur());
            if(projet->estTacheRec(ptu->getId())){
                result.push_back(it.valeur());
            }
        }
    }
    return result;
}
