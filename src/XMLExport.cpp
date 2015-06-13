#include "headers/XMLExport.h"
void XMLExport::exportProjet(const Projet& p){

    QDomElement projet(document.createElement("projet"));
    //Export des éléments relatifs au projet

    //Noeuds indiquant les taches COMPOSITE et UNITAIRE
    QDomElement unitaire(document.createElement("tache"));
    unitaire.setAttribute("type","unitaire");
    QDomElement composite(document.createElement("tache"));
    composite.setAttribute("type","composite");
    QString unit,comp;

    //Lorsqu'on exporte le projet on va exporter toutes les taches qui le compose
    for(Projet::constIterator it=p.getIterator();it.courant()!=p.end();it.next()){
        if(it.valeur()->getType()==typeTache::UNITAIRE){
            unit % QString::number(it.valeur()->getId());
        }else{
            comp % QString::number(it.valeur()->getId());
        }
        exportTache(*it.valeur());
    }
    //Ajout du textnode respectif
    unitaire.appendChild(document.createTextNode(unit));
    composite.appendChild(document.createTextNode(comp));
    projet.appendChild(document.createElement("id").appendChild(document.createTextNode(QString::number(p.getId()))));
    projet.appendChild(document.createElement("dispo").appendChild(document.createTextNode(p.getDateDispo().toString())));
    projet.appendChild(document.createElement("echeance").appendChild(document.createTextNode(p.getDateEcheance().toString())));
    projet.appendChild(document.createElement("titre").appendChild(document.createTextNode(p.getTitre())));
    projet.appendChild(unitaire);
    projet.appendChild(composite);

    projets.appendChild(projet);

}

void XMLExport::exportActivite(const Activite &a){
    QDomElement activite(document.createElement("activite"));
    //Ajout des informations sur l'activite
    activite.appendChild(document.createElement("id").appendChild(document.createTextNode(QString::number(a.getId()))));
    activite.appendChild(document.createElement("nom").appendChild(document.createTextNode(a.getNom())));
    activite.appendChild(document.createElement("date").appendChild(document.createTextNode(a.getDate().toString())));
    activite.appendChild(document.createElement("duree").appendChild(document.createTextNode(a.getDuree().toString())));
    //ajout de l'activite dans noeud activites
    activites.appendChild(activite);
}

void XMLExport::exportProgrammation(const Programmation &prog){
    QDomElement programmation(document.createElement("programmation"));
    programmation.appendChild(document.createElement("id").appendChild(document.createTextNode(QString::number(prog.getId()))));
    programmation.appendChild(document.createElement("date").appendChild(document.createTextNode(prog.getDate().toString())));
    programmation.appendChild(document.createElement("horaire").appendChild(document.createTextNode(prog.getHoraire().toString())));
    programmation.appendChild(document.createElement("duree").appendChild(document.createTextNode(prog.getDuree().toString())));
    programmation.appendChild(document.createElement("type").appendChild(document.createTextNode(QString::number(prog.getType()))));
    programmations.appendChild(programmation);
}

void XMLExport::exportTache(const Tache &t){
    taches.appendChild(exportTacheBis(t));
}

QDomElement XMLExport::exportTacheBis(const Tache &t){
    QDomElement tache(document.createElement("tache"));
    tache.appendChild(document.createElement("id").appendChild(document.createTextNode(QString::number(t.getId()))));
    tache.appendChild(document.createElement("titre").appendChild(document.createTextNode(t.getTitre())));
    QDomElement precedence(document.createElement("precedence"));
    QString predStr;
    for(Tache::constIterator it=t.getIterator();it.courant()!=t.end();it.next()){
        predStr % QString::number(it.valeur()->getId()) % " ";
    }
    precedence.appendChild(document.createTextNode(predStr));
    tache.appendChild(precedence);

    tache.appendChild(document.createElement("dispo").appendChild(document.createTextNode(t.getDateDispo().toString())));
    tache.appendChild(document.createElement("echeance").appendChild(document.createTextNode(t.getEcheance().toString())));
    //tache.appendChild(document.createElement("etat").appendChild())
    tache.appendChild(document.createElement("etat").appendChild(document.createTextNode(QString::number(t.getEtat()))));
    tache.appendChild(document.createElement("type").appendChild(document.createTextNode(t.getTypeToQString())));

    //Si la tache est COMPOSITE, on va exporter les sous-taches
    if(t.getType()==typeTache::COMPOSITE){
        exportSousTache(dynamic_cast<const Tache_Composite&>(t),tache);
    }
}

void XMLExport::exportSousTache(const Tache_Composite &t,QDomElement& tc){
    for(Tache_Composite::constIterator it=t.getIterator();it.courant()!=t.end();it.next()){
        if(it.valeur()->getType()==typeTache::COMPOSITE){
            tc.appendChild(exportTacheBis(*(it.valeur())));
        }
    }
}
