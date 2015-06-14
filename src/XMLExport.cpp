#include "headers/XMLExport.h"
#include <QDebug>
void XMLExport::exportProjet(const Projet& p){
    QDomElement projet(document.createElement("projet"));
    QDomElement tmp;
    //Export des éléments relatifs au projet

   ///Noeuds indiquant les taches COMPOSITE et UNITAIRE
    QDomElement unitaire(document.createElement("tache"));
    unitaire.setAttribute("type","unitaire");
    QDomElement composite(document.createElement("tache"));
    composite.setAttribute("type","composite");
    QString unit,comp;

    //Lorsqu'on exporte le projet on va exporter toutes les taches qui le compose
    for(Projet::constIterator it=p.getIterator();it.courant()!=p.end();it.next()){
        if(it.valeur()->getType()==typeTache::UNITAIRE || typeTache::PREEMPTIVE || typeTache::NON_PREEMPTIVE){
            qDebug() << "unitaire";
            unit += QString::number(it.valeur()->getId());
            unit += " ";
        }else{
            qDebug() << "composite" << it.valeur()->getId();
            comp += QString::number(it.valeur()->getId());
            comp += " ";
        }
        exportTache(*it.valeur());
    }
    //Ajout du textnode respectif
    unitaire.appendChild(document.createTextNode(unit));
    composite.appendChild(document.createTextNode(comp));

    tmp=document.createElement("id");
    tmp.appendChild(document.createTextNode(QString::number(p.getId())));
    projet.appendChild(tmp);
    tmp=document.createElement("dispo");
    tmp.appendChild(document.createTextNode(p.getDateDispo().toString()));
    projet.appendChild(tmp);
    tmp=document.createElement("echeance");
    tmp.appendChild(document.createTextNode(p.getDateEcheance().toString()));
    projet.appendChild(tmp);
    tmp=document.createElement("titre");
    tmp.appendChild(document.createTextNode(p.getTitre()));
    projet.appendChild(tmp);
    projet.appendChild(unitaire);
    projet.appendChild(composite);
    projets.appendChild(projet);


}

void XMLExport::exportActivite(const Activite &a){
    QDomElement activite(document.createElement("activite"));
    QDomElement tmp;
    //Ajout des informations sur l'activite
    tmp=document.createElement("id");
    tmp.appendChild(document.createTextNode(QString::number(a.getId())));
    activite.appendChild(tmp);
    tmp=document.createElement("nom");
    tmp.appendChild(document.createTextNode(a.getNom()));
    activite.appendChild(tmp);
    tmp=document.createElement("date");
    tmp.appendChild(document.createTextNode(a.getDate().toString()));
    activite.appendChild(tmp);
    tmp=document.createElement("duree");
    tmp.appendChild(document.createTextNode(a.getDuree().toString()));
    activite.appendChild(tmp);
    //ajout de l'activite dans noeud activites
    activites.appendChild(activite);
}

void XMLExport::exportProgrammation(const Programmation &prog){
    QDomElement programmation(document.createElement("programmation"));
    QDomElement tmp;
    qDebug() << "programmation node créé";
    tmp=document.createElement("id");
    tmp.appendChild(document.createTextNode(QString::number(prog.getId())));
    programmation.appendChild(tmp);
    qDebug() << "id" << prog.getId();
    tmp=document.createElement("date");
    tmp.appendChild(document.createTextNode(prog.getDate().toString()));
    programmation.appendChild(tmp);
    qDebug() << "date" << prog.getDate();
    tmp=document.createElement("horaire");
    tmp.appendChild(document.createTextNode(prog.getHoraire().toString()));
    programmation.appendChild(tmp);
    qDebug() << "horaire" << prog.getHoraire();
    tmp=document.createElement("duree");
    tmp.appendChild(document.createTextNode(prog.getDuree().toString()));
    programmation.appendChild(tmp);
    qDebug() << "duree" << prog.getDuree();
    tmp=document.createElement("type");
    tmp.appendChild(document.createTextNode(QString::number(prog.getType())));
    programmation.appendChild(tmp);
    qDebug() << "type" << prog.getType();
    tmp=document.createElement("element");
    if(prog.getType()==typeProg::PROGTACHE){
        tmp.appendChild(document.createTextNode(QString::number(dynamic_cast<const ProgTUnit*>(&prog)->getProgramme()->getId())));
    }else{
        tmp.appendChild(document.createTextNode(QString::number(dynamic_cast<const ProgActivite*>(&prog)->getProgramme()->getId())));
    }
    programmation.appendChild(tmp);
    programmations.appendChild(programmation);
}

void XMLExport::exportTache(const Tache &t){
    taches.appendChild(exportTacheBis(t));
}

QDomElement XMLExport::exportTacheBis(const Tache &t){
    qDebug() << "exportation de tache";
    QDomElement tache(document.createElement("tache"));
    QDomElement tmp;
    tmp=document.createElement("id");
    tmp.appendChild(document.createTextNode(QString::number(t.getId())));
    tache.appendChild(tmp);
    tmp=document.createElement("titre");
    tmp.appendChild(document.createTextNode(t.getTitre()));
    tache.appendChild(tmp);
    QDomElement precedence(document.createElement("precedence"));
    QString predStr;
    qDebug() << "avant iterateur precedence";
    for(Tache::constIterator it=t.getIterator();it.courant()!=t.end();it.next()){
        predStr += QString::number(it.valeur()->getId()) += " ";
    }
    precedence.appendChild(document.createTextNode(predStr));
    tache.appendChild(precedence);

    tmp=document.createElement("dispo");
    tmp.appendChild(document.createTextNode(t.getDateDispo().toString()));
    tache.appendChild(tmp);
    tmp=document.createElement("echeance");
    tmp.appendChild(document.createTextNode(t.getEcheance().toString()));
    tache.appendChild(tmp);
    //tache.appendChild(document.createElement("etat").appendChild())
    tmp=document.createElement("etat");
    tmp.appendChild(document.createTextNode(QString::number(t.getEtat())));
    tache.appendChild(tmp);
    tmp=document.createElement("type");
    tmp.appendChild(document.createTextNode(t.getTypeToQString()));
    tache.appendChild(tmp);

    //Si la tache est COMPOSITE, on va exporter les sous-taches
    if(t.getType()==typeTache::COMPOSITE){
        exportSousTache(dynamic_cast<const Tache_Composite&>(t),tache);
    }
    return tache;
}

void XMLExport::exportSousTache(const Tache_Composite &t,QDomElement& tc){
    for(Tache_Composite::constIterator it=t.getIterator();it.courant()!=t.end();it.next()){
            tc.appendChild(exportTacheBis(*(it.valeur())));
    }
}
