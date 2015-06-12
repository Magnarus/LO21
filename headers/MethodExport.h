#ifndef METHODEXPORT_H
#define METHODEXPORT_H
#include <QString>
#include "headers/projet.h"
#include "headers/tache.h"
#include "headers/activite.h"
#include "headers/programmation.h"

/**
 * \class       MethodExport MethodExport.h "headers/MethodExport.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe MethodExport
 * \details     La classe MethodExport est une classe abstraite généralisant les différents formats possibles d'exportation.
 */

class MethodExport{
    QString filename;
public:
    MethodExport(const QString& fn):filename(fn){}
    virtual void exportProjet(const Projet& p)=0;
    virtual void exportTache(const Tache& t)=0;
    virtual void exportProgrammation(const Programmation& prog)=0;
    virtual void exportActivite(const Activite& a)=0;
    virtual const QString sendExport()=0;
    virtual ~MethodExport(){}
};

#endif // METHODEXPORT_H
