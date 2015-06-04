#ifndef AGENDAEXCEPTION_H
#define AGENDAEXCEPTION_H
/**
 * \class       AgendaException agendaexception.h "headers/agendaexception.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe de gestion des exceptions
 *
 * \details    Cette classe gère les exceptions
 */
class AgendaException{
public:
    AgendaException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};
#endif // AGENDAEXCEPTION_H
