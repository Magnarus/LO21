#include "headers/ProgrammationExport.h"

const QString ProgrammationExport::generateFilename(){
    return TExport<Programmation*>::generateFilename() + "programmation_";
}

void ProgrammationExport::exportData(MethodExport *e){
    if(e==NULL && getExportMethod()==NULL) throw ExportException("Aucune stratégie d'exportation indiquée. Exportation impossible.");
    if(getExportMethod()==NULL) setExportMethod(e);

    TManager<Projet*>::Iterator itProjet=ProjetManager::getInstance()->getIterator();
    bool found=false; //boolean servant de flag
    //Recuperation des programmations concernées
    QVector<Programmation*> programmations=findElements();

    //Stockage temporaire des projets déjà enregistrés
    QVector<Projet*> projets_saved;

    //Creation du fichier
    const QString namefile=this->generateFilename()+"."+this->getExtension();
    std::ofstream file(namefile.toStdString().c_str(),std::ios::out | std::ios::trunc);
    ProgActivite* pa;
    ProgTUnit* ptu;
    if(file){
        //Pour chaque programmation on va effectuer la conversion
        for(QVector<Programmation*>::iterator it=programmations.begin();it!=programmations.end();++it){
            //Sauvegarde de la programmation
            getExportMethod()->exportProgrammation(**it);
            //Recuperation de l'objet de la programmation
            if((*it)->getType()==typeProg::PROGACTIVITE){ //Si c'est une simple activité
                qDebug() << "programmation d'activite";
                pa=dynamic_cast<ProgActivite*>(*it);
                getExportMethod()->exportActivite(*pa->getProgramme());
            }else{
                //On souhaite exporter une tache UNITAIRE
                ptu=dynamic_cast<ProgTUnit*>(*it);
                //Recuperation du projet de la tache
                itProjet=ProjetManager::getInstance()->getIterator();
                found=false;
                while(itProjet.courant()!=ProjetManager::getInstance()->end() && !found){
                    found=itProjet.valeur()->estTacheRec(ptu->getProgramme()->getId());
                    if(!found) itProjet.next();
                }

                //Si le projet n'a pas déjà été exporté, alors on l'exporte et on ajoute le projet à la liste des projets déjà sauvegardés
                if(std::find(projets_saved.begin(),projets_saved.end(),itProjet.valeur())==projets_saved.end()){
                    getExportMethod()->exportProjet(*itProjet.valeur());
                    projets_saved.push_back(itProjet.valeur());
                }

            }
        }
        //Ecriture du fichier
        file << getExportMethod()->sendExport().toStdString();
        //Fermeture du fichier
        file.close();
    }else{
        //Gestion d'un soucis d'exportation
        throw ExportException("Problème de création du fichier");
    }
}
