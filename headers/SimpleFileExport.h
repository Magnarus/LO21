#ifndef SIMPLEFILEEXPORT_H
#define SIMPLEFILEEXPORT_H
#include "headers/MethodExport.h"
#include <QStringBuilder>

/**
 * \class       SimpleFileExport SimpleFileExport.h "headers/SimpleFileExport.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe SimpleFileExport
 * \extends     MethodExport
 * \details     Stratégie d'exportation en fichier simple
 */

class SimpleFileExport : public MethodExport{
    //Voir après pour les paramètres
public:
    SimpleFileExport(const QString& fn):MethodExport(fn){}
    void exportProjet(const Projet& p);
    void exportTache(const Tache& t);
    void exportProgrammation(const Programmation& prog);
    void exportActivite(const Activite& a);
    const QString sendExport(){ return "toto";}
};

#endif //SIMPLEFILEEXPORT_H
