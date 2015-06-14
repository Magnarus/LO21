#ifndef PROGRAMMATIONEXPORT_H
#define PROGRAMMATIONEXPORT_H
#include "TExport.h"
#include "progmanager.h"
#include "programmation.h"
#include "exportexception.h"
#include "projetmanager.h"

/**
 * \class       ProgrammationExport ProgrammationExport.h "headers/ProgrammationExport.h"
 * \author      NEVEUX Anais et DELAUNAY Gregory
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe ProgrammationExport
 * \details     Classe abstraite permettant de gérer les exportations qui concernent des programmations
 */

class ProgrammationExport : public TExport<Programmation*>{
protected:
        virtual QVector<Programmation*> findElements()=0;
        virtual const QString generateFilename()=0;
public:
    ProgrammationExport(const QString& t,MethodExport* e=NULL):TExport<Programmation*>(t,e){}
    /**
     * \brief exportData
     * Fonction principale d'exportation, ici finale car la fonction reste la même pour toutes les filles, seuls la recherche des programmations
     * et la génération du nom du fichier change.
     * \param e
     * Permet un changement de méthode d'exportation
     */
    virtual void exportData(MethodExport *e=NULL) final;
};

#endif //PROGRAMMATIONEXPORT_H
