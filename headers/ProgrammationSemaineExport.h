#ifndef PROGRAMMATIONSEMAINEEXPORT_H
#define PROGRAMMATIONSEMAINEEXPORT_H
#include "ProgrammationExport.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
/**
 * \class       ProgrammationSemaineExport ProgrammationSemaineExport.h "headers/ProgrammationSemaineExport.h"
 * \author      NEVEUX Anais et DELAUNAY Gregory
 * \version     1.0
 * \date        13 juin 2015
 * \brief       Implémente la classe ProgrammationSemaineExport
 * \details     Classe concrète permettant de gérer les exportations qui concernent les programmations d'une semaine particulière. Il est impossible
 * d'en hériter.
 */

class ProgrammationSemaineExport final : public ProgrammationExport{
    QDate _debutSemaine; /** Date de début de la semaine à exporter*/
    QDate _finSemaine; /** Date de fin de la semaine à exporter */
protected:
    /**
     * \brief getDateDebut
     * Permet de récupérer la date de début de la semaine à exporter
     * \return une référence constante sur la date de début
     */
    inline const QDate& getDateDebut()const{ return _debutSemaine; }
    /**
     * \brief getDateFin
     * Permet de récupérer la date de fin de la semaine à exporter
     * \return une référence constante sur la date de fin
     */
    inline const QDate& getDateFin()const{ return _finSemaine; }
    /**
     * \brief generateFilename
     * Permet de générer le nom complet du fichier
     * \return une chaine de caractère constante contenant le nom du fichier (sans l'extension)
     */
    const QString generateFilename();
    /**
     * \brief findElements
     * Permet de récupérer toutes les programmations d'une semaine particulière
     * \return Un vecteur de pointeur de programmations
     */
    QVector<Programmation*> findElements();
public:
    /**
     * \brief ProgrammationSemaineExport
     * Constructeur de la classe, déclenche une exception de type ExportException si la date de début est postérieure à la date de fin
     * \param le type d'export
     * \param deb date de début de semaine
     * \param fin date de fin de semaine
     * \param em stratégie d'exportation
     */
    ProgrammationSemaineExport(const QString& fn,const QDate& deb,const QDate& fin,MethodExport* em=NULL):ProgrammationExport(fn,em),_debutSemaine(deb),_finSemaine(fin){
        if(_finSemaine<_debutSemaine) throw ExportException("La date de fin doit etre après celle de debut...");
    }
};

#endif // PROGRAMMATIONSEMAINEEXPORT_H
