#ifndef XMLEXPORT_H
#define XMLEXPORT_H
#include"MethodExport.h"
#include"qdom.h"

/**
 * \class       XMLExport XMLExport.h "headers/XMLExport.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe XMLExport
 * \extends     MethodExport
 * \details     Stratégie d'exportation au format XML
 */

class XMLExport : public MethodExport{
    QDomDocument document;
    QDomElement node,projets,activites,programmations,taches;
public:
    XMLExport(const QString& fn):MethodExport(fn),document(fn),node(document.createElement("export")),
    projets(document.createElement("projets")),activites(document.createElement("activites")),
      programmations(document.createElement("programmations")),taches(document.createElement("taches")){
        document.appendChild(node);
        node.appendChild(projets);
        node.appendChild(taches);
        node.appendChild(activites);
        node.appendChild(programmations);
    }
    void exportProjet(const Projet& p);
    void exportTache(const Tache& t);
    void exportProgrammation(const Programmation& prog);
    void exportActivite(const Activite& a);
    const QString sendExport(){ return document.toString(); }
};

#endif // XMLEXPORT_H
