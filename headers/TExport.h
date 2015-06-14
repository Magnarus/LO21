#ifndef TEXPORT_H
#define TEXPORT_H
#include "MethodExport.h"
#include <QVector>
#include <fstream>
#include <iostream>
/**
 * \class       TExport TExport.h "headers/TExport.h"
 * \author      NEVEUX Anais et DELAUNAY Gregory
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente le template TExport
 * \details     Le template TExport agit comme une interface devant etre implémentée pour tout export, elle permet également
 * de mettre en place la stratégie d'exportation, d'une part car elle généralise ce qu'on veut exporter, mais également car elle
 * stocke le format d'exportation.
 */

template<typename U>
class TExport{
    MethodExport* exportMethod; /** Stratégie de format d'exportation*/
    QString type; /** type d'exportation*/
protected:
    /**
     * \brief getExportMethod
     * Permet de récupérer la stratégie de format d'exportation
     * \return un pointeur sur la stratégie
     */
    const MethodExport* getExportMethod()const{ return exportMethod;}
    /**
     * \brief setExportMethod
     * Permet de changer la stratégie du format d'exportation
     * \param me
     * La nouvelle stratégie de format
     */
    void setExportMethod(MethodExport* me){
        delete exportMethod;
        exportMethod=me;
    }
    /**
     * \brief getExtension
     * Retourne l'extension du fichier exporté. La méthode de format doit être définie!
     * \return une chaine de caractere correspondant à l'extension du fichier exporté
     */
    inline const QString getExtension()const{ return exportMethod->getExtension();}
    /**
     * \brief getExportMethod
     * Version non const de la récupération de stratégie de format d'exportation
     * \return un pointeur sur la stratégie
     */
    inline MethodExport* getExportMethod(){ return exportMethod;}
    /**
     * \brief findElements
     * Fonction template de récupération des T à exporter
     * \return un QVector des T à exporter
     */
    virtual QVector<U> findElements()=0;
    /**
     * \brief generateFilename
     * Permet de générer le nom du fichier
     * \return une chaine de caractere constante contenant le nom du fichier
     */
    virtual const QString generateFilename()=0;
    /**
     * \brief getExportType
     * Permet de récupérer le type d'exportation.
     * \return le type d'exportation
     */
    const QString& getExportType()const{ return type;}
public:
    TExport(const QString& t,MethodExport* e=NULL):exportMethod(e),type(t){}
    /**
     * \brief exportData
     * Fonction principale contenant le principe général de l'exportation
     * \param e format d'exportation
     */
    virtual void exportData(MethodExport* e=NULL)=0;
    virtual ~TExport();
};

template<typename U>
const QString TExport<U>::generateFilename(){
    return "export_";
}

template<typename U>
TExport<U>::~TExport(){ delete exportMethod;}
#endif // TEXPORT_H
