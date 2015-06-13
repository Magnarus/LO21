#include "headers/ProgrammationProjetExport.h"

const QString ProgrammationProjetExport::generateFilename(){
    return ProgrammationExport::generateFilename()+"projet_"+projet->getTitre();
}

QVector<Programmation*> ProgrammationProjetExport::findElements(){
    QVector<Programmation*> result;
    qDebug() << "vector créé";
    ProgTUnit* ptu;
    qDebug() << "ptu créé";
    for(ProgManager::Iterator it=ProgManager::getInstance()->getIterator();it.courant()!=ProgManager::getInstance()->end();it.next()){
        if(it.valeur()->getType()==typeProg::PROGTACHE){
            qDebug() << "prog de tache";
            ptu=dynamic_cast<ProgTUnit*>(it.valeur());
            if(projet->estTacheRec(ptu->getId())){
                qDebug() << "c'est une tache du projet";
                result.push_back(it.valeur());
            }
        }
    }
    return result;
}
