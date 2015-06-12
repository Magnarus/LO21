#ifndef PROGRAMMATIONEXPORT_H
#define PROGRAMMATIONEXPORT_H
#include "TExport.h"
#include "progmanager.h"
#include "programmation.h"
#include "exportexception.h"

/**
 * \class       ProgrammationExport ProgrammationExport.h "headers/ProgrammationExport.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe ProgrammationExport
 * \extends     TExport<Programmation*>
 * \details     Classe abstraite permettant de gérer les exportations qui concernent des programmations
 */

class ProgrammationExport : public TExport<Programmation*>{
public:
    ProgrammationExport(const QString& t,MethodExport* e=NULL):TExport<Programmation*>(t,e){}

    virtual const QString generateFilename()=0;
    //L'exportation des données reste la même quelque soit le genre de programmation qu'on exporte
    //Une fois définie, cette méthode ne changera pas et ne devrait pas être réimplémentée par héritage, d'ou le final
    virtual void exportData(MethodExport *e=NULL) final;
    virtual QVector<Programmation*> findElements()=0;
};

#endif //PROGRAMMATIONEXPORT_H