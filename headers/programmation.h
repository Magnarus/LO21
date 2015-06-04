#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include<QDate>
#include<QTime>
#include "agendaexception.h"
#include <iostream>
/**
 * \class       Programmation programmation.h "headers/programmation.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe programmation
 *
 * \details     Les programmations définissent quand l'utilisateur doit faire une tache ou une activite.
 */
class Programmation{
protected:
    int id;
    QDate date;
    QTime duree;
    Programmation(const Programmation&);
    Programmation& operator=(const Programmation&);
public:
    Programmation(const int id,const QDate& d, const QTime& dur):id(id),date(d),duree(dur){}
    const inline int getId() const {return id;}
    const inline QDate& getDate()const{return date;}
    const inline QTime& getDuree()const{return duree;}
    virtual inline void setDate(QDate& d) = 0;
    virtual inline void setDuree(QTime &d) = 0;
    virtual void afficher() = 0;
};

#endif // PROGRAMMATION_H
