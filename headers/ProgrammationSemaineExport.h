#ifndef PROGRAMMATIONSEMAINEEXPORT_H
#define PROGRAMMATIONSEMAINEEXPORT_H
#include "ProgrammationExport.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
/**
 * \class       ProgrammationSemaineExport ProgrammationSemaineExport.h "headers/ProgrammationSemaineExport.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        13 juin 2015
 * \brief       Implémente la classe ProgrammationSemaineExport
 * \extends     ProgrammationExport
 * \details     Classe concrète permettant de gérer les exportations qui concernent les programmations d'une semaine particulière. Il est impossible
 * d'en hériter.
 */

class ProgrammationSemaineExport final : public ProgrammationExport{
    QDate _debutSemaine;
    QDate _finSemaine;
protected:
    inline const QDate& getDateDebut()const{ return _debutSemaine; }
    inline const QDate& getDateFin()const{ return _finSemaine; }
    const QString generateFilename();
    QVector<Programmation*> findElements();
public:
    ProgrammationSemaineExport(const QString& fn,const QDate& deb,const QDate& fin,MethodExport* em=NULL):ProgrammationExport(fn,em),_debutSemaine(deb),_finSemaine(fin){
        if(_finSemaine<_debutSemaine) throw ExportException("La date de fin doit etre après celle de debut...");
    }
};

#endif // PROGRAMMATIONSEMAINEEXPORT_H
