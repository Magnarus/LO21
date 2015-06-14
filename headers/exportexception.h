#ifndef EXPORTEXCEPTION_H
#define EXPORTEXCEPTION_H
/**
 * \class       ExportException exportexception.h "headers/exportexception.h"
 * \author      NEVEUX Anais et DELAUNAY Gregory
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe de gestion des exceptions d'exportation
 *
 * \details    Cette classe gère les exceptions liées aux exportations
 */
#include<QString>
class ExportException{
public:
    /**
     * \brief ExportException
     * Le constructeur de l'exception
     * \param message à afficher
     */
    ExportException(const QString& message):info(message){}
    /**
     * \brief getInfo
     * \return le message de l'exception
     */
    QString getInfo() const { return info; }
private:
    QString info; /** Message de l'exception */
};
#endif // EXPORTEXCEPTION_H
