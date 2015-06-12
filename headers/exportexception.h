#ifndef EXPORTEXCEPTION_H
#define EXPORTEXCEPTION_H
/**
 * \class       ExportException exportexception.h "headers/exportexception.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        12 juin 2015
 * \brief       Implémente la classe de gestion des exceptions d'exportation
 *
 * \details    Cette classe gère les exceptions liées aux exportations
 */
#include<QString>
class ExportException{
public:
    ExportException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};
#endif // EXPORTEXCEPTION_H
