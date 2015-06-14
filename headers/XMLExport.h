#ifndef XMLEXPORT_H
#define XMLEXPORT_H
#include"MethodExport.h"
#include"qdom.h"

/**
 * \class       XMLExport XMLExport.h "headers/XMLExport.h"
 * \author      NEVEUX Anais et DELAUNAY Gregory
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe XMLExport
 * \extends     MethodExport
 * \details     Stratégie d'exportation au format XML
 */

class XMLExport : public MethodExport{
    QDomDocument document; /** Document XML*/
    QDomElement node,projets,activites,programmations,taches; /** Les différents noeuds composants le fichier XML*/
    /**
     * \brief exportSousTache
     * Fonction d'exportation des sous-tâches d'une tâche composite
     * \param t la tâche composite
     * \param tc le noeud père
     */
    void exportSousTache(const Tache_Composite& t,QDomElement& tc);
public:
    /**
     * \brief XMLExport
     * Constructeur de la classe. Elle initialise les différents paramètres et effectue les liaisons entre les différents noeuds
     * \param fn extension de fichier
     */
    XMLExport(const QString& fn):MethodExport(fn),document(),node(document.createElement("export")),
    projets(document.createElement("projets")),activites(document.createElement("activites")),
      programmations(document.createElement("programmations")),taches(document.createElement("taches")){
        document.appendChild(node);
        node.appendChild(projets);
        node.appendChild(taches);
        node.appendChild(activites);
        node.appendChild(programmations);
    }
    /**
     * \brief exportProjet
     * Implémentation XML de l'exportation d'un projet et de ses tâches
     * \param p le projet à exporter
     */
    void exportProjet(const Projet& p);
    /**
     * \brief exportTache
     * Implémentation XML de l'exportation d'une tâche
     * \param t la tâche à exporter
     */
    void exportTache(const Tache& t);
    /**
     * \brief exportTacheBis
     * Fonction secondaire d'exportation de tâches.
     * \param t la tache à exporter
     * \return un noeud de tâche
     */
    QDomElement exportTacheBis(const Tache& t);
    /**
     * \brief exportProgrammation
     * Implémentation XML de l'exportation d'un programmation
     * \param prog la programmation à exporter
     */
    void exportProgrammation(const Programmation& prog);
    /**
     * \brief exportActivite
     * Implémentation XML de l'exportation d'une activité
     * \param a l'activité à exporter
     */
    void exportActivite(const Activite& a);
    /**
     * \brief sendExport
     * Permet de convertir le document en QString pour l'écriture dans le fichier
     * \return un QString constant
     */
    const QString sendExport(){ return document.toString(); }
};

#endif // XMLEXPORT_H
