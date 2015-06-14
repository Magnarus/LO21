#ifndef PROGRAMMATIONPROJETEXPORT_H
#define PROGRAMMATIONPROJETEXPORT_H
#include "ProgrammationExport.h"

/**
 * \class       ProgrammationProjetExport ProgrammationProjetExport.h "headers/ProgrammationProjetExport.h"
 * \author      NEVEUX Anais et DELAUNAY Gregory
 * \version     1.0
 * \date        13 juin 2015
 * \brief       Implémente la classe ProgrammationProjetExport
 * \details     Classe concrète permettant de gérer les exportations qui concernent les programmations d'un projet particulier. Il est impossible
 * d'en hériter.
 */

class ProgrammationProjetExport final : public ProgrammationExport{
protected:
    Projet* projet; /** projet sujet de l'exportation*/
    /**
     * \brief getProjet
     * Permet de récupérer le projet à exporter
     * \return un pointeur constant sur le projet sujet de l'exportation
     */
    const Projet* getProjet()const{ return projet;}
    /**
     * \brief findElements
     * Permet de récupérer les programmations concernant des tâches du projet
     * \return un vecteur contenant les programmations à exporter
     */
    QVector<Programmation*> findElements();
    /**
     * \brief generateFilename
     * Permet de générer le nom du fichier en se basant sur les différents critères d'exportation
     * \return le nom du fichier
     */
    const QString generateFilename();
public:
    /**
     * \brief ProgrammationProjetExport
     * Constructeur
     * \param projecttoexport
     * Le projet à exporter
     * \param fn
     * le type d'export
     * \param em
     * La stratégie d'exportation à adopter (facultatif, mais devra être ajoutée lors de l'utilisation)
     */
    ProgrammationProjetExport(Projet* projecttoexport,const QString& fn, MethodExport* em=NULL):ProgrammationExport(fn,em),projet(projecttoexport){}
};

#endif //PROGRAMMATIONPROJETEXPORT_H
