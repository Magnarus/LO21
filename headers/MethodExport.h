#ifndef METHODEXPORT_H
#define METHODEXPORT_H
#include <QString>
#include <QStringBuilder>
#include "headers/projet.h"
#include "headers/tache.h"
#include "headers/activite.h"
#include "headers/programmation.h"
#include "headers/progTUnit.h"
#include "headers/progActivite.h"

/**
 * \class       MethodExport MethodExport.h "headers/MethodExport.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe MethodExport
 * \details     La classe MethodExport est une classe abstraite généralisant les différents formats possibles d'exportation.
 */

class MethodExport{
    QString extension; /** extension du fichier */
public:
    /**
     * \brief MethodExport
     * Constructeur à utiliser dans les classes filles afin d'initaliser le paramètre d'extension.
     * \param ext
     */
    MethodExport(const QString& ext):extension(ext){}
    /**
     * \brief getExtension
     * \return l'extension du format d'exportation
     */
    inline const QString& getExtension()const{ return extension; }
    /**
     * \brief exportProjet
     * Génère la partie concernant l'exportation d'un projet et de ses tâches. Est à redéfinir pour chaque format.
     * \param p
     */
    virtual void exportProjet(const Projet& p)=0;
    /**
     * \brief exportTache
     * Génère la partie concernant l'exportation des tâches et sous-tâches. Est à redéfinir pour chaque format.
     * \param t
     */
    virtual void exportTache(const Tache& t)=0;
    /**
     * \brief exportProgrammation
     * Génère la partie concernant l'exportation d'une programmation. Est à redéfinir pour chaque format.
     * \param prog
     */
    virtual void exportProgrammation(const Programmation& prog)=0;
    /**
     * \brief exportActivite
     * Génère la partie concernant l'exportation d'une activité. Est à redéfinir pour chaque format.
     * \param a
     */
    virtual void exportActivite(const Activite& a)=0;
    /**
     * \brief sendExport
     * Permet de générer le texte du fichier qui sera sauvegardé
     * \return une chaine de caractère correspondant au contenu du fichier
     */
    virtual const QString sendExport()=0;
    virtual ~MethodExport(){}
};

#endif // METHODEXPORT_H
