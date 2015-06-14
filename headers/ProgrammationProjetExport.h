#ifndef PROGRAMMATIONPROJETEXPORT_H
#define PROGRAMMATIONPROJETEXPORT_H
#include "ProgrammationExport.h"

/**
 * \class       ProgrammationProjetExport ProgrammationProjetExport.h "headers/ProgrammationProjetExport.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        13 juin 2015
 * \brief       Implémente la classe ProgrammationProjetExport
 * \details     Classe concrète permettant de gérer les exportations qui concernent les programmations d'un projet particulier. Il est impossible
 * d'en hériter.
 */

class ProgrammationProjetExport final : public ProgrammationExport{
protected:
    Projet* projet;
    const Projet* getProjet()const{ return projet;}
    QVector<Programmation*> findElements();
    const QString generateFilename();
public:
    ProgrammationProjetExport(Projet* projecttoexport,const QString& fn, MethodExport* em=NULL):ProgrammationExport(fn,em),projet(projecttoexport){}
};

#endif //PROGRAMMATIONPROJETEXPORT_H
