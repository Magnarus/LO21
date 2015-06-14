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
#include<QString>
class AgendaException{
public:
    /**
     * \brief AgendaException constructeur
     * \param message
     */
    AgendaException(const QString& message):info(message){}

    /**
     * \brief getInfo
     * \return \e QString le message à afficher
     */
    QString getInfo() const { return info; }
private:
    QString info; /** le message à afficher */
};
#endif // AGENDAEXCEPTION_H
