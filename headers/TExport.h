#ifndef TEXPORT_H
#define TEXPORT_H
#include "MethodExport.h"
#include <QVector>
/**
 * \class       TExport TExport.h "headers/TExport.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente le template TExport
 * \details     Le template TExport agit comme une interface devant etre implémentée pour tout export, elle permet également
 * de mettre en place la stratégie d'exportation, d'une part car elle généralise ce qu'on veut exporter, mais également car elle
 * stocke le format d'exportation.
 */

template<typename U>
class TExport{
    MethodExport* exportMethod;
    QString type;
protected:
    const MethodExport* getExportMethod(){ return exportMethod;}
    void setExportMethod(MethodExport* me){
        delete exportMethod;
        exportMethod=me;
    }
public:
    TExport(const QString& t,MethodExport* e=NULL):exportMethod(e),type(t){}
    const QString& getExportType()const{ return type;}
    virtual const QString generateFilename()=0;
    virtual void exportData(MethodExport* e=NULL)=0;
    virtual QVector<U> findElements()=0;
    virtual ~TExport()final;
};

template<typename U>
const QString TExport<U>::generateFilename(){
    return "export_";
}

template<typename U>
TExport<U>::~TExport(){ delete exportMethod;}
#endif // TEXPORT_H
